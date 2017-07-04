#include <unistd.h>
#include <string.h>
#include <algorithm>
#include "databuffer.h"
#include "log.h"

namespace lbs
{
DataBuffer::DataBuffer(int fd) 
    : fd_(fd)
{

}

DataBuffer::~DataBuffer()
{

}

char* DataBuffer::begin()
{
	return buffer_ + start_;
}

char* DataBuffer::end()
{
    return buffer_ + end_;
}

size_t DataBuffer::getLen() const
{
	return end_ - start_;
}

int DataBuffer::moveStart(size_t n)
{
    if (start_ + n > end_)
    {
        return -1;
    }
    start_ += n;
    return 1;
}

size_t DataBuffer::leftSpace() const
{
    return MAX_BUFFER_SIZE - end_;
}

int DataBuffer::copy2Left(size_t n)
{
    if (n > start_)
        return -1;

    if (n == 0)
        return 1;

    if (getLen() == 0)
    {
        start_ = 0;
        end_   = 0;
        return 1;
    }
    ::memmove(buffer_, buffer_ + n, getLen());
    end_ -= n;
    start_ -= n;
    return 1;
}

int DataBuffer::tryReadNBytes(size_t n, char* data)
{
    int left = readNFromFd(n);
    if (left < 0)
    {
        return -2;
    }

    if (n > getLen())
    {
	return -1;
    }
    ::memcpy(data, begin(), n);
    return 1;
}

int DataBuffer::readNBytes(size_t n, char* data)
{
    if (0 == n)
    {
        return 1;
    }
    if (tryReadNBytes(n, data) < 0) 
    {
        return -1;
    }
    return moveStart(n);
}

int DataBuffer::append(char* data, size_t len)
{
    if (len == 0)
        return 1;
    if (end_ + len > MAX_BUFFER_SIZE)
    {
        LOG(ERROR) << "start:" << start_ << " end:" << end_ << " len:" << len;
    	return -1;
    }
    ::memcpy(end(), data, len);
    end_ += len;
    return 1;
}

int DataBuffer::readNFromFd(size_t count)
{
    /* 接受数据 */
    /* 循环读取fd上的数据，直到遇到EAGAIN错误*/
    if (leftSpace() < count)
    {
        LOG(ERROR) << "no left space, start" << start_ <<", end "<< end_;
        return -1;
    }

    size_t n = 0;
    int    nread = 0;
    while (count > 0)
    { 
        nread = ::read(fd_, end() + n, count);
        if (nread < 0)
        {
            if (errno == EINTR)
                continue;
            if (errno == EAGAIN || errno == EWOULDBLOCK)
                break;
            LOG(ERROR) << "read error";
            return -1;
        } 

        if (0 == nread) 
        {
            DLOG(INFO) << "peer close";
            return -1;
        }
        n += nread;
        count -= nread;
    }

    end_ += n;
    /* 接受数据over 指定长度数据收完或者缓冲区为空了*/
    return count;
}

int DataBuffer::readFromFd()
{
	char data[MAX_BUFFER_SIZE];
	//::memset(data, 0, MAX_BUFFER_SIZE); 
    ssize_t  nread = 0;
    ssize_t  n     = 0;
    while(true)
    { 
        if (n >= MAX_BUFFER_SIZE)
        {
            LOG(ERROR) << "read in data too large";
            return -1;
        }
        nread = ::read(fd_, data + n, MAX_BUFFER_SIZE - n);
        if (nread > 0)
            n += nread;
        
        if (nread < 0)
        {
            if (errno == EINTR)  //信号中断
                continue;

            if (errno == EAGAIN || errno == EWOULDBLOCK) //缓冲区已空
                break;

            LOG(ERROR) << "read failed"; //其他错误 关闭连接
            return -1;
        }

        if (0 == nread) 
        {
            LOG(ERROR) << "peer close";  //对端关闭连接，关闭连接
            return -1;
        }
    }
    //内核缓冲区的数据全部都读到用户缓冲区了
    if(append(data, n) < 0)
    {
    	LOG(ERROR) << "user buffer is full";
    	return -1;
    }
    return 1;
}

int DataBuffer::writeToFd()
{
    /* 发送消息 */
    ssize_t n = getLen();
    if (n == 0)
    {
    	//没有要发的东西
        DLOG(INFO) << "nothing need to send";
    	return 1;
    }
    ssize_t nwrite = 0;
    ssize_t count  = 0;
    while (true)
    {
        nwrite = ::write(fd_, begin() + count, n);
        if (nwrite > 0)
        {
            n -= nwrite;
            count += nwrite;
        }

        if (nwrite < 0)
        {
            if (errno == EINTR)
                continue;
            if (errno == EAGAIN || errno == EWOULDBLOCK)
                break;
            LOG(ERROR) << "write failed";
            return -1;
        }
    }
    
    /* 发送数据over 指定长度数据发完或者缓冲区满了*/
    //更新
    return copy2Left(count);
}
}

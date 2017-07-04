#include <memory>
#include <mutex>
#include <unistd.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <strings.h>
#include <arpa/inet.h>

#include "until.h"

/*
* common function
*/
/*************************方法*********************************/

int writen(int fd, void *buff, size_t count)
{
    /* 发送消息 */
    size_t n = count;
    int nwrite = 0;
    while (n > 0 
          && (nwrite = ::write(fd, (char*)buff + count - n, n)) > 0)
    {
       n -= nwrite;
    }
    
    if (nwrite == -1 && errno != EAGAIN)
    {
       printf("write failed\n");
       return -1;
    }
    
    /* 发送数据over 指定长度数据发完或者缓冲区为满了*/
    return n;
}

int readn(int fd, void *buff, size_t count)
{
    /* 接受数据 */
    /* 循环读取fd上的数据，直到遇到EAGAIN错误*/
    size_t n = 0;
    int    nread = 0;
    while (count > 0 
          && (nread = ::read(fd, (char*)buff + n, count)) > 0) 
    {
        n += nread;
        count -= nread;
    }
    
    if (0 == nread) 
    {
        printf("peer close\n");
        return -1;
    }

    if (-1 == nread && errno != EAGAIN) 
    {
        printf("read failed\n");
        return -1;
    }
    /* 接受数据over 指定长度数据收完或者缓冲区为空了*/
    return count;
}
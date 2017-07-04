#ifndef _DATA_BUFFER_H_
#define _DATA_BUFFER_H_

#include <vector>
#define MAX_BUFFER_SIZE 10 * 1024
namespace lbs
{
class DataBuffer
{
public:
    DataBuffer(int fd);
    ~DataBuffer(); 
    char* begin();
    char* end();
    size_t getLen() const; 
    size_t leftSpace() const;
    int moveStart(size_t n);
    int copy2Left(size_t n);
    int append(char* data, size_t len);
    int readFromFd();
    int writeToFd();
    int tryReadNBytes(size_t n, char* data);
    int readNBytes(size_t n, char* data);
    int readNFromFd(size_t count);
public:
    char   buffer_[MAX_BUFFER_SIZE];
    size_t start_ = 0;
    size_t end_ = 0;
    int    fd_;
};
}
#endif

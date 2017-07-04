#ifndef _TYPE_H_
#define _TYPE_H_
#include <sys/epoll.h>

/* 
* 位置 
*/
struct Position
{
   double x;
   double y;
   int    id;
   Position(double x_r, double y_r) :x(x_r), y(y_r) {}
};

enum 
{
    EVENT_IN   = EPOLLIN,
    EVENT_OUT  = EPOLLOUT,
    EVENT_ERR  = EPOLLERR,
    EVENT_HUP  = EPOLLHUP,
    EVENT_ET   = EPOLLET,
    EVENT_ONESHOT = EPOLLONESHOT
};
#endif
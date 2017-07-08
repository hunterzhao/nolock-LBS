#ifndef _GEO_INTERFACE_H_
#define _GEO_INTERFACE_H_
#include <vector>
#include <mutex>
#include "geo_service.h"
#include "type.h"
/*
*  geo算法库服务接口
*/

namespace geo
{
class GeoInterface
{
public:
    GeoInterface();

    /* 插入一堆新的位置 thread safe*/
    int insertPos(const Position& c);

    /* 插入一个新的位置 thread safe*/
    int insertPos(const std::vector<Position>& pos);

    /* delete */
    int deletePos(std::string pos);
    /* 返回半径为radius内的坐标点 thread safe */
    int searchPos(const Position& c, const double radius, 
	                 std::vector<Position>& ans) const;

private:
   GeoService* geo_service_;
   static std::mutex mtx_;
};
}

#endif

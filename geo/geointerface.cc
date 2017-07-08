#include "assert.h"
#include "geointerface.h"
#include "geohash.h"
#include "log.h"

namespace geo
{
std::mutex GeoInterface::mtx_; 

GeoInterface::GeoInterface() : geo_service_(new GeoService())
{
}

int GeoInterface::insertPos(const Position& c)
{
    Geohash hash(c.x, c.y, 40);
    std::string hash_code = hash.convertToBase32(hash.getGeo(), 40, 40); 
    geo_service_->insert(hash_code, c);
    DLOG(INFO) << "insert one pos" << hash_code;
    return 1;
}

int GeoInterface::deletePos(std::string pos)
{
    return 1; 
}

int GeoInterface::insertPos(const std::vector<Position>& pos)
{
    std::lock_guard<std::mutex> lck(mtx_);
    for (auto c : pos) 
    {
        insertPos(c);
    }
    return 1;
}

int GeoInterface::searchPos(const Position& c, const double radius, 
              std::vector<Position>& ans) const
{
    Geohash hash(c.x, c.y, 40);
    std::string hash_code = hash.convertToBase32(hash.getGeo(), 40, 40);
    ans = geo_service_->search(hash_code, 2.5);    
    return 1;
}
}

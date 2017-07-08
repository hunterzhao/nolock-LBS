#ifndef _GEOHASH_H_
#define _GEOHASH_H_

#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

namespace geo
{
class Geohash
{
public:
   long getJ() { return j_;}
   long getW() { return w_;}
   long getGeo() { return geo_;}
   int  getJLen() { return j_len_;}
   int  getWLen() { return w_len_;}
   int  getGeoLen() { return j_len_ + w_len_;}

private:
   long j_ = 0l;
   long w_ = 0l;
   long geo_ = 0l;
   int  j_len_= 0;
   int  w_len_= 0;
   int  geo_len_= 0;

public:
   /*
   * x jingdu 
   * y weidu
   * len geohash code len
   */
   Geohash(double x, double y, int len);
   //
   static long combineToGeo(long j, int j_len, long w, int w_len);
  
   //
   static std::string convertToBase32(long geo, int origin_len, int geo_len);
  
   static long split(long geo, int len, int origin_len, bool j = true);
  
};

}
#endif

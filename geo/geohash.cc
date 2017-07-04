#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
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
   Geohash(double x, double y, int len)
   {
      ssize_t n = len / 2 - 1, m = len - 1;
      double j_s = -180, j_e = 180;
      double w_s = -90, w_e = 90;
      while (n >= 0)
      {
         double j_mid = (j_s + j_e) / 2;
         double w_mid = (w_s + w_e) / 2;
         j_ <<= 1;
         w_ <<= 1;
         if (x > j_mid)
         {    
              j_ |= 1 ; 
              j_s = j_mid;
         }
         else 
         {    
              j_ |= 0; 
              j_e = j_mid;
         }
         m--;
         if (y > w_mid)
         {    
              w_ |= 1; 
              w_s = w_mid;
         }
         else 
         {    
              w_ |= 0; 
              w_e = w_mid;
         }
         n--; m--;
      }
      j_len_ = w_len_ =  len / 2;
      geo_len_ = len;
      geo_ = combineToGeo(j_, j_len_, w_, w_len_);
   }
   
   //
   static long combineToGeo(long j, int j_len, long w, int w_len)
   {
      long geo = 0;
      int  geo_len = j_len + w_len;
      j_len--; w_len--;
      for (int i = 0; i < geo_len; i++)
      {
          geo <<= 1;
          if ((i & 1) == 0)
          {
             geo |= ((j >> j_len) & 1); j_len--;
          }
          else
          {
             geo |= ((w >> w_len) & 1); w_len--;
          }
      }
      return geo;
   }
   
   //
   static std::string convertToBase32(long geo, int origin_len, int geo_len)
   {
      std::string base = "0123456789bcdefghjkmnpqrstuvwxyz";
      geo >>= (origin_len - geo_len);
      int n = geo_len / 5;
      std::string ans(n, '0');
 
      for (int i = 0; i < n; i++)
      {
         long number = geo >> (geo_len - 5 * (i+1)) & 31;
         std::bitset<5> num_bitset(number);
         ans[i] = base[num_bitset.to_ulong()];
      }
      return ans;
   }
   
   
   static long split(long geo, int len, int origin_len, bool j = true)
   {
      long ans = 0;
      int  index = 0;
      geo >>= (origin_len - len);
      len--;
      len = j ? len : len - 1;
      for (int i = len; i >= 0; i = i-2)
      {
         ans <<= 1;
         ans |= ((geo >> i) & 1);
      }
      return ans;
   }
   
};

std::string findENeighbor(long geo, int origin_len, int len)
{
   int  len_l = (len & 1) ? len / 2 + 1 : len / 2;
   int  len_w = len / 2 ;
   long l = Geohash::split(geo, len, origin_len, true);
   long w = Geohash::split(geo, len, origin_len,false);
   l += 1;
   long geo_new = Geohash::combineToGeo(l, len_l, w, len_w);
   int  geo_new_len = len_l + len_w; 
   return Geohash::convertToBase32(geo_new, geo_new_len, geo_new_len);
}

std::string findWNeighbor(long geo, int origin_len, int len)
{
   int  len_l = (len & 1) ? len / 2 + 1 : len / 2;
   int  len_w = len / 2 ;
   long l = Geohash::split(geo, len, origin_len, true);
   long w = Geohash::split(geo, len, origin_len,false);
   l -= 1;
   long geo_new = Geohash::combineToGeo(l, len_l, w, len_w);
   int  geo_new_len = len_l + len_w;
   return Geohash::convertToBase32(geo_new, geo_new_len, geo_new_len);
}

std::string findNNeighbor(long geo, int origin_len, int len)
{
   int  len_l = (len & 1) ? len / 2 + 1 : len / 2;
   int  len_w = len / 2 ; 
   long l = Geohash::split(geo, len, origin_len, true);
   long w = Geohash::split(geo, len, origin_len,false);
   w += 1;
   long geo_new = Geohash::combineToGeo(l, len_l, w, len_w);
   int  geo_new_len = len_l + len_w;
   return Geohash::convertToBase32(geo_new, geo_new_len, geo_new_len);
}

std::string findSNeighbor(long geo, int origin_len, int len)
{
   int  len_l = (len & 1) ? len / 2 + 1 : len / 2;
   int  len_w = len / 2 ; 
   long l = Geohash::split(geo, len, origin_len, true);
   long w = Geohash::split(geo, len, origin_len,false);
   w -= 1;
   long geo_new = Geohash::combineToGeo(l, len_l, w, len_w);
   int  geo_new_len = len_l + len_w;
   return Geohash::convertToBase32(geo_new, geo_new_len, geo_new_len);
}

std::string findNENeighbor(long geo, int origin_len, int len)
{
   int  len_l = (len & 1) ? len / 2 + 1 : len / 2;
   int  len_w = len / 2 ; 
   long l = Geohash::split(geo, len, origin_len, true);
   long w = Geohash::split(geo, len, origin_len,false);
   l += 1;
   w += 1;
   long geo_new = Geohash::combineToGeo(l, len_l, w, len_w);
   int  geo_new_len = len_l + len_w;
   return Geohash::convertToBase32(geo_new, geo_new_len, geo_new_len);
}

std::string findNWNeighbor(long geo, int origin_len, int len)
{
   int  len_l = (len & 1) ? len / 2 + 1 : len / 2;
   int  len_w = len / 2 ; 
   long l = Geohash::split(geo, len, origin_len, true);
   long w = Geohash::split(geo, len, origin_len,false);
   w += 1;
   l -= 1;
   long geo_new = Geohash::combineToGeo(l, len_l, w, len_w);
   int  geo_new_len = len_l + len_w;
   return Geohash::convertToBase32(geo_new, geo_new_len, geo_new_len);
}

std::string findSENeighbor(long geo, int origin_len, int len)
{
   int  len_l = (len & 1) ? len / 2 + 1 : len / 2;
   int  len_w = len / 2 ; 
   long l = Geohash::split(geo, len, origin_len, true);
   long w = Geohash::split(geo, len, origin_len,false);
   w -= 1;
   l += 1;
   long geo_new = Geohash::combineToGeo(l, len_l, w, len_w);
   int  geo_new_len = len_l + len_w;
   return Geohash::convertToBase32(geo_new, geo_new_len, geo_new_len);
}

std::string findSWNeighbor(long geo, int origin_len, int len)
{
   int  len_l = (len & 1) ? len / 2 + 1 : len / 2;
   int  len_w = len / 2 ; 
   long l = Geohash::split(geo, len, origin_len, true);
   long w = Geohash::split(geo, len, origin_len,false);
   l -= 1;
   w -= 1;
   long geo_new = Geohash::combineToGeo(l, len_l, w, len_w);
   int  geo_new_len = len_l + len_w;
   return Geohash::convertToBase32(geo_new, geo_new_len, geo_new_len);
}

int main()
{
   const int n = 40;
   Geohash geo(116.3906, 39.92324, n);
   std:: cout << Geohash::convertToBase32(geo.getGeo(), geo.getGeoLen(), geo.getGeoLen()) << std::endl;
   
   std::cout << findNWNeighbor(geo.getGeo(), 40, 25) << " ";
   std::cout << findNNeighbor(geo.getGeo(), 40, 25)  << " ";
   std::cout << findNENeighbor(geo.getGeo(), 40, 25) << std::endl;

   
   std::cout << findWNeighbor(geo.getGeo(), 40, 25) << " ";
   std::cout << Geohash::convertToBase32(geo.getGeo(), 40, 25) << " ";   
   std::cout << findENeighbor(geo.getGeo(), 40, 25) << std::endl;
   
   
   std::cout << findSWNeighbor(geo.getGeo(), 40, 25) << " ";
   std::cout << findSNeighbor(geo.getGeo(), 40, 25)  << " ";
   std::cout << findSENeighbor(geo.getGeo(), 40, 25) << std::endl;
   //long m = 10;
   //std::cout << Geohash::combineToGeo(3, 2, 0, 2) <<std::endl;
   //std::cout << Geohash::split(m, 2, true) <<std::endl;
   //std::cout << Geohash::split(m, 2, false) <<std::endl;
   
}



#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

template<size_t N>
class Geohash
{
public:
   std::bitset<N / 2> j_set_;
   std::bitset<N / 2> w_set_;
   std::bitset<  N  > geo_set_;
   int j_len_;
   int w_len_;
   int geo_len_;

public:
   Geohash(double x, double y)
   {
      ssize_t n = N / 2 - 1, m = N - 1;
      double j_s = -180, j_e = 180;
      double w_s = -90, w_e = 90;
      while (n >= 0)
      {
         double j_mid = (j_s + j_e) / 2;
         double w_mid = (w_s + w_e) / 2;
         if (x > j_mid)
         {    
              j_set_[n] = 1; geo_set_[m] = 1;
              j_s = j_mid;
         }
         else 
         {    
              j_set_[n] = 0; geo_set_[m] = 0;
              j_e = j_mid;
         }
         m--;
         if (y > w_mid)
         {    
              w_set_[n] = 1; geo_set_[m] = 1;
              w_s = w_mid;
         }
         else 
         {    
              w_set_[n] = 0; geo_set_[m] = 0;
              w_e = w_mid;
         }
         n--; m--;
      }
      j_len_ = w_len_ =  N / 2;
      j_number_ = j_set_.to_ulong();
      w_number_ = w_set_.to_ulong(); 
      geo_len_ = N;
   }
   
   std::string convertToBase32(int len)
   {
      std::string base = "0123456789bcdefghjkmnpqrstuvwxyz";
      int n = len / 5;
      std::string ans(n, '0');
      std::string bit_str = geo_set_.to_string();
      std::istringstream bit_stream(bit_str);
 
      std::bitset<5> num_bitset;
      for (int i = 0; i < n; i++)
      {
         bit_stream >> num_bitset;
         ans[i] = base[num_bitset.to_ulong()];
      }
      return ans;
   }
   
   template <int M>
   static std::string convertToBase32(std::bitset<M> req_set)
   {
      std::string base = "0123456789bcdefghjkmnpqrstuvwxyz";
      int n = M / 5;
      std::string ans(n, '0');
      std::string bit_str = req_set.to_string();
      std::istringstream bit_stream(bit_str);
 
      std::bitset<5> num_bitset;
      for (int i = 0; i < n; i++)
      {
          bit_stream >> num_bitset;
          ans[i] = base[num_bitset.to_ulong()];
      }
      return ans;
   }
   
   template <int M, int N>
   static std::bitset< M + N > combine(std::bitset<M> j, std::bitset<N> w)
   {
      std::bitset<M+N> ans;
      for (int i = 0; i < M + N ;i++)
      {
          if (i & 1)
              ans[i] = w[ i / 2 + 1];
          else
              ans[i] = j[ i / 2];
      }
      return ans;
   } 
};



std::string void findEastNeighbor(long x, long y, 
                                  int target_len, int origin_len)
{
   x >>= (origin_len - target_len);
   y >>= (origin_len - target_len);
   x += 1;
   std::bitset<target_len> target_j(x);
   std::bitset<target_len> target_w(y);
   return convertToBase32(combine(target_j, target_w));
}

int main()
{
  const int n = 40;
  Geohash<n> geo = Geohash<n>(116.3906, 39.92324);
  std:: cout << geo.convertToBase32(40) << std::endl;
  std:: cout << geo.findEastNeighbor(5) << std::endl;
  
  int w = 5;
  
}



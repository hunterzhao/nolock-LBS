#ifndef _GEO_SERVICE_H_
#define _GEO_SERVICE_H_

#include <string>
#include <vector>
#include <map>
#include "geohash.h"
#include "trie_tree.h"
#include "type.h"

namespace geo 
{
class GeoService
{
public:
   GeoService() : tree_(new TrieTree()) 
   {
   }
   
   ~GeoService() {delete tree_;};
   
   bool insert(std::string code, Position p)
   {
      if (!tree_->insert(code))
      {
         return false;
      }
      //storage_[code].push_back(p);
      return true;
   }

   std::vector<Position> search(std::string code)
   {
      return storage_[code];
   }

   // dist km
   std::vector<Position> search(std::string code, int dist)
   {
       std::string geo_hash;
       if (dist > 2500)        geo_hash = code.substr(1);
       else if (dist > 630)    geo_hash = code.substr(2);
       else if (dist > 78)     geo_hash = code.substr(3);
       else if (dist > 20)     geo_hash = code.substr(4);
       else if (dist > 2.4)    geo_hash = code.substr(5);
       else if (dist > 0.61)   geo_hash = code.substr(6);
       else if (dist > 0.076)  geo_hash = code.substr(7);
       else if (dist > 0.019)  geo_hash = code.substr(8);
       return storage_[geo_hash];    
   } 
   
private:
   std::map<std::string, std::vector<Position>> storage_;
   TrieTree* tree_;      
};
}
#endif

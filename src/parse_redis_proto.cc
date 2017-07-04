#include <assert.h>
#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <sstream>
#include "log.h"
#include "parse_redis_proto.h"
#define MAX_PACKAGE_LEN 1024
/*
 *2\r\n
 $5\r\n
 hello\r\n
 $5\r\n
 world\r\n
*/

bool encode(std::string& res, int type, std::vector<std::string> package)
{
   int n = package.size();
   if (n ==0) return 0;
   switch(type)
   {
      case 0 : res += "+" + package[0] + "\r\n";  break;
      case 1 : res += '-' + package[0] + "\r\n"; break;
      case 2 : res += ':' + package[0] + "\r\n"; break;
   }  
 
   //ss << '*' << n << "\\r\\n";
   //for (int i = 0; i < n; i++)
   //{
   //   size_t cube_len = package[i].size(); 
   //   ss << '$' << cube_len << "\\r\\n";
   //   ss << package[i] << "\\r\\n";
   //}

   DLOG(INFO) << "redis res" << res; 
   if (res.size() > MAX_PACKAGE_LEN)
   {
       LOG(ERROR) << "mesg too long";
       return false;
   }
   return true;
}

bool decode(char* msg, int limit, int& len, std::vector<std::string>& ans)
{
   if (limit == 0) return false;
   char* p = msg;
   if (*p != '*')
      return false;
   p++; len++;

   std::string number= "";
   while (*p != '\r')
   {
      if (*p > '9' || *p < '0')
         return false;
      number.append(1, *p);
      p++; len++;
   }

   int n = std::stoi(number);
   
   if (n == 0)
      return true;

   if (*(p+1) != '\n')
      return false;
   p += 2; len += 2;
   
   std::string len_str = "";
   std::string str = "";
   for (int i = 0; i < n; i++)
   {
      if (*p != '$') return false;
      p++; len++;
      while (*p != '\r')
      {
         if (*p > '9' || *p < '0')
            return false;
         len_str.append(1, *p);
         p++; len++;
      }
      
      int len_local = std::stoi(len_str);
      len_str = "";
      if (*(p + 1) != '\n')
         return false;
      p += 2; len += 2;
      
      str = std::string(p, len_local);
      p += len_local; len += len_local;
      if (*(p+1) != '\n')
         return false;
      p += 2; len += 2;
      ans.emplace_back(str);
      str = "";
   }         
    
   return len <= limit;
}

//int main()
//{
//   char* txt = "*2\r\n$5\r\nhello\r\n$5\r\nworld\r\n";
//   int len = 0;
//   std::vector<std::string> ans;
//   assert(decode(txt, len, ans) == true);
//   std::cout << "len :" << len <<std::endl;
//   for (auto str : ans)
//     std::cout << str <<std::endl;
//}


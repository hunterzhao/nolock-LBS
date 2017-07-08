#include <assert.h>
#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <sstream>
#include "log.h"
#define MAX_PACKAGE_LEN 1024
/*
 *2\r\n
 $5\r\n
 hello\r\n
 $5\r\n
 world\r\n
*/

extern bool encode(std::string& res, int type, std::vector<std::string>& package);

bool decode(char* msg, int limit, int& len, std::vector<std::string>& ans);

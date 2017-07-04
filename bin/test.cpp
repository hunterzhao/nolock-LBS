#include "log.h"

int main(int argc, char* argv[])
{
   google::InitGoogleLogging(argv[0]);
   SET_LEVEL(Log::INFO);
   LBSLOG(Log::ERROR) << "hello world LBSLOG";
   VLOG(10) << "heheh";
}


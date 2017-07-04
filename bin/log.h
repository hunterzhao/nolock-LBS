#ifndef _LOG_H_
#define _LOG_H_
#include <glog/logging.h>
#include <string>
#include <fstream>

class Log{
public:
  enum {
    TRACE = 1,
    INFO = 2,
    WARNING = 3,
    ERROR = 4,
    FATAL = 5
  };
  
  static void set_level(int level)
  {
     level_ = level;
  }
private:
  static int level_;

}; 

int Log::level_ = 1;
#define SET_LEVEL(le)      \
        Log::set_level(le);

#define LBSLOG(severity)   \
        VLOG(severity)

// class GLogHelper
// {
// public:
//     GLogHelper(const char* program)
//     {
//         google::InitGoogleLogging(program);
//         initGlog();
//         //google::InstallFailureSignalHandler();
//         //默认捕捉 SIGSEGV 信号信息输出会输出到 stderr，可以通过下面的方法自定义输出方式：
//         //google::InstallFailureWriter(&SignalHandle);
//     }
//     ~GLogHelper()
//     {
//         google::ShutdownGoogleLogging();
//     }

//     void initGlog()
//     {
//         std::string home = "../log/";
//         std::string info_log = home + "info_";   
//         google::SetLogDestination(google::INFO, info_log.c_str());   
//         std::string warning_log = home + "warning_";   
//         google::SetLogDestination(google::WARNING, warning_log.c_str());   
//         std::string error_log = home + "error_";   
//         google::SetLogDestination(google::ERROR, error_log.c_str());   
//         std::string fatal_log = home + "fatal_";   
//         google::SetLogDestination(google::FATAL, fatal_log.c_str());   
//         FLAGS_alsologtostderr = 1;
//         FLAGS_colorlogtostderr= 1;
//         FLAGS_minloglevel = 0;
//     }
    
//     //将信息输出到单独的文件和 LOG(ERROR)
//     static void SignalHandle(const char* data, int size)
//     {
//         std::ofstream fs("glog_dump.log",std::ios::app);
//         std::string str = std::string(data,size);
//         fs<<str;
//         fs.close();
//         LOG(ERROR)<<str;
//     }
// };



#endif

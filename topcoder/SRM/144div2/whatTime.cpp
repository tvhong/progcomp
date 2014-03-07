//#include <sstream>
#include <cstdio>
#include <string>
class Time {
  public:
    std::string whatTime(int seconds) {
      int h, m, s;
      h = seconds / 3600, seconds %= 3600;
      m = seconds / 60, seconds %= 60;
      s = seconds;
      /*
      std::ostringstream ss;
      ss << h << ":" << m << ":" << s;
      return ss.str();
      */
      char buf[40];
      sprintf(buf, "%d:%d:%d", h, m, s);
      return std::string(buf);
    }
};

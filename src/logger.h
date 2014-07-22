#define PC

#ifdef ANDROID
#include <android/log.h>
#endif

#ifdef IOS
#endif

#ifdef PC
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#endif

namespace wtl
{
  void log(const char *t, ...)
  {

    #ifdef ANDROID
      __android_log_print(ANDROID_LOG_INFO, "WTL", t, __VA_ARGS__);
    #endif

    #ifdef PC
      va_list args;
      va_start(args,t);
      vprintf(t, args); //note the 'vprintf'
      printf("\n");
      va_end(args);
    #endif
  }

};


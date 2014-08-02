#define WTL_ANDROID

#ifdef WTL_ANDROID
#include <android/log.h>
#endif

#ifdef WTL_IOS
#endif

#ifdef WTL_PC
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#endif

namespace wtl
{
  void log(const char *t, ...)
  {

    #ifdef WTL_ANDROID
      __android_log_print(ANDROID_LOG_INFO, "WTL", t, __VA_ARGS__);
    #endif

    #ifdef WTL_PC
      va_list args;
      va_start(args,t);
      vprintf(t, args); //note the 'vprintf'
      printf("\n");
      va_end(args);
    #endif
  }

};


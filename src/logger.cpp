#include "logger.h"

void wtl::log(const char *t, ...)
{
    va_list args;
    va_start(args,t);
  #ifdef WTL_ANDROID
    __android_log_print(ANDROID_LOG_INFO, "WTL", t, args);
  #endif
  #ifdef WTL_PC
    vprintf(t, args); //note the 'vprintf'
    printf("\n");
  #endif
    va_end(args);
}


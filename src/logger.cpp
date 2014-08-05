#include "logger.h"

//I don't fully understand this, but apparently __VA_ARGS__ needs to be in a macro?
#ifdef WTL_ANDROID
#define WTL_ANDROID_LOG_MACRO(t, ...) __android_log_print(ANDROID_LOG_INFO, "WTL", t, __VA_ARGS__);
#endif

void wtl::log(const char *t, ...)
{
    va_list args;
    va_start(args,t);
  #ifdef WTL_ANDROID
    WTL_ANDROID_LOG_MACRO(t, args);
  #endif
  #ifdef WTL_PC
    vprintf(t, args); //note the 'vprintf'
    printf("\n");
  #endif
    va_end(args);
}


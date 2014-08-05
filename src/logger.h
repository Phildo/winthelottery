#ifndef _LOGGER_H_
#define _LOGGER_H_

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
  void log(const char *t, ...);
};

#endif


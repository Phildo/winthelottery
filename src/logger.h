#ifndef _LOGGER_H_
#define _LOGGER_H_

#include "defines.h"

#ifdef WTL_ANDROID
#include <android/log.h>
#define wtl_log(t, ...) __android_log_print(ANDROID_LOG_INFO, "WTL", t, ##__VA_ARGS__)
#endif

#ifdef WTL_IOS
#endif

#ifdef WTL_PC
#define wtl_log(t, ...) printf(t, ##__VA_ARGS__)
#endif

#endif


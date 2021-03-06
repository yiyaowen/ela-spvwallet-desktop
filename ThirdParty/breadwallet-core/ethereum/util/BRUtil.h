//
//  BBRUtil.h
//  breadwallet-core Ethereum
//
//  Created by Ed Gamble on 3/16/2018.
//  Copyright © 2018 Breadwinner AG.  All rights reserved.
//
//  See the LICENSE file at the project root for license information.
//  See the CONTRIBUTORS file at the project root for a list of contributors.

#ifndef BR_Util_H
#define BR_Util_H

#include "BRUtilHex.h"
#include "BRUtilMath.h"

#if 0
#define eth_log(topic, formatter, ...)   _eth_log("ETH: %s: " formatter "\n", (topic), __VA_ARGS__)
#else

#ifdef __cplusplus
extern "C" void ElastosElaWalletLog(const char *s);
#else
void ElastosElaWalletLog(const char *s);
#endif

#define eth_log(topic, formatter, ...)   do { \
	char buf[2048]; \
	snprintf(buf, sizeof(buf), "ETH: %s: " formatter, (topic), __VA_ARGS__); \
	ElastosElaWalletLog(buf); \
} while (0)

#endif

#if defined(TARGET_OS_MAC)
//#  include <Foundation/Foundation.h>
//#  define _eth_log(...) NSLog(__VA_ARGS__)
#  include <stdio.h>
#  define _eth_log(...) printf(__VA_ARGS__)
#elif defined(__ANDROID__)
#  include <android/log.h>
#  define _eth_log(...) __android_log_print(ANDROID_LOG_INFO, "bread", __VA_ARGS__)
#else
#  include <stdio.h>
#  define _eth_log(...) printf(__VA_ARGS__)
#endif

#endif // BR_Util_H

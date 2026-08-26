/*
 * QBuild POSIX helper
 * Includes posix functions and provide posix helper functions on posix platforms
 */

#ifndef _qbuild_posix_internal_h_
#define _qbuild_posix_internal_h_

// Check if posix standard header is available
#if defined(__has_include) && !defined(__POSIX__)
#	if __has_include(<unistd.h>)
#		define __POSIX__
#	endif
#endif

// Checck if platform is one of known posix platforms
#ifndef __POSIX__
#	if defined(__linux__)
#		define __POSIX__
#	endif
#endif

#ifdef __POSIX__
#include <unistd.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

#endif


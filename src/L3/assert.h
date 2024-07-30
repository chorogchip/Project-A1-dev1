#pragma once

#include <cassert>

[[noreturn]] inline void unreachable()
{
#if defined(_MSC_VER) && !defined(__clang__) // MSVC
    __assume(false);
    __builtin_unreachable();
#endif
}

#define ASSERT_LEVEL 0

#if ASSERT_LEVEL >= 0
    #define ASSERT_RELEASE(x) assert((x))
#else
    #define ASSERT_RELEASE(x)
#endif

#if ASSERT_LEVEL >= 1
    #define ASSERT_ALPHA(x) assert((x))
    #define ASSERT_UNREACHABLE() assert(false)
#else
    #define ASSERT_ALPHA(x)
    #define ASSERT_UNREACHABLE() unreachable()
#endif

#if ASSERT_LEVEL >= 2
    #define ASSERT_DEBUG(x) assert((x))
#else
    #define ASSERT_DEBUG(x)
#endif

#if ASSERT_LEVEL >= 3
    #define ASSERT_SLOW(x) assert((x))
#else
    #define ASSERT_SLOW(x)
#endif

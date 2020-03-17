#pragma once

// define all other platforms to be zero
//@port Define the platform here to be zero when compiling for other platforms
#ifdef _MSC_VER
#define PLATFORM_WINDOWS 1
#else
#define PLATFORM_LINUX 1
#endif

#include "../GenericPlatform/GenericPlatform.h"

#if PLATFORM_WINDOWS
#include "../Windows/WindowsPlatform.h"
#endif

#if PLATFORM_LINUX
#include "../Linux/LinuxPlatform.h"
#endif

//---------------------------------------------------------
// Include main platform setup header (XXX/XXXPlatform.h)
//---------------------------------------------------------

//#include COMPILED_PLATFORM_HEADER(Platform.h)

//------------------------------------------------------------------
// Finalize define setup
//------------------------------------------------------------------
// Alignment.
#ifndef GCC_PACK
#define GCC_PACK(n)
#endif
#ifndef GCC_ALIGN
#define GCC_ALIGN(n)
#endif
#ifndef MS_ALIGN
#define MS_ALIGN(n)
#endif

/** Branch prediction hints */
#ifndef LIKELY /* Hints compiler that expression is likely to be true, much softer than ASSUME - \
                  allows (penalized by worse performance) expression to be false */
#if (defined(__clang__) || defined(__GNUC__)) && (PLATFORM_UNIX) // effect of these on non-Linux
                                                                 // platform has not been analyzed
                                                                 // as of 2016-03-21
#define LIKELY(x) __builtin_expect(!!(x), 1)
#else
#define LIKELY(x) (x)
#endif
#endif

#ifndef UNLIKELY /* Hints compiler that expression is unlikely to be true, allows (penalized by \ \
                    \ \ worse performance) expression to be true */
#if (defined(__clang__) || defined(__GNUC__)) && (PLATFORM_UNIX) // effect of these on non-Linux
                                                                 // platform has not been analyzed
                                                                 // as of 2016-03-21
#define UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#define UNLIKELY(x) (x)
#endif
#endif

#if USING_THREAD_SANITISER
#if !defined(TSAN_SAFE) || !defined(TSAN_BEFORE) || !defined(TSAN_AFTER) || !defined(TSAN_ATOMIC)
#error Thread Sanitiser macros are not configured correctly for this platform
#endif
#else
// Define TSAN macros to empty when not enabled
#define TSAN_SAFE
#define TSAN_BEFORE(Addr)
#define TSAN_AFTER(Addr)
#define TSAN_ATOMIC(Type) Type
#endif

// If we don't have a platform-specific define for the TEXT macro, define it now.
#if !defined(TEXT) && !UE_BUILD_DOCS
#if PLATFORM_TCHAR_IS_CHAR16
#define TEXT_PASTE(x) u##x
#else
#define TEXT_PASTE(x) L##x
#endif
#define TEXT(x) TEXT_PASTE(x)
#endif

// Prefetch
#ifndef PLATFORM_CACHE_LINE_SIZE
#define PLATFORM_CACHE_LINE_SIZE 64
#endif

#ifndef RESTRICT
#define RESTRICT __restrict /* no alias hint */
#endif

#ifndef PLATFORM_SUPPORTS_GEOMETRY_SHADERS
#define PLATFORM_SUPPORTS_GEOMETRY_SHADERS 1
#endif

#ifndef PLATFORM_SUPPORTS_TESSELLATION_SHADERS
#define PLATFORM_SUPPORTS_TESSELLATION_SHADERS 1
#endif


//------------------------------------------------------------------
// Transfer the platform types to global types
//------------------------------------------------------------------

//~ Unsigned base types.
/// An 8-bit unsigned integer.
typedef FPlatformTypes::uint8 uint8;
/// A 16-bit unsigned integer.
typedef FPlatformTypes::uint16 uint16;
/// A 32-bit unsigned integer.
typedef FPlatformTypes::uint32 uint32;
/// A 64-bit unsigned integer.
typedef FPlatformTypes::uint64 uint64;

//~ Signed base types.
/// An 8-bit signed integer.
typedef FPlatformTypes::int8 int8;
/// A 16-bit signed integer.
typedef FPlatformTypes::int16 int16;
/// A 32-bit signed integer.
typedef FPlatformTypes::int32 int32;
/// A 64-bit signed integer.
typedef FPlatformTypes::int64 int64;

//~ Character types.
/// An ANSI character. Normally a signed type.
typedef FPlatformTypes::ANSICHAR ANSICHAR;
/// A wide character. Normally a signed type.
typedef FPlatformTypes::WIDECHAR WIDECHAR;
/// Either ANSICHAR or WIDECHAR, depending on whether the platform supports wide characters or the
/// requirements of the licensee.
typedef FPlatformTypes::TCHAR TCHAR;
/// An 8-bit character containing a UTF8 (Unicode, 8-bit, variable-width) code unit.
typedef FPlatformTypes::CHAR8 UTF8CHAR;
/// A 16-bit character containing a UCS2 (Unicode, 16-bit, fixed-width) code unit, used for
/// compatibility with 'Windows TCHAR' across multiple platforms.
typedef FPlatformTypes::CHAR16 UCS2CHAR;
/// A 16-bit character containing a UTF16 (Unicode, 16-bit, variable-width) code unit.
typedef FPlatformTypes::CHAR16 UTF16CHAR;
/// A 32-bit character containing a UTF32 (Unicode, 32-bit, fixed-width) code unit.
typedef FPlatformTypes::CHAR32 UTF32CHAR;

/// An unsigned integer the same size as a pointer
typedef FPlatformTypes::UPTRINT UPTRINT;
/// A signed integer the same size as a pointer
typedef FPlatformTypes::PTRINT PTRINT;
/// An unsigned integer the same size as a pointer, the same as UPTRINT
typedef FPlatformTypes::SIZE_T SIZE_T;
/// An integer the same size as a pointer, the same as PTRINT
typedef FPlatformTypes::SSIZE_T SSIZE_T;

/// The type of the NULL constant.
typedef FPlatformTypes::TYPE_OF_NULL TYPE_OF_NULL;
/// The type of the C++ nullptr keyword.
typedef FPlatformTypes::TYPE_OF_NULLPTR TYPE_OF_NULLPTR;
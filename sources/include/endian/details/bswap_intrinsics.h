#ifndef endian_bswap_intrinsics_h
#define endian_bswap_intrinsics_h
//  THIS WAS COPIED FROM boost::endian intrinsic.hpp FILE. ALSO MACRO NAMES WERE
//  CHANGED. Allow user to force BSWAP_NO_INTRINSICS in case they aren't
//  available for a particular platform/compiler combination.
#ifndef BSWAP_NO_INTRINSICS

#ifndef __has_builtin       // Optional of course
#define __has_builtin(x) 0  // Compatibility with non-clang compilers
#endif

#if defined(_MSC_VER) && (!defined(__clang__) || defined(__c2__))
//  Microsoft documents these as being compatible since Windows 95 and
//  specifically lists runtime library support since Visual Studio 2003
//  (aka 7.1). Clang/c2 uses the Microsoft rather than GCC intrinsics, so we
//  check for defined(_MSC_VER) before defined(__clang__)
#define BSWAP_INTRINSIC_MSG "cstdlib _byteswap_ushort, etc."
#include <cstdlib>
#define BSWAP_INTRINSIC_2(x) _byteswap_ushort(x)
#define BSWAP_INTRINSIC_4(x) _byteswap_ulong(x)
#define BSWAP_INTRINSIC_8(x) _byteswap_uint64(x)

//  GCC and Clang recent versions provide intrinsic byte swaps via builtins
#elif (defined(__clang__) && __has_builtin(__builtin_bswap32) && \
       __has_builtin(__builtin_bswap64)) ||                      \
    (defined(__GNUC__) &&                                        \
     (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3)))
#define BSWAP_INTRINSIC_MSG "__builtin_bswap16, etc."
// prior to 4.8, gcc did not provide __builtin_bswap16 on some platforms so we
// emulate it see http://gcc.gnu.org/bugzilla/show_bug.cgi?id=52624 Clang has a
// similar problem, but their feature test macros make it easier to detect
#if (defined(__clang__) && __has_builtin(__builtin_bswap16)) || \
    (defined(__GNUC__) &&                                       \
     (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 8)))
#define BSWAP_INTRINSIC_2(x) __builtin_bswap16(x)
#else
#define BSWAP_INTRINSIC_2(x) __builtin_bswap32((x) << 16)
#endif
#define BSWAP_INTRINSIC_4(x) __builtin_bswap32(x)
#define BSWAP_INTRINSIC_8(x) __builtin_bswap64(x)

#define BSWAP_CONSTEXPR_INTRINSICS

//  Linux systems provide the byteswap.h header, with
#elif defined(__linux__)
//  don't check for obsolete forms defined(linux) and defined(__linux) on the
//  theory that compilers that predefine only these are so old that byteswap.h
//  probably isn't present.
#define BSWAP_INTRINSIC_MSG "byteswap.h bswap_16, etc."
#include <byteswap.h>
#define BSWAP_INTRINSIC_2(x) bswap_16(x)
#define BSWAP_INTRINSIC_4(x) bswap_32(x)
#define BSWAP_INTRINSIC_8(x) bswap_64(x)

#else
#define BSWAP_NO_INTRINSICS
#define BSWAP_INTRINSIC_MSG "no byte swap intrinsics"
#endif

#elif !defined(BSWAP_INTRINSIC_MSG)
#define BSWAP_INTRINSIC_MSG "no byte swap intrinsics"
#endif  // BSWAP_NO_INTRINSICS

#endif /* endian_bswap_intrinsics_h */

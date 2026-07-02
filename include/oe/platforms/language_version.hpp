/**
 * @file language_version.hpp
 * @brief Defines the language version detection
 * Supports C and C++
 * OE_LANGUAGE_TYPE is for the language type string
 * OE_LANGUAGE_TYPE_CPP is defined for C++
 * OE_LANGUAGE_TYPE_C is defined for C
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#ifdef __cplusplus
/**
 * @define OE_LANGUAGE_TYPE
 * @brief Defines the language type string for C++
 */
#define OE_LANGUAGE_TYPE "C++"

/**
 * @define OE_LANGUAGE_TYPE_CPP
 * @brief Defines the language type for C++
 */
#define OE_LANGUAGE_TYPE_CPP

/**
 * @define OE_LANGUAGE_CPP_STANDARD
 * @brief Defines the C++ standard version for the current language type
 * OE_LANGUAGE_CPP_STANDARD is defined to the standard version string (e.g.
 * "23").
 * OE_LANGUAGE_TYPE_CPP<version> is defined for the standard version (e.g.
 * OE_LANGUAGE_TYPE_CPP23)
 * OE_LANGAUGE_CPP_STANDARD_ID is defined to the standard version ID (e.g.
 * 2023L), can be compared.
 */
#if __cplusplus >= 202302L
#define OE_LANGUAGE_CPP_STANDARD "23"
#define OE_LANGAUGE_CPP_STANDARD_ID 2023L
#define OE_LANGUAGE_TYPE_CPP23
#elif __cplusplus >= 201703L
#define OE_LANGUAGE_CPP_STANDARD "17"
#define OE_LANGAUGE_CPP_STANDARD_ID 2017L
#define OE_LANGUAGE_TYPE_CPP17
#elif __cplusplus >= 201402L
#define OE_LANGUAGE_CPP_STANDARD "14"
#define OE_LANGAUGE_CPP_STANDARD_ID 2014L
#define OE_LANGUAGE_TYPE_CPP14
#elif __cplusplus >= 201103L
#define OE_LANGUAGE_CPP_STANDARD "11"
#define OE_LANGAUGE_CPP_STANDARD_ID 2011L
#define OE_LANGUAGE_TYPE_CPP11
#elif __cplusplus >= 199711L
#define OE_LANGUAGE_CPP_STANDARD "98"
#define OE_LANGAUGE_CPP_STANDARD_ID 1997L
#define OE_LANGUAGE_TYPE_CPP98
#else
#error "Unsupported C++ standard"
#endif

#elif defined(__STDC_VERSION__)
/**
 * @define OE_LANGUAGE_TYPE
 * @brief Defines the language type string for C
 */
#define OE_LANGUAGE_TYPE "C"

/**
 * @define OE_LANGUAGE_TYPE_C
 * @brief Defines the language type for C
 */
#define OE_LANGUAGE_TYPE_C

/**
 * @define OE_LANGUAGE_C_STANDARD
 * @brief Defines the C standard version for the current language type
 * OE_LANGUAGE_C_STANDARD is defined to the standard version string (e.g. "23")
 * OE_LANGUAGE_TYPE_C<version> is defined for the standard version (e.g.
 * OE_LANGUAGE_TYPE_C23)
 */
#if __STDC_VERSION__ >= 202311L
#define OE_LANGUAGE_C_STANDARD "23"
#define OE_LANGUAGE_TYPE_C23
#elif __STDC_VERSION__ >= 201710L
#define OE_LANGUAGE_C_STANDARD "17"
#define OE_LANGUAGE_TYPE_C17
#elif __STDC_VERSION__ >= 201112L
#define OE_LANGUAGE_C_STANDARD "11"
#define OE_LANGUAGE_TYPE_C11
#elif __STDC_VERSION__ >= 199901L
#define OE_LANGUAGE_C_STANDARD "99"
#define OE_LANGUAGE_TYPE_C99
#elif __STDC_VERSION__ >= 199409L
#define OE_LANGUAGE_C_STANDARD "95"
#define OE_LANGUAGE_TYPE_C95
#else
#error "Unsupported C standard"
#endif

#endif

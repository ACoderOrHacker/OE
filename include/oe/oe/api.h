/**
 * @file api.h
 * @brief The OE API header.
 * This header defines the OE API macro used to mark functions as exported from
 * the OE library.
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#include <oe/platforms/compiler.hpp>
#ifdef OE_SHARED
#ifdef OE_COMPILER_MICROSOFT_VISUAL_CPP
/**
 * @define OE_API
 * @brief The OE API macro.
 * This macro is used to mark functions as exported from the OE library.
 */
#define OE_API __declspec(dllexport)
#else
// Ditto
#define OE_API
#endif
#else
// Ditto
#define OE_API
#endif

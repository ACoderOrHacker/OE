/**
 * @file posix_headers.hpp
 * @brief Simple include headers for POSIX platforms, don't need to check for
 * OE_PLATFORM_POSIX_SYSTEM
 */
#pragma once

#include <oe/platforms/system.hpp>

#ifdef OE_PLATFORM_POSIX_SYSTEM
#include <unistd.h>
#endif

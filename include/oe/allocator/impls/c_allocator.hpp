/**
 * @file c_allocator.hpp
 * @brief A C allocator implementation that uses the standard C library.
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#include <oe/oe/unused.h>
#include <oe/platforms/msvc_flag_detection.hpp>
#include <oe/allocator/allocator_define.hpp>

#ifdef OE_MSVC_FLAG_DETECTED
// MSVC CRT headers
#include <malloc.h>
#else
#include <cstdlib>
#endif

namespace oe {
OE_DEFINE_ALLOCATOR(c_allocator)

inline oe::pvoid
c_allocator::allocate(oe::usize size, oe::memory_alignment alignment) noexcept {
    OE_UNUSED(alignment);
#if defined(OE_MSVC_FLAG_DETECTED)
    // an unstandard function
    // see cppreference for more details.
    // MSVC CRT has not defined std::aligned_malloc but defined _aligned_malloc
    return _aligned_malloc(size, alignment);
#else
    return std::aligned_alloc(alignment, size);
#endif
}

inline void c_allocator::deallocate(oe::pvoid ptr,
                                    oe::memory_alignment alignment) noexcept {
    OE_UNUSED(alignment);
#if defined(OE_MSVC_FLAG_DETECTED)
    _aligned_free(ptr);
#else
    std::free(ptr);
#endif
}

inline bool c_allocator::resize(oe::pvoid ptr, oe::memory_alignment alignment,
                                oe::usize new_size) noexcept {
    OE_UNUSED(ptr);
    OE_UNUSED(alignment);
    OE_UNUSED(new_size);
    return false; // C Allocator does not support resize
}

inline oe::pvoid c_allocator::remap(oe::pvoid ptr,
                                    oe::memory_alignment alignment,
                                    oe::usize new_size) noexcept {
    if (new_size == 0)
        return ptr;
#ifdef OE_MSVC_FLAG_DETECTED
    // an unstandard function
    // see cppreference for more details.
    // MSVC CRT has not defined std::aligned_realloc but defined
    // _aligned_realloc
    return _aligned_realloc(ptr, new_size, alignment);
#else
    OE_UNUSED(alignment);
    return std::realloc(ptr, new_size);
#endif
}

} // namespace oe

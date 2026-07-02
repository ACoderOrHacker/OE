/**
 * @file allocator_define.hpp
 * @brief Defines the OE_DEFINE_ALLOCATOR macro for creating allocator
 * templates.
 * @note This header file guarantees to export oe/oe/api, oe/types,
 * oe/allocator/static_allocator, and oe/allocator/dyn_allocator. So you don't
 * need to include these headers yourself when using this macro.
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#include <oe/oe/api.h>
#include <oe/types.hpp>
#include <oe/allocator/static_allocator.hpp>
#include <oe/allocator/dynamic_allocator.hpp>

/**
 * @define OE_DEFINE_ALLOCATOR
 * @brief Creates an allocator template
 * Creates a static and dynamic allocator template with the given name
 * (<name>, dyn_<name>). And you should implement the <name>'s allocator methods
 * yourself.
 * @param name The name of the allocator to create
 */
#define OE_DEFINE_ALLOCATOR(name)                                              \
    class OE_API name {                                                        \
      public:                                                                  \
        static oe::pvoid allocate(oe::usize size,                              \
                                  oe::memory_alignment alignment) noexcept;    \
        static void deallocate(oe::pvoid ptr,                                  \
                               oe::memory_alignment alignment) noexcept;       \
        static bool resize(oe::pvoid ptr, oe::memory_alignment alignment,      \
                           oe::usize new_size) noexcept;                       \
        static oe::pvoid remap(oe::pvoid ptr, oe::memory_alignment alignment,  \
                               oe::usize new_size) noexcept;                   \
    };                                                                         \
    class OE_API OE_ID_CONTACT(dyn_, name) : public oe::dyn_allocator_base {   \
      public:                                                                  \
        inline oe::pvoid                                                       \
        allocate(oe::usize size,                                               \
                 oe::memory_alignment alignment) noexcept override {           \
            return name::allocate(size, alignment);                            \
        }                                                                      \
        inline void                                                            \
        deallocate(oe::pvoid ptr,                                              \
                   oe::memory_alignment alignment) noexcept override {         \
            name::deallocate(ptr, alignment);                                  \
        }                                                                      \
        inline bool resize(oe::pvoid ptr, oe::memory_alignment alignment,      \
                           oe::usize new_size) noexcept override {             \
            return name::resize(ptr, alignment, new_size);                     \
        }                                                                      \
        inline oe::pvoid remap(oe::pvoid ptr, oe::memory_alignment alignment,  \
                               oe::usize new_size) noexcept override {         \
            return name::remap(ptr, alignment, new_size);                      \
        }                                                                      \
    };\

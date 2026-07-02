/**
 * @file static_allocator.hpp
 * @brief The static allocator implementation.
 * First using this for zero overhead
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#include <oe/oe/api.h>
#include <oe/types.hpp>
#include <oe/allocator/allocator_traits.hpp>
#include <oe/allocator/allocator_interfaces.hpp>

namespace oe {
namespace details {
namespace allocator {
/**
 * @brief The static allocator implementation.
 * This allocator uses the static allocator type T to allocate memory.
 * It is a simple wrapper around the static allocator type T.
 */
template <typename Allocator> struct OE_API allocator_impl {
    static_assert(oe::is_allocator_v<Allocator>,
                  "Allocator requires an allocator type, must follow the "
                  "oe::is_allocator");

    /**
     * @brief Allocates memory of the given size and alignment, using just the
     * allocator implementation.
     * @note Should be freed with raw_deallocate
     * @see raw_deallocate
     * @pre The size must be greater than 0
     * @pre The alignment must be a power of 2
     * @param[in] size The size of the memory to allocate
     * @param[in] alignment The alignment of the memory to allocate
     * @return A pointer to the allocated memory, nullptr if the allocation
     * fails
     */
    inline oe::pvoid raw_allocate(oe::usize size,
                                  oe::memory_alignment alignment) {
        return Allocator::allocate(size, alignment);
    }

    /**
     * @brief Frees the memory allocated by raw_allocate
     * @details This function should only be used to free memory allocated by
     * raw_allocate, if the ptr is a nullptr, the function does nothing.
     * @see raw_allocate
     * @pre The alignment must be a power of 2
     * @param[in] ptr The pointer to the memory to free
     * @param[in] alignment The alignment of the memory to free
     */
    inline void raw_deallocate(oe::pvoid ptr,
                               oe::memory_alignment alignment) noexcept {
        Allocator::deallocate(ptr, alignment);
    }

    /**
     * @brief Resize the memory at the given pointer to the given size and
     * alignment
     * @details If the ptr is nullptr, this function returns false.
     * If the new size is 0, this function deallocates the memory and returns
     * true. It is sure not to move the pointer. So the allocator implementation
     * can refuse this operation and return false.
     * @see raw_remap
     * @param[in] ptr The pointer to the memory to resize
     * @param[in] alignment The alignment of the memory to resize
     * @param[in] new_size The new size of the memory
     * @return The status of the resize operation. False if the resize fails,
     * true otherwise.
     */
    inline bool raw_resize(oe::pvoid ptr, oe::memory_alignment alignment,
                           oe::usize new_size) noexcept {
        return Allocator::resize(ptr, alignment, new_size);
    }

    /**
     * @brief Remap the memory at the given pointer to the given size and
     * alignment
     * @details If the ptr is nullptr, this function does nothing.
     * If the new size is 0, this function deallocates the memory and returns
     * the old pointer (freed). It may move the pointer and copy the old data to
     * the new location.
     * @see raw_resize
     * @param[in] ptr The pointer to the memory to resize
     * @param[in] alignment The alignment of the memory to resize
     * @param[in] new_size The new size of the memory
     * @return The reallocated pointer, nullptr if the allocation fails, the old
     * pointer (freed) if new_size is 0
     */
    inline oe::pvoid raw_remap(oe::pvoid ptr, oe::memory_alignment alignment,
                               oe::usize new_size) noexcept {
        return Allocator::remap(ptr, alignment, new_size);
    }
};
} // namespace allocator
} // namespace details

/**
 * @brief The static allocator implementation.
 */
template <typename Allocator>
using allocator = details::allocator::allocator_interfaces<
    details::allocator::allocator_impl<Allocator>>;

} // namespace oe

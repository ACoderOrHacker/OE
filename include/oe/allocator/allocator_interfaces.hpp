/**
 * @file allocator_interfaces.hpp
 * @brief The public interfaces for allocator
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#include <oe/allocator/allocator_traits.hpp>
#include <oe/array/dyn_size_array.hpp>

namespace oe {
namespace details {
namespace allocator {
/**
 * @brief The public interfaces for allocator
 */
template <typename Impl> struct OE_API allocator_interfaces : public Impl {
    template <typename... Args>
    inline explicit allocator_interfaces(Args&&... args)
        : Impl(std::forward<Args>(args)...) {}

    /**
     * @brief Allocates memory for the type T with the given alignment
     * @see deallocate
     * @pre alignment must be a power of 2
     * @pre sizeof(T) * n cannot overflow
     * @tparam T The type of the memory to allocate
     * @param[in] n The number of elements to allocate, default is 1
     * @param[in] alignment The alignment of the memory to allocate, default is
     * alignof(T)
     * @return A array to the allocated memory, ptr() == nullptr if the
     * allocation fails
     */
    template <typename T>
    inline oe::dyn_size_array<T>
    allocate(oe::usize n = 1,
             oe::memory_alignment alignment = alignof(T)) noexcept {
        return oe::dyn_size_array<T>{
            static_cast<T*>(this->raw_allocate(sizeof(T) * n, alignment)), n};
    }

    /**
     * @brief Frees the memory allocated by allocate
     * @details This function should only be used to free memory allocated by
     * allocate, if the ptr is a nullptr, the function does nothing.
     * @see allocate
     * @tparam T The type of the memory to free
     * @param[out] data The data to free, the ptr() is unknown after this call
     * @param[in] alignment The alignment of the memory to free
     */
    template <typename T>
    inline void
    deallocate(dyn_size_array<T> data,
               oe::memory_alignment alignment = alignof(T)) noexcept {
        this->raw_deallocate(data.ptr(), alignment);
    }

    /**
     * @brief Resize the memory at the given pointer to the given size
     * @details If the ptr is nullptr, this function returns false.
     * If the n is 0, this function deallocates the memory and returns
     * true. It is sure not to move the pointer. So the allocator implementation
     * can refuse this operation and return false.
     * @see raw_resize
     * @pre sizeof(T) * n cannot overflow
     * @tparam T The type of the memory to resize
     * @param[in] ptr The pointer to resize
     * @param[in] new_size The new size of the memory to resize
     * @param[in] alignment The alignment of the memory to resize
     * @return The status of the resize operation. False if the resize fails,
     * true otherwise.
     */
    template <typename T>
    inline bool resize(oe::pvoid ptr, oe::usize n,
                       oe::memory_alignment alignment = alignof(T)) noexcept {
        return this->raw_resize(ptr, alignment, sizeof(T) * n);
    }

    /**
     * @brief Remap the memory at the given pointer to the given size
     * @details If the ptr is nullptr, this function returns nullptr.
     * If the n is 0, this function deallocates the memory and returns
     * the old pointer (freed). It may move the pointer and copy the old data to
     * the new location.
     * @see raw_remap
     * @pre sizeof(T) * n cannot overflow
     * @param[in] ptr The pointer to remap
     * @param[in] n The number of elements to remap
     * @param[in] alignment The alignment of the memory to remap
     * @return The reallocated data, ptr() == nullptr if the allocation fails,
     * ptr() == the old pointer (freed) if n is 0
     */
    template <typename T>
    inline dyn_size_array<T>
    remap(oe::pvoid ptr, oe::usize n,
          oe::memory_alignment alignment = alignof(T)) noexcept {
        return dyn_size_array<T>{
            static_cast<T*>(this->raw_remap(ptr, alignment, sizeof(T) * n)), n};
    }

    /**
     * @brief Reallocates the memory allocated by allocate
     * @details if the ptr is a nullptr, the function allocates a new block of
     * memory. This function can only failed on out-of-memory.
     * @see allocate remap
     * @pre sizeof(T) * n cannot overflow
     * @param[in] ptr The pointer to reallocate
     * @param[in] n The number of elements to reallocate
     * @param[in] alignment The alignment of the memory to reallocate
     * @return A data array to the reallocated memory, ptr() == nullptr if the
     * reallocation fails, ptr() == the old pointer (freed) if data.size() is 0
     */
    template <typename T>
    inline oe::dyn_size_array<T>
    reallocate(oe::pvoid ptr, oe::usize n,
               oe::memory_alignment alignment = alignof(T)) noexcept {
        T* new_ptr = this->remap<T>(ptr, n, alignment);
        if (new_ptr != nullptr)
            return new_ptr;
        return this->allocate<T>(n, alignment);
    }
};
} // namespace allocator
} // namespace details
} // namespace oe

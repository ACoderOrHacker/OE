/**
 * @file dynamic_allocator.hpp
 * @brief The dynamic allocator interface *Actually, you should use
 * `oe::static_allocator` as usual. So think carefully before using this.
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#include <oe/oe/api.h>
#include <oe/types.hpp>
#include <oe/traits.hpp>
#include <oe/allocator/allocator_traits.hpp>
#include <oe/allocator/allocator_interfaces.hpp>

namespace oe {

/**
 * @brief The allocator interface
 * @details The dyn_allocator_base is a low-level interface for dynamic memory
 * allocation. Users can derive from this class to implement their own dynamic
 * allocators.
 * @note All the dyn_allocator_base or it's children follow the allocator
 * interface specs. So oe::is_allocator_v<dyn_allocator_base> or
 * oe::is_allocator_v< <child-of-dyn_allocator_base> > are always true
 */
class OE_API dyn_allocator_base {
  public:
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
    virtual pvoid allocate(oe::usize size,
                           oe::memory_alignment alignment) noexcept = 0;

    /**
     * @brief Frees the memory allocated by raw_allocate
     * @details This function should only be used to free memory allocated by
     * raw_allocate, if the ptr is a nullptr, the function does nothing.
     * @see raw_allocate
     * @pre The alignment must be a power of 2
     * @param[in] ptr The pointer to the memory to free
     * @param[in] alignment The alignment of the memory to free
     */
    virtual void deallocate(oe::pvoid ptr,
                            oe::memory_alignment alignment) noexcept = 0;

    /**
     * @brief Resize the memory at the given pointer to the given size and
     * alignment
     * @details If the ptr is nullptr, this function returns false.
     * If the new size is 0, this function deallocates the memory and returns
     * true. It is sure not to move the pointer. So the allocator implementation
     * can refuse this operation and return false.
     * @see remap
     * @param[in] ptr The pointer to the memory to resize
     * @param[in] alignment The alignment of the memory to resize
     * @param[in] new_size The new size of the memory
     * @return The status of the resize operation. False if the resize fails,
     * true otherwise.
     */
    virtual bool resize(oe::pvoid ptr, oe::memory_alignment alignment,
                        oe::usize new_size) noexcept = 0;

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
    virtual oe::pvoid remap(oe::pvoid ptr, oe::memory_alignment alignment,
                            oe::usize new_size) noexcept = 0;
};

namespace details {
namespace allocator {
/**
 * @brief The dynamic allocator interface.
 * Provides a high-level interface for dynamic memory allocation.
 */
class OE_API dyn_allocator_impl {
  public:
    /**
     * @brief Constructs a dyn_allocator_impl with the given allocator
     * implementation
     * @param[in] allocator_impl The allocator implementation to use
     */
    inline explicit dyn_allocator_impl(
        dyn_allocator_base* allocator_impl) noexcept
        : m_vtable(allocator_impl) {}

    /**
     * @brief Returns the allocator implementation
     * @return A reference to the allocator implementation, can be changed to a
     * different implementation
     */
    inline dyn_allocator_base*& vtable() noexcept { return m_vtable; }

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
                                  oe::memory_alignment alignment) noexcept {
        return vtable()->allocate(size, alignment);
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
        vtable()->deallocate(ptr, alignment);
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
        return vtable()->resize(ptr, alignment, new_size);
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
        return vtable()->remap(ptr, alignment, new_size);
    }

  private:
    dyn_allocator_base* m_vtable;
};
} // namespace allocator
} // namespace details

/**
 * @brief The dynamic allocator interface, provides a high-level interface for
 * dynamic memory allocation.
 */
using dyn_allocator = details::allocator::allocator_interfaces<
    details::allocator::dyn_allocator_impl>;

static_assert(oe::is_allocator_v<dyn_allocator_base>,
              "Compilation failed: oe::dyn_allocator_base does not follow the "
              "allocator interface specs, please report this issue");

} // namespace oe

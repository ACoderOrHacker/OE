/**
 * @file allocator_traits.hpp
 * @brief The allocator traits. Gives the allocator specs check.
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#include <oe/types.hpp>
#include <oe/traits.hpp>
#include <oe/oe/idcontact.h>

namespace oe {
using memory_alignment = oe::usize; //!< Memory alignment type

namespace details {
namespace allocator {
/**
 * @brief Checks if a type has an `allocate` member function with the correct
 * signature
 */
OE_DEFINE_HAS_FUNCTION_MEMBER(has_allocate, allocate, oe::pvoid, oe::usize,
                              oe::memory_alignment);

/**
 * @brief Checks if a type has a `deallocate` member function with the correct
 * signature
 */
OE_DEFINE_HAS_FUNCTION_MEMBER(has_deallocate, deallocate, void, oe::pvoid,
                              oe::memory_alignment);

/**
 * @brief Checks if a type has a `resize` member function with the correct
 * signature
 */
OE_DEFINE_HAS_FUNCTION_MEMBER(has_resize, resize, bool, oe::pvoid,
                              oe::memory_alignment, oe::usize);

/**
 * @brief Checks if a type has a `remap` member function with the correct
 * signature
 */
OE_DEFINE_HAS_FUNCTION_MEMBER(has_remap, remap, oe::pvoid, oe::pvoid,
                              oe::memory_alignment, oe::usize);
} // namespace allocator
} // namespace details

/**
 * @brief Checks if a type follows the allocator interface specs
 *
 * @tparam T The type to check
 * @return true if the type follows the allocator interface specs, false
 * otherwise
 */
template <typename T>
using is_allocator = oe::conjunction<oe::details::allocator::has_allocate<T>,
                                     oe::details::allocator::has_deallocate<T>,
                                     oe::details::allocator::has_resize<T>,
                                     oe::details::allocator::has_remap<T>>;

/**
 * @brief Checks if a type follows the allocator interface specs
 *
 * @tparam T The type to check
 * @return true if the type follows the allocator interface specs, false
 * otherwise
 */
template <typename T>
constexpr inline bool is_allocator_v = is_allocator<T>::value;

} // namespace oe

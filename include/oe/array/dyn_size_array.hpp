/**
 * @file dyn_size_array.hpp
 * @brief Dynamic size array implementation
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#include <oe/types.hpp>
#include <oe/utility.hpp>

namespace oe {
/**
 * @brief Dynamic size array implementation
 * @details You should allocate the memory yourself.
 * It's low-level and requires manual memory management.
 * It only gives the basic array operations such as slicing.
 */
template <typename ElementType> struct dyn_size_array {
  public:
    /**
     * @brief Default constructor
     */
    constexpr dyn_size_array() noexcept : m_ptr(nullptr), m_size(0) {}

    /**
     * @brief Constructor with data and size
     * @param[in] data Pointer to the data
     * @param[in] size Size of the data
     */
    constexpr dyn_size_array(ElementType* data, oe::usize size) noexcept
        : m_ptr(data), m_size(size) {}

    /**
     * @brief Slice the array
     * @pre start < end && end <= m_size
     * @param[in] start Start index
     * @param[in] end End index
     * @return Sliced array
     */
    constexpr dyn_size_array<ElementType> slice(oe::usize start,
                                                oe::usize end) noexcept {
        OE_ASSERT(start < end && end <= m_size, "Out of bounds");
        return dyn_size_array<ElementType>(m_ptr + start, end - start);
    }

    /**
     * @brief Get the pointer to the data
     * @return Pointer to the data
     */
    constexpr ElementType* ptr() noexcept { return m_ptr; }

    /**
     * @brief Get the const pointer to the data
     * @return Const pointer to the data
     */
    constexpr const ElementType* ptr() const noexcept { return m_ptr; }

    /**
     * @brief Get the size of the array
     * @return Size of the array
     */
    constexpr oe::usize size() const noexcept { return m_size; }

    /**
     * @brief Get the element at the given index
     * @pre index < m_size
     * @param[in] index Index of the element
     * @return Reference to the element
     */
    constexpr ElementType& operator[](oe::usize index) noexcept {
        OE_ASSERT(index < m_size, "Out of bounds");
        return m_ptr[index];
    }

  private:
    ElementType* m_ptr;
    oe::usize m_size;
};
} // namespace oe

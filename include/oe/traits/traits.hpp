/**
 * @file traits.hpp
 * @brief Traits definitions
 * @copyright Copyright (C) 2026 ACoderOrHacker
 */
#pragma once

#include <type_traits>
#include <utility>
#include <oe/oe/idcontact.h>
#include <oe/platforms/language_version.hpp>

namespace oe {
using std::integral_constant;

#if OE_LANGAUGE_CPP_STANDARD_ID >= 2017L
using std::bool_constant;
#endif
using std::false_type;
using std::true_type;

// primary type categories
using std::is_array;
using std::is_class;
using std::is_enum;
using std::is_floating_point;
using std::is_function;
using std::is_integral;
using std::is_lvalue_reference;
using std::is_member_function_pointer;
using std::is_member_object_pointer;
using std::is_null_pointer;
using std::is_pointer;
using std::is_rvalue_reference;
using std::is_union;
using std::is_void;

// composite type categories
using std::is_arithmetic;
using std::is_compound;
using std::is_fundamental;
using std::is_member_pointer;
using std::is_object;
using std::is_reference;
using std::is_scalar;

// type properties
using std::is_abstract;
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2017L
using std::is_aggregate;
#endif
using std::is_const;
using std::is_empty;
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2014L
using std::is_final;
#endif
using std::is_polymorphic;
using std::is_standard_layout;
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2023L
using std::is_implicit_lifetime;
#endif
using std::is_trivially_copyable;
using std::is_volatile;

#if OE_LANGAUGE_CPP_STANDARD_ID >= 2020L
using std::is_bounded_array;
using std::is_unbounded_array;
#endif
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2023L
using std::is_scoped_enum;
#endif
using std::is_signed;

using std::is_unsigned;

using std::is_assignable;
using std::is_constructible;
using std::is_copy_assignable;
using std::is_copy_constructible;
using std::is_default_constructible;
using std::is_destructible;
using std::is_move_assignable;
using std::is_move_constructible;
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2017L
using std::is_swappable;
using std::is_swappable_with;
#endif
using std::is_trivially_assignable;
using std::is_trivially_constructible;
using std::is_trivially_copy_assignable;
using std::is_trivially_copy_constructible;
using std::is_trivially_default_constructible;
using std::is_trivially_destructible;
using std::is_trivially_move_assignable;
using std::is_trivially_move_constructible;

using std::is_nothrow_assignable;
using std::is_nothrow_constructible;
using std::is_nothrow_copy_assignable;
using std::is_nothrow_copy_constructible;
using std::is_nothrow_default_constructible;
using std::is_nothrow_destructible;
using std::is_nothrow_move_assignable;
using std::is_nothrow_move_constructible;
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2017L
using std::is_nothrow_swappable;
using std::is_nothrow_swappable_with;
#endif

using std::has_virtual_destructor;

#if OE_LANGAUGE_CPP_STANDARD_ID >= 2017L
using std::has_unique_object_representations;
#endif

#if OE_LANGAUGE_CPP_STANDARD_ID >= 2023L
using std::reference_constructs_from_temporary;
using std::reference_converts_from_temporary;
#endif
// type property queries
using std::alignment_of;
using std::extent;
using std::rank;

// type relations
using std::is_base_of;
using std::is_convertible;
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2020L
using std::is_layout_compatible;
using std::is_nothrow_convertible;
using std::is_pointer_interconvertible_base_of;
using std::is_pointer_interconvertible_base_of_v;
#endif

using std::is_same;
// NOTE: C++26 traits
// using std::is_virtual_base_of;

#if OE_LANGAUGE_CPP_STANDARD_ID >= 2017L
using std::is_invocable;
using std::is_invocable_r;

using std::is_nothrow_invocable;
using std::is_nothrow_invocable_r;
#endif

// const-volatile modifications
using std::add_const;
using std::add_cv;
using std::add_volatile;
using std::remove_const;
using std::remove_cv;
using std::remove_volatile;

using std::add_const_t;
using std::add_cv_t;
using std::add_volatile_t;
using std::remove_const_t;
using std::remove_cv_t;
using std::remove_volatile_t;

// reference modifications
using std::add_lvalue_reference;
using std::add_rvalue_reference;
using std::remove_reference;

using std::add_lvalue_reference_t;
using std::add_rvalue_reference_t;
using std::remove_reference_t;

// sign modifications
using std::make_signed;
using std::make_unsigned;

using std::make_signed_t;
using std::make_unsigned_t;

// array modifications
using std::remove_all_extents;
using std::remove_extent;

using std::remove_all_extents_t;
using std::remove_extent_t;

// Pointer modifications
using std::add_pointer;
using std::remove_pointer;

using std::add_pointer_t;
using std::remove_pointer_t;

// other transformations
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2020L
using std::basic_common_reference;
using std::common_reference;
#endif
using std::common_type;
using std::conditional;
using std::decay;
using std::enable_if;
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2017L
using std::invoke_result;
using std::invoke_result_t;
using std::void_t;
#endif
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2020L
using std::common_reference_t;
using std::remove_cvref;
using std::remove_cvref_t;
using std::type_identity;
using std::type_identity_t;
using std::unwrap_ref_decay;
using std::unwrap_ref_decay_t;
using std::unwrap_reference;
using std::unwrap_reference_t;
#endif
using std::underlying_type;

using std::common_type_t;
using std::conditional_t;
using std::decay_t;
using std::enable_if_t;
using std::underlying_type_t;

// logical operator traits
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2017L
using std::conjunction;
using std::disjunction;
using std::negation;
#endif

// primary type categories
using std::is_array_v;
using std::is_class_v;
using std::is_enum_v;
using std::is_floating_point_v;
using std::is_function_v;
using std::is_integral_v;
using std::is_lvalue_reference_v;
using std::is_member_function_pointer_v;
using std::is_member_object_pointer_v;
using std::is_null_pointer_v;
using std::is_pointer_v;
using std::is_rvalue_reference_v;
using std::is_union_v;
using std::is_void_v;

// composite type categories
using std::is_arithmetic_v;
using std::is_compound_v;
using std::is_fundamental_v;
using std::is_member_pointer_v;
using std::is_object_v;
using std::is_reference_v;
using std::is_scalar_v;

// type properties
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2017L
using std::has_unique_object_representations_v;
#endif
using std::has_virtual_destructor_v;
using std::is_abstract_v;
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2017L
using std::is_aggregate_v;
#endif
using std::is_assignable_v;
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2020L
using std::is_bounded_array_v;
using std::is_unbounded_array_v;
#endif
using std::is_const_v;
using std::is_constructible_v;
using std::is_copy_assignable_v;
using std::is_copy_constructible_v;
using std::is_default_constructible_v;
using std::is_destructible_v;
using std::is_empty_v;
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2014L
using std::is_final_v;
#endif
using std::is_move_assignable_v;
using std::is_move_constructible_v;
using std::is_nothrow_assignable_v;
using std::is_nothrow_constructible_v;
using std::is_nothrow_copy_assignable_v;
using std::is_nothrow_copy_constructible_v;
using std::is_nothrow_default_constructible_v;
using std::is_nothrow_destructible_v;
using std::is_nothrow_move_assignable_v;
using std::is_nothrow_move_constructible_v;
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2017L
using std::is_nothrow_swappable_v;
using std::is_nothrow_swappable_with_v;
#endif
using std::is_polymorphic_v;
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2023L
using std::is_scoped_enum_v;
#endif
using std::is_signed_v;
using std::is_standard_layout_v;
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2017L
using std::is_swappable_v;
using std::is_swappable_with_v;
#endif
using std::is_trivial_v;
using std::is_trivially_assignable_v;
using std::is_trivially_constructible_v;
using std::is_trivially_copy_assignable_v;
using std::is_trivially_copy_constructible_v;
using std::is_trivially_copyable_v;
using std::is_trivially_default_constructible_v;
using std::is_trivially_destructible_v;
using std::is_trivially_move_assignable_v;
using std::is_trivially_move_constructible_v;
using std::is_unsigned_v;
using std::is_volatile_v;
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2023L
using std::reference_constructs_from_temporary_v;
using std::reference_converts_from_temporary_v;
#endif

// type property queries
using std::alignment_of_v;
using std::extent;
using std::rank_v;

// type relations
using std::is_base_of_v;
using std::is_convertible_v;
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2017L
using std::is_invocable_r_v;
using std::is_invocable_v;
using std::is_nothrow_invocable_r_v;
using std::is_nothrow_invocable_v;
#endif
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2020L
using std::is_layout_compatible_v;
using std::is_nothrow_convertible_v;
#endif
using std::is_same_v;
// NOTE: C++26 traits
// using std::is_virtual_base_of_v;

// logical operator traits
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2017L
using std::conjunction_v;
using std::disjunction_v;
using std::negation_v;
#endif

// member relationships
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2020L
using std::is_corresponding_member;
using std::is_pointer_interconvertible_with_class;
#endif

// constant evaluation context
#if OE_LANGAUGE_CPP_STANDARD_ID >= 2020L
using std::is_constant_evaluated;
#endif
// NOTE: C++26 traits
// using std::is_within_lifetime;

using std::declval;
} // namespace oe

/**
 * @define OE_DEFINE_HAS_MEMBER
 * @brief Macro to define a trait for checking if a type has a member function
 * or field
 * @param member_name The name of the member to check for
 */
#define OE_DEFINE_HAS_MEMBER(trait_name, member_name)                          \
    template <class T, class = void> struct trait_name : oe::false_type {};    \
    template <class T>                                                         \
    struct trait_name<T, oe::void_t<decltype(oe::declval<T>().member_name)>>   \
        : oe::true_type {};                                                    \
    template <class T>                                                         \
    constexpr static bool OE_ID_CONTACT(trait_name, _v) =                      \
        trait_name<T>::value;

/**
 * @define OE_DEFINE_HAS_MEMBER_WITH_TYPE
 * @brief Macro to define a trait for checking if a type has a member with
 * a correct type or field with a specific type
 * @param trait_name The name of the trait to define
 * @param member_name The name of the member to check for
 * @param type The type of the member to check for
 */
#define OE_DEFINE_HAS_MEMBER_WITH_TYPE(trait_name, member_name, type)          \
    template <class T, class = void> struct trait_name : oe::false_type {};    \
    template <class T>                                                         \
    struct trait_name<T, oe::enable_if_t<std::is_same_v<                       \
                             decltype(oe::declval<T>().member_name), type>>>   \
        : oe::true_type {};                                                    \
    template <class T>                                                         \
    constexpr static bool OE_ID_CONTACT(trait_name, _v) =                      \
        trait_name<T>::value;

/**
 * @define OE_DEFINE_HAS_FUNCTION_MEMBER
 * @brief Macro to define a trait for checking if a type has a function member
 * with a given return type and arguments
 * @param trait_name The name of the trait to define
 * @param member_name The name of the function member to check for
 * @param ret The return type of the function member to check for
 * @param ... The argument types of the function member to check for
 */
#define OE_DEFINE_HAS_FUNCTION_MEMBER(trait_name, member_name, ret, ...)       \
    template <class T, class... Args>                                          \
    struct OE_ID_CONTACT(trait_name, _Details) {                               \
      private:                                                                 \
        template <class U>                                                     \
        static auto check(int)                                                 \
            -> decltype(oe::is_same_v<decltype(oe::declval<T>().member_name(   \
                                          oe::declval<Args>()...)),            \
                                      ret>,                                    \
                        oe::true_type());                                      \
        template <class U> static oe::false_type check(...);                   \
                                                                               \
      public:                                                                  \
        enum {                                                                 \
            value = oe::is_same<decltype(check<T>(0)), oe::true_type>::value   \
        };                                                                     \
    };                                                                         \
    template <class T>                                                         \
    using trait_name = OE_ID_CONTACT(trait_name, _Details)<T, __VA_ARGS__>;    \
    template <class T>                                                         \
    constexpr static bool OE_ID_CONTACT(trait_name, _v) =                      \
        trait_name<T>::value;

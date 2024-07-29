#ifndef endian_typedefs_h
#define endian_typedefs_h

#include <cstddef>
#include <type_traits>

namespace endian
{
namespace details
{
template <std::size_t N>
struct uint_by_size
{
};

template <>
struct uint_by_size<1>
{
    using type = std::uint8_t;
};

template <>
struct uint_by_size<2>
{
    using type = std::uint16_t;
};

template <>
struct uint_by_size<4>
{
    using type = std::uint32_t;
};

template <>
struct uint_by_size<8>
{
    using type = std::uint64_t;
};

template <std::size_t N>
using uint_by_size_t = typename uint_by_size<N>::type;

template <typename T>
struct is_uint
    : std::integral_constant<bool,
                             std::is_unsigned_v<T> && !std::is_same_v<T, bool>>
{
};

template <typename T>
inline constexpr bool is_uint_v = is_uint<T>::value;

template <typename T, std::size_t... I>
struct is_sizeof_one_of
    : std::disjunction<std::bool_constant<sizeof(T) == I>...>
{
};

template <typename T, std::size_t... I>
inline constexpr bool is_sizeof_one_of_v = is_sizeof_one_of<T, I...>::value;
}  // namespace details
}  // namespace endian

#endif /* endian_typedefs_h */

#ifndef test_helpers_h
#define test_helpers_h

#include <array>

template <typename T>
struct is_std_array : std::false_type
{
};

template <typename T, std::size_t N>
struct is_std_array<std::array<T, N>> : std::true_type
{
};

template <typename T>
inline constexpr bool is_std_array_v = is_std_array<T>::value;

template <typename T, std::size_t N>
constexpr bool is_equal_arrays(const std::array<T, N>& a1,
                               const std::array<T, N>& a2) noexcept
{
    for (std::size_t i = 0; i < N; ++i)
    {
        if constexpr (is_std_array_v<T>)
        {
            return is_equal_arrays(a1[i], a2[i]);
        }
        else
        {
            if (a1[i] != a2[i])
            {
                return false;
            }
        }
    }
    return true;
}

#endif /* test_helpers_h */

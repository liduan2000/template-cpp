#include <concepts>
#include <type_traits>

template <typename T>
T max1(const T& lhs, const T& rhs) {
    return lhs > rhs ? lhs : rhs;
}

template <typename T1, typename T2>
typename std::conditional<(sizeof(T1) > sizeof(T2)), T1, T2>::type max2(const T1& lhs, const T2& rhs) {
    return lhs > rhs ? lhs : rhs;
}

template <typename T1, typename T2>
typename std::common_type<T1, T2>::type max3(const T1& lhs, const T2& rhs) {
    return lhs > rhs ? lhs : rhs;
}

template <typename T1, typename T2>
auto max4(const T1 lhs, const T2 rhs) {
    return lhs > rhs ? lhs : rhs;
}

// C++20 concepts
template <std::totally_ordered T>
T max5(const T& lhs, const T& rhs) {
    return lhs > rhs ? lhs : rhs;
}

int main() {
    max2(1.1f, 2.2);
    max3(1.1f, 2.2);
    max4(1.1f, 2.2);
    return 0;
}
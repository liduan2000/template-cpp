#include <iostream>
#include <type_traits>
#include <typeinfo>

// C++11: type traits
template <typename T1, typename T2>
typename std::common_type<T1, T2>::type sum1(T1 t, T2 t2) {
    return t + t2;
}

// C++11: auto with decltype
template <typename T1, typename T2>
auto sum2(T1 t1, T2 t2) -> decltype(t1 + t2) {
    return t1 + t2;
}

// C++14: auto
template <typename T1, typename T2>
auto sum3(T1 t1, T2 t2) {
    return t1 + t2;
}

// C++20: concepts
template <typename T>
concept Arithmetic = std::is_arithmetic<T>::value;

Arithmetic auto sum4(Arithmetic auto t1, Arithmetic auto t2) { return t1 + t2; }

int main() {
    std::cout << typeid(sum1(5.5, 5.5)).name() << '\n';    // double
    std::cout << typeid(sum2(5.5, true)).name() << '\n';   // double
    std::cout << typeid(sum3(true, 5.5)).name() << '\n';   // double
    std::cout << typeid(sum4(true, false)).name() << '\n'; // bool

    return 0;
}
#include <iostream>

template <int N>
struct Factorial {
    static int const value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<1> {
    static int const value = 1;
};

int main() {
    std::cout << "Factorial<5>::value: " << Factorial<5>::value << std::endl;
    std::cout << "Factorial<10>::value: " << Factorial<10>::value << std::endl;

    return 0;
}
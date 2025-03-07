#include <iostream>
#include <string>
#include <variant>
#include <vector>

template <typename... Args>
void printSize(Args&&... args) {
    std::cout << sizeof...(Args) << ", " << sizeof...(args) << std::endl;
}

void myPrintf(const char* format) { std::cout << format; }

template <typename T, typename... Args>
void myPrintf(const char* format, T value, Args... args) {
    for (; *format != '\0'; ++format) {
        if (*format == '%') {
            std::cout << value;
            myPrintf(format + 1, args...);
            return;
        }
        std::cout << *format;
    }
}

template <typename... Ts>
struct Overload : Ts... {
    using Ts::operator()...;
};
template <class... Ts>
Overload(Ts...) -> Overload<Ts...>;

void testPrintSize() {
    std::cout << "----testPrintSize----" << std::endl;
    printSize(1, 1.1f, "Hello", false);
}

void testMyPrintf() {
    std::cout << "----testMyPrintf----" << std::endl;
    myPrintf("Hello World!\n");
    myPrintf("% World% %\n", "Hello", '!', 2025);
}

void testOverload() {
    std::cout << "----testOverload----" << std::endl;

    std::vector<std::variant<char, float, double, int, long, long long>> vecVariant1 = {5,    'a',  5.4, 100LL,
                                                                                        200L, 5.5f, 2025};
    auto TypeOfIntegral = Overload{
        [](char) { return "char"; },
        [](int) { return "int"; },
        [](unsigned int) { return "unsigned int"; },
        [](long int) { return "long int"; },
        [](long long int) { return "long long int"; },
        [](auto) { return "unknown type"; },
    };
    for (auto& v : vecVariant1) { std::cout << std::visit(TypeOfIntegral, v) << std::endl; }

    std::vector<std::variant<std::vector<int>, double, std::string>> vecVariant2 = {1.1, std::vector<int>{1, 2, 3},
                                                                                    "Hello"};
    auto DisplayMe = Overload{
        [](std::vector<int>& myVec) {
            for (auto v : myVec) std::cout << v << " ";
            std::cout << std::endl;
        },
        [](auto& arg) { std::cout << arg << std::endl; },
    };

    for (auto& v : vecVariant2) { std::visit(DisplayMe, v); }
}

int main() {
    testPrintSize();

    testMyPrintf();

    testOverload();

    return 0;
}
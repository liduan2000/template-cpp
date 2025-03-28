#include <iostream>
#include <string>

template <typename Derived>
struct Relational {
    friend bool operator>(Derived const& op1, Derived const& op2) { return op2 < op1; }
    friend bool operator==(Derived const& op1, Derived const& op2) { return !(op1 < op2) && !(op2 < op1); }
    friend bool operator!=(Derived const& op1, Derived const& op2) { return (op1 < op2) || (op2 < op1); }
    friend bool operator<=(Derived const& op1, Derived const& op2) { return (op1 < op2) || (op1 == op2); }
    friend bool operator>=(Derived const& op1, Derived const& op2) { return (op1 > op2) || (op1 == op2); }
};

class Apple : public Relational<Apple> {
  public:
    explicit Apple(int s) : size{s} {};
    friend bool operator<(Apple const& a1, Apple const& a2) { return a1.size < a2.size; }

  private:
    int size;
};

class Man : public Relational<Man> {
  public:
    explicit Man(const std::string& n) : name{n} {}
    friend bool operator<(Man const& m1, Man const& m2) { return m1.name < m2.name; }

  private:
    std::string name;
};

int main() {
    Apple apple1{5};
    Apple apple2{10};
    std::cout << "apple1 < apple2: " << (apple1 < apple2) << std::endl;
    std::cout << "apple1 > apple2: " << (apple1 > apple2) << std::endl;
    std::cout << "apple1 == apple2: " << (apple1 == apple2) << std::endl;
    std::cout << "apple1 != apple2: " << (apple1 != apple2) << std::endl;
    std::cout << "apple1 <= apple2: " << (apple1 <= apple2) << std::endl;
    std::cout << "apple1 >= apple2: " << (apple1 >= apple2) << std::endl;

    std::cout << std::endl;

    Man man1{"John"};
    Man man2{"Ben"};
    std::cout << "man1 < man2: " << (man1 < man2) << std::endl;
    std::cout << "man1 > man2: " << (man1 > man2) << std::endl;
    std::cout << "man1 == man2: " << (man1 == man2) << std::endl;
    std::cout << "man1 != man2: " << (man1 != man2) << std::endl;
    std::cout << "man1 <= man2: " << (man1 <= man2) << std::endl;
    std::cout << "man1 >= man2: " << (man1 >= man2) << std::endl;

    return 0;
}
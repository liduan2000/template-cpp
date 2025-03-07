#include <algorithm>
#include <concepts>
#include <cstddef>
#include <iostream>

template <typename T, std::size_t N>
class Array {
  public:
    std::size_t size() const { return N; }

    template <typename U>
    Array<T, N>& operator=(const Array<U, N>& arr)
        requires std::convertible_to<U, T> // C++20 concepts
    {
        std::copy(std::begin(arr.elements_), std::end(arr.elements_), std::begin(elements_));
        return *this;
    }

    template <typename, std::size_t>
    friend class Array;

  private:
    T elements_[N];
};

void testArray() {
    Array<float, 5> float5;
    std::cout << float5.size() << std::endl;

    Array<double, 5> double5;
    std::cout << double5.size() << std::endl;

    float5 = double5;
}

template <typename T>
class Base {
  public:
    void func1() const { std::cout << "func1()" << std::endl; }
    void func2() const { std::cout << "func2()" << std::endl; }
    void func3() const { std::cout << "func3()" << std::endl; }
    virtual void vfunc() const { std::cout << "Base::vfunc()" << std::endl; }
};

template <typename T>
class Derived : public Base<T> {
  public:
    using Base<T>::func2;
    void callAllBaseFunctions() {
        this->func1();
        func2();
        Base<T>::func3();
    }

    void vfunc() const override { std::cout << "Derived::vfunc()" << std::endl; }
};

void testPolymorphic() {
    Derived<int> derived1;
    derived1.callAllBaseFunctions();
    Base<int>* derived2 = new Derived<int>;
    derived2->vfunc();
    delete derived2;
}

int main() {
    testArray();
    testPolymorphic();
    return 0;
}
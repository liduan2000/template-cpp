#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Object {
  public:
    template <typename T>
    Object(T&& obj) : object(std::make_shared<Model<T>>(std::forward<T>(obj))) {}

    std::string getName() const { return object->getName(); }

    struct Concept {
        virtual ~Concept() {}
        virtual std::string getName() const = 0;
    };

    template <typename T>
    struct Model : Concept {
        Model(const T& t) : object(t) {}
        std::string getName() const override { return object.getName(); }

      private:
        T object;
    };

    std::shared_ptr<const Concept> object;
};

void printName(std::vector<Object>& v) {
    for (auto o : v) std::cout << o.getName() << std::endl;
}

struct Bar {
    std::string getName() const { return "Bar"; }
};

struct Foo {
    std::string getName() const { return "Foo"; }
};

int main() {
    std::vector<Object> v{Object(Foo()), Object(Bar())};

    printName(v);

    return 0;
}
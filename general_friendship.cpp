#include <iostream>

template <typename T>
void myFriendFunction(T);

template <typename U>
class MyFriend;

class GrantingFriendshipAsClass {
    template <typename U>
    friend void myFriendFunction(U);
    template <typename U>
    friend class MyFriend;

    std::string secret{"Secret from GrantingFriendshipAsClass."};
};

template <typename T>
class GrantingFriendshipAsClassTemplate {
    template <typename U>
    friend void myFriendFunction(U);
    template <typename U>
    friend class MyFriend;

    std::string secret{"Secret from GrantingFriendshipAsClassTemplate."};
};

template <typename T>
void myFriendFunction(T) {
    GrantingFriendshipAsClass myFriend;
    std::cout << myFriend.secret << std::endl;

    GrantingFriendshipAsClassTemplate<double> myFriend1;
    std::cout << myFriend1.secret << std::endl;
}

template <typename T>
class MyFriend {
  public:
    MyFriend() {
        GrantingFriendshipAsClass myFriend;
        std::cout << myFriend.secret << std::endl;

        GrantingFriendshipAsClassTemplate<T> myFriend1;
        std::cout << myFriend1.secret << std::endl;
    }
};

int main() {
    int a{2011};
    myFriendFunction(a);

    MyFriend<double> myFriend;

    return 0;
}
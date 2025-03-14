#include <fstream>
#include <iostream>
#include <string>

template <typename OutputPolicy>
class Message : private OutputPolicy {
  public:
    void write(const std::string& mess) const { print(mess); }

  private:
    using OutputPolicy::print;
};

class WriteToCout {
  protected:
    void print(const std::string& message) const { std::cout << message << std::endl; }
};

class WriteToFile {
  protected:
    void print(const std::string& message) const {
        std::ofstream myFile;
        myFile.open("policyInheritance.txt");
        myFile << message << std::endl;
    }
};

int main() {
    Message<WriteToCout> messageCout;
    messageCout.write("Hello world");

    Message<WriteToFile> messageFile;
    messageFile.write("Hello world");

    return 0;
}
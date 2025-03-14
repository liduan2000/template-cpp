#include <fstream>
#include <iostream>
#include <string>

template <typename OutputPolicy>
class Message {
  public:
    void write(const std::string& mess) const { outPolicy.print(mess); }

  private:
    OutputPolicy outPolicy;
};

class WriteToCout {
  public:
    void print(const std::string& message) const { std::cout << message << std::endl; }
};

class WriteToFile {
  public:
    void print(const std::string& message) const {
        std::ofstream myFile;
        myFile.open("policyComposition.txt");
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
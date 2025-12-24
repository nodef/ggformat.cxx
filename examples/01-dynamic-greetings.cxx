// Dynamic greetings with multiple placeholders
#define GGFORMAT_IMPLEMENTATION
#include <ggformat.h>
#include <iostream>
#include <string>


int main() {
  char buffer[256];
  std::string name = "Alice";
  int age = 30;
  double height = 5.7;

  size_t len = ggformat(buffer, sizeof(buffer),
                        "Hello, {}! You are {} years old and {} feet tall.",
                        name.c_str(), age, height);
  std::cout << "Formatted string: " << buffer << "\n";
  std::cout << "Length of formatted string: " << len << "\n";

  return 0;
}

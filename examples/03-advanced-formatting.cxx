// Advanced formatting options
#define GGFORMAT_IMPLEMENTATION
#include <ggformat.h>
#include <iostream>


int main() {
  char buffer[128];
  FormatOpts opts;

  // Example 1: Precision and width
  opts.width = 10;
  opts.precision = 2;
  ggformat(buffer, sizeof(buffer), "{:10.2f}", 123.456);
  std::cout << "Formatted with precision and width: " << buffer << "\n";

  // Example 2: Zero padding
  opts.zero_pad = true;
  opts.width = 8;
  ggformat(buffer, sizeof(buffer), "{:08}", 42);
  std::cout << "Formatted with zero padding: " << buffer << "\n";

  // Example 3: Hexadecimal with alignment
  opts.left_align = false;
  ggformat(buffer, sizeof(buffer), "{:x}", 255);
  std::cout << "Formatted as hexadecimal: " << buffer << "\n";

  return 0;
}

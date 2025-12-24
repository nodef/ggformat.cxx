// File output and error handling
#define GGFORMAT_IMPLEMENTATION
#include <cstdio>
#include <ggformat.h>


int main() {
  FILE *file = fopen("output.txt", "w");
  if (!file) {
    ggprint("Failed to open file for writing.\n");
    return 1;
  }

  if (!ggprint_to_file(file, "The answer is {}\n", 42)) {
    ggprint("Failed to write to file.\n");
    fclose(file);
    return 1;
  }

  ggprint("Successfully wrote to file.\n");
  fclose(file);
  return 0;
}

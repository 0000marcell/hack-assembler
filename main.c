#include <stdio.h>

int main() {
  FILE *file = fopen("./add/Add.asm", "r");
  char currentline[100];

  while (fgets(currentline, sizeof(currentline), file) != NULL) {
    fprintf(stderr, "got line: %s\n", currentline);
  }

  fclose(file);
}

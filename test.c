#include <stdio.h>
#include <string.h>
#include "parser.h"

void test(char str[6]) {
  char *comp = strtok(str, ";");
  printf("d: %s\n", comp);
}


int main() {
  char str[6] = "0;JMP"; 
  printf("%s", str);
  test(str);
}



#include <stdio.h>
#include "parser.h"

int main() {
  char str[256] = "0;JMP"; 
  printf("testing!!!");
  char *result = parse(str);
  printf("%s", result);
}



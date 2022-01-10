#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../parser.h"


int main() {
  char str[256] = "0;JMP"; 
  char test_result[] = "1110101010000111";
  printf("running tests...\n");
  char *result = parse(str);
  printf("r: %s t: %s \n", result, test_result);
  printf("%d\n", strcmp(result, test_result));
  assert(strcmp(result, test_result) == 1);
  return 0;
}

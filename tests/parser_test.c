#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../parser.h"

void test(char desc[], char op[], char bin[]) {
  printf("%s\n", desc);
  char op1[20];
  strcpy(op1, op);
  char *result = parse(op1);
  printf("result: %s\n", result);
  printf("bin: %s\n", bin);
  assert(strcmp(result, bin) == 0);
}

int main() {
  printf("running tests...\n");
  /* test(">>>> 0;JMP", "0;JMP", "1110101010000111"); */
  /* test(">>>> @2", "@2", "1000000000000010"); */
  /* test(">>>> @0", "@0", "1000000000000000"); */
  /* test(">>>> @3", "@3", "1000000000000011"); */
  /* test(">>>> @16", "@16", "1000000000010000"); */
  test(">>>> D=M", "D=M", "1111110000010000");
  return 0;
}

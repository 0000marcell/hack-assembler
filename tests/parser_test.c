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
  test(">>>> 0;JMP", "0;JMP", "1110101010000111");
  test(">>>> @2", "@2", "0000000000000010");
  test(">>>> @0", "@0", "0000000000000000");
  test(">>>> @3", "@3", "0000000000000011");
  test(">>>> @16", "@16", "0000000000010000");
  test(">>>> D=M", "D=M", "1111110000010000");
  test(">>>> D=D-M", "D=D-M", "1111010011010000");
  test(">>>> D;JGT", "D=D-M", "1111010011010000");
  test(">>>> D;JGT", "D;JGT", "1110001100000001");
  return 0;
}

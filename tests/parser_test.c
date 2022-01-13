#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../parser.h"

void test(char desc[], char op[], char bin[]) {
  printf("%s\n", desc);
  char op1[20];
  strcpy(op1, op);
  char *result = parse(op1);
  assert(strcmp(result, bin) == 0);
}

int main() {
  printf("running tests...\n");
  test(">>>> 0;JMP", "0;JMP", "1110101010000111");
  test(">>>> @0", "@0", "1000000000000000");
  return 0;
}

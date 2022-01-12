#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../parser.h"

void test(char desc[], char op[], char bin[]) {
  printf("%s\n", desc);
  /* printf("op: %s\n", op); */
  char *result = parse(op);
  assert(strcmp(result, bin) == 0);
}

int main() {
  printf("running tests...\n");
  test(">>>> 0;JMP", "0;JMP", "1110101010000111");
  /* printf("r: %s t: %s \n", comp_val, test_result); */
  /* printf("%d\n", strcmp(comp_val, test_result)); */
  //assert(strcmp(result, test_result) == 0);
  return 0;
}

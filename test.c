#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isNumber(char s[]) {
  for(int i = 0; s[i]!= '\0'; i++) {
    if(isdigit(s[i]) == 0)
      return 0;
  }
  return 1;
}


int main() {
  char *m = "23";
  if(isNumber(m)) {
    printf("true"); 
  }
}



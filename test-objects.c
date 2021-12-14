#include <stdio.h>
#include <string.h>

typedef struct {
  char* key;
  int value;
} item;

struct orderSlip
{
    char source[64];
    char destination[64];
    char item[64];  
    int position;
};


int main() {
  struct orderSlip x = {"sour", "dest", "item", 5};
  //printf("%s", x.destination);
  struct orderSlip* p[5];
  int i = 0;
  while(i < 3) {
    char str[10];
    sprintf(str, "%d", i);
    strcat(str, "item");
    printf("%s", str);
    struct orderSlip x = {"sour", "dest", *str, 5};
    p[i] = &x;  
    i++; 
  }
  printf("%s", p[0]->item);
}

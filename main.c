#include <stdio.h>

typedef struct {
  char* key;
  int value;
} item;

item* init_hash_table() {
  int i = 0;
  item* items[100];
  while(i < 5) {
    item x = {"R0", 0}; 
    items[i] = &x;
  }
  return items;    
};

int main() {
  item* i = init_hash_table();
  printf("%s", i[0].key);
  /* FILE *file = fopen("./add/Add.asm", "r"); */
  /* char currentline[100]; */

  /* while (fgets(currentline, sizeof(currentline), file) != NULL) { */
  /*   fprintf(stderr, "got line: %s\n", currentline); */
  /* } */

  /* fclose(file); */
}

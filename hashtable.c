#include <stdio.h>
#include <string.h>

typedef struct {
    char* key;
    int value;
} item;

item* linear_search(item* items, int size, const char* key) {
  for (int i=0; i<size; i++) {
      if (strcmp(items[i].key, key) == 0) {
          return &items[i];
      }
  }
  return 0;
}

int main(void) {
  // Loading the predefined symbol table
  item items[] = {
      {"R0", 0}, {"R1", 1}, {"R2", 2}, {"R3", 3},
      {"bob", 11}, {"jane", 100}, {"x", 200}};
  int num_items = sizeof(items) / sizeof(item);

  item* found = linear_search(items, num_items, "bob");
  if (!found) {
      return 1;
  }
  printf("linear_search: value of 'bob' is %d\n", found->value);
  return 0;
}

#include <stdio.h>
#include <string.h>

typedef struct {
  char* key;
  int value;
} item;

int main() {
  item symbols[100] = {{"R0", 0}, {"R1", 1}, 
    {"R2", 2}, {"R3", 3}, {"R4", 4}, {"R5", 5}, {"R6", 6}, {"R7", 7},
    {"R8", 8}, {"R9", 9}, {"R10", 10}, {"R11", 11}, {"R12", 12}, {"R13", 13},
    {"R14", 14}, {"R15", 15}, {"SCREEN", 16384}, {"KBD", 24576}, {"SP", 0},
    {"LCL", 1}, {"ARG", 2}, {"THIS", 3}, {"THAT", 4}};

  FILE *file = fopen("./max/Max.asm", "r");
  char currentline[100];
  int current_table_index = 23;
  int line_number = 0;

  while (fgets(currentline, sizeof(currentline), file) != NULL) {
    fprintf(stderr, "got line: %s\n", currentline);
    char line[256]; 
    char *subString; 

    strcpy(line, currentline);

    if (line[0] == '(') {
      subString = strtok(&line[1],")");   // find the second double quote
      item new = { subString, line_number};
      symbols[current_table_index] = new; 
      printf("the thing in between quotes is '%s'\n", subString);
    }

    if(currentline[0] != '/' && NOT_BLANK) {
      line_number++;
    }
  }

  fclose(file);
}

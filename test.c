#include <stdio.h>
#include <string.h>

typedef struct {
  char *key;
  int value;
} item;

static void insert(item *p, char *key, int value) {
  p->key = key;
  p->value = value;
}

int is_empty(char * currentline) {
  char c = 'a';
  int i = 0;
  int all_blank = 1;
  int prev_char_comment = 0;
  int e;
  while (c != '\n'){
    c = currentline[i];
    // print ascii value
    //scanf("%c",&c);
    //e=c;
    //printf("\n%d",e);
    if(c == '/') {
      if(prev_char_comment) {
        all_blank = 1;
        break;
      }
      prev_char_comment = 1;
    } else {
      prev_char_comment = 0;
      if(c != ' ' && c != '\0' && c != '\n' && c != '\r') {
        all_blank = 0; 
        break;
      }
    }
    i++;
  }
  return all_blank;
}

int main() {
  item symbols[100] = {{"R0", 0}, {"R1", 1}, 
    {"R2", 2}, {"R3", 3}, {"R4", 4}, {"R5", 5}, {"R6", 6}, {"R7", 7},
    {"R8", 8}, {"R9", 9}, {"R10", 10}, {"R11", 11}, {"R12", 12}, {"R13", 13},
    {"R14", 14}, {"R15", 15}, {"SCREEN", 16384}, {"KBD", 24576}, {"SP", 0},
    {"LCL", 1}, {"ARG", 2}, {"THIS", 3}, {"THAT", 4}};
  FILE *file = fopen("./testfile", "r");
  char currentline[100];
  int current_table_index = 23;
  int variable_start_index = 16;
  int line_number = 0;

  while (fgets(currentline, sizeof(currentline), file) != NULL) {
    if(!is_empty(currentline)) {
      // JUMP SYMBOLS
      //printf("%s\n", currentline);
      if (currentline[0] == '(') {
        char line[256]; 
        strcpy(line, currentline);
        //printf("%s\n", line);
        char *subString;
        subString = strtok(&line[1],")");   // find the second double quote
        symbols[current_table_index].key = subString;
        symbols[current_table_index].value = line_number;
        //insert(&symbols[current_table_index],  subString, line_number);
        //printf("symbol %s on line %d cti: %d\n", subString, line_number, current_table_index);
        current_table_index++;
      }
      line_number++;
    }
  }

  for(int i = 0; i < current_table_index; i++) {
    printf("k: %s v: %d\n", symbols[i].key, symbols[i].value);
  }

  fclose(file);
}
 

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

typedef struct {
  char *key;
  int value;
} item;

int is_empty(char * currentline) {
  char c = 'a';
  int i = 0;
  int all_blank = 1;
  int prev_char_comment = 0;
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

item symbols[100] = {{"R0", 0}, {"R1", 1}, 
    {"R2", 2}, {"R3", 3}, {"R4", 4}, {"R5", 5}, {"R6", 6}, {"R7", 7},
    {"R8", 8}, {"R9", 9}, {"R10", 10}, {"R11", 11}, {"R12", 12}, {"R13", 13},
    {"R14", 14}, {"R15", 15}, {"SCREEN", 16384}, {"KBD", 24576}, {"SP", 0},
    {"LCL", 1}, {"ARG", 2}, {"THIS", 3}, {"THAT", 4}};

int current_table_index = 23;

int find_symbol(char key[]) {
  int val = -1;
  for(int i = 0; i < current_table_index; i++) {
    //printf("%s == %s\n", subString, symbols[i].key); 
    //printf(">> %d\n", strcmp(symbols[i].key, subString)); 
    if(strcmp(symbols[i].key, key) == 0) {
      val = symbols[i].value;
      break;
    }
  }
  return val; 
}

int main() {
  FILE *file = fopen("./testfile", "r");
  char currentline[256];
  int variable_start_index = 16;
  int line_number = 0;
  char *file_lines[256];

  while (fgets(currentline, sizeof(currentline), file) != NULL) {
    // JUMP SYMBOLS
    if(!is_empty(currentline)) {
      file_lines[line_number] = strdup(currentline);
      if (currentline[0] == '(') {
        char line[256]; 
        strcpy(line, currentline);
        char *subString = strtok(&line[1],")");   // find the second double quote
        // check if subString is a number, if it's it doesn't need to be added
        symbols[current_table_index].key = strdup(subString);
        symbols[current_table_index].value = line_number;
        current_table_index++;
      }
      line_number++;
    }
  }

  // VARIABLES
  for(int i = 0; i < line_number; i++) {
    char * ptr;
    int ch = '@';
    ptr = strchr(file_lines[i], ch);
    if(ptr) {
      char *subString = strtok(&ptr[1], "\r"); 
      subString = strtok(subString, "\n"); 
      subString = strtok(subString, " "); 
      //printf("%c %d", subString[2], subString[2]);
      int is_already_on_table = 0;
      for(int i = 0; i < current_table_index; i++) {
        //printf("%s == %s\n", subString, symbols[i].key); 
        //printf(">> %d\n", strcmp(symbols[i].key, subString)); 
        if(strcmp(symbols[i].key, subString) == 0) {
          //printf("found!\n");
          is_already_on_table = 1;
          break;
        }
      }

      if(!is_already_on_table && !isNumber(subString)) {
        //printf("subString: %s vsi: %d\n", subString, variable_start_index);
        symbols[current_table_index].key = strdup(subString);
        symbols[current_table_index].value = variable_start_index;
        variable_start_index++;
        current_table_index++;
      }
    }
  }

  // Print symbols table
  /* for(int i = 0; i < current_table_index; i++) { */
  /*   printf("k: %s v: %d\n", symbols[i].key, symbols[i].value); */
  /* } */

  // transform everything
  for(int i = 0; i < line_number; i++) {
    char *line = file_lines[i];
    if(strstr(line, "@") != NULL) {
      char *a = strtok(line, "@"); 
      a = strtok(NULL, "\0"); 
      int val = find_symbol(a);
      printf("val: %d\n", val);
    }
  }

  fclose(file);
}

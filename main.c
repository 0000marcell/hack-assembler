#include <stdio.h>
#include <string.h>

typedef struct {
  char *key;
  int value;
} item;

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

static void insert(item *p, char *key, int value)
{
    p->key = key;
    p->value = value;
}

int main() {
  item symbols[100] = {{"R0", 0}, {"R1", 1}, 
    {"R2", 2}, {"R3", 3}, {"R4", 4}, {"R5", 5}, {"R6", 6}, {"R7", 7},
    {"R8", 8}, {"R9", 9}, {"R10", 10}, {"R11", 11}, {"R12", 12}, {"R13", 13},
    {"R14", 14}, {"R15", 15}, {"SCREEN", 16384}, {"KBD", 24576}, {"SP", 0},
    {"LCL", 1}, {"ARG", 2}, {"THIS", 3}, {"THAT", 4}};

  FILE *file = fopen("./testfile", "r");
  char *currentline;
  int current_table_index = 23;
  int variable_start_index = 16;
  int line_number = 0;

  while (fgets(currentline, sizeof(currentline), file) != NULL) {
    if(!is_empty(currentline)) {
      // JUMP SYMBOLS
      if (currentline[0] == '(') {
        char line[256]; 
        strcpy(line, currentline);
        printf("%s\n", line);
        char subString;
        subString[0] = strtok(&line[1],")");   // find the second double quote
        insert(&symbols[current_table_index],  subString, line_number);
        printf("symbol %s on line %d cti: %d\n", subString, line_number, current_table_index);
        current_table_index++;
      }
      line_number++;
      //printf("is not empty!\n");
      // VARIABLES 
      //char * ptr;
      //int    ch = '@';
      //ptr = strchr(currentline, ch);
      //if(ptr) {
        //char *subString = strtok(&ptr[1], "\r"); 
        //printf("%c %d", subString[2], subString[2]);
        //int is_already_on_table = 0;
        //for(int i = 0; i < current_table_index; i++) {
          //printf("%s == %s\n", subString, symbols[i].key);
          //printf(">> %d\n", strcmp(symbols[i].key, subString));
          //if(strcmp(symbols[i].key, subString) == 0) {
            //printf("found!\n");
            //is_already_on_table = 1;
            //break;
          //}
        //}

        //if(!is_already_on_table) {
          //printf("subString: %s vsi: %d\n", subString, variable_start_index);
          //item n = { subString, variable_start_index };
          //symbols[current_table_index] = n;
          //variable_start_index++;
          //current_table_index++;
        //}
      //}

      
    }
  }

  printf("k: %s v: %d\n", symbols[23].key, symbols[23].value);
  printf("k: %s v: %d\n", symbols[24].key, symbols[24].value);
  printf("k: %s v: %d\n", symbols[25].key, symbols[25].value);

  /* for(int i = 0; i < current_table_index; i++) { */
  /*   printf("k: %s v: %d\n", symbols[i].key, symbols[i].value); */
  /*   i++; */
  /* } */

  fclose(file);
}

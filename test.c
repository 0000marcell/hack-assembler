#include <stdio.h>
#include <string.h>
 
#define SIZE 40

typedef struct {
  char* key;
  int value;
} item;
 
int main(void)
{
  

  item symbols[100] = {{"R0", 0}, {"R1", 1}, 
    {"R2", 2}, {"R3", 3}, {"R4", 4}, {"R5", 5}, {"R6", 6}, {"R7", 7},
    {"R8", 8}, {"R9", 9}, {"R10", 10}, {"R11", 11}, {"R12", 12}, {"R13", 13},
    {"R14", 14}, {"R15", 15}, {"SCREEN", 16384}, {"KBD", 24576}, {"SP", 0},
    {"LCL", 1}, {"ARG", 2}, {"THIS", 3}, {"THAT", 4}};

  int current_table_index = 23;
  int variable_start_index = 16;
  char buffer1[SIZE] = "        @R1";
  char * ptr;
  int    ch = '@';
  ptr = strchr( buffer1, ch );
  if(ptr) {
    char *subString; 
    subString = strtok(&ptr[1],"\0");   // find the second double quote
    int is_already_on_table = 0;
    for(int i = 0; i < current_table_index; i++) {
      printf("%s == %s\n", subString, symbols[i].key);
      if(strcmp(symbols[i].key, subString)) {
        printf("found!");
        is_already_on_table = 1;
        break;
      }
    }

    if(!is_already_on_table) {
      item new = { subString, variable_start_index };
      symbols[current_table_index] = new;
      variable_start_index++;
      current_table_index++;
    }
  }
  
  
  // I need to grab the value see if it exists on the hash table, if it doesn't
  // I need to include it

  //printf( "The first occurrence of %c in '%s' is '%s'\n", ch, buffer1, ptr );
}
 
/*****************  Output should be similar to:  *****************
 
The first occurrence of p in 'computer program' is 'puter program'
*/

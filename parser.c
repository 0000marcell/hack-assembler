#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"

// destination computation and jump
// dest = comp; jump
// binary syntax
//
// 111accccccdddjjj
//
// let's break down the things that I have to do
// first the dest
// I can find the dest by finding a equals symbol and 
// breaking down the code there, if there's a equals symbol I get
// what I have before the symbol, then I translate to the dest
//
typedef struct {
  char *key;
  char *value;
} item;
// for the comp instruction I'm going to put the 
// a == 0 and a == 1 thing in the beggining of the string
const item comp[100] = {
  {"0",  "0101010"}, 
  {"1",  "0111111"},
  {"-1", "0111010"},
  {"D",  "0001100"},
  {"A",  "0100000"},
  {"!D", "0001101"},
  {"!A", "0110001"},
  {"-D", "0001111"},
  {"-A", "0110011"},
  {"D+1","0011111"},
  {"A+1","0110111"},
  {"D-1","0001110"},
  {"A-1","0110010"},
  {"D+A","0000010"},
  {"A-D","0000111"},
  {"D&A","0000000"},
  {"D|A","0010101"},
  {"M",  "1110000"},
  {"!M", "1110001"},
  {"-M", "1110011"},
  {"M+1","1110111"},
  {"M-1","1110010"},
  {"D+M","1000010"},
  {"D-M","1010011"},
  {"M-D","1000111"},
  {"D&M","1000000"},
  {"D|M","1010101"}
};


const item dest[100] = {
  {"null","000"},
  {"M",   "001"},
  {"D",   "010"},
  {"DM",  "011"},
  {"A",   "100"},
  {"AM",  "101"},
  {"AD",  "110"},
  {"ADM", "111"}
};

const item jump[100] = {
  {"null", "000"},
  {"JGT",  "001"},
  {"JEQ",  "010"},
  {"JGE",  "011"},
  {"JLT",  "100"},
  {"JNE",  "101"},
  {"JLE",  "110"},
  {"JMP",  "111"}
};

char * to_binary(int n) {
  int a[10], i;    
  for(i=0;n>0;i++) {    
    a[i]=n%2;    
    n=n/2;    
  }    

  char str[2] = "";
  char r[17] = "";
  int j = 0;
  for(i=i-1;i>=0;i--) {    
    sprintf(str, "%d", a[i]);
    r[j] = *strdup(str);
    j++;
  }

  int z = 16 - strlen(r);
  printf("z: %d\n", z);
  char zpad[17] = "1";
  for(i = 1; i < z; i++) {
    zpad[i] = '0';
  }
  char concat[17] = "";
  /* printf("zpad: %s\n", zpad); */
  /* printf("r: %s\n", r); */
  sprintf(concat, "%s%s", zpad, r);
  //printf("concat: %s\n", concat);
  char *ret = &concat[0];
  return ret;
}

char * translate(char *key, char type[]) {
  if(strcmp(type, "jump") == 0) {
    for(int i = 0; i < 8; i++) {
      if(strcmp(key, jump[i].key) == 0) {
        return jump[i].value;
      }
    }
  }

  if(strcmp(type, "comp") == 0) {
    for(int i = 0; i < 27; i++) {
      if(strcmp(key, comp[i].key) == 0) {
        return comp[i].value;
      }
    }
  }

  if(strcmp(type, "dest") == 0) {
    for(int i = 0; i < 8; i++) {
      if(strcmp(key, dest[i].key) == 0) {
        return dest[i].value;
      }
    }
  }

  return "null";
}

char result[1280] = "";

char * parse(char str[20]) {
  char b_start[] = "111";
  char *dest = "", *comp = "", *jump = "";
  if(strstr(str, "@") != NULL) {
    char *s = strtok(str, "@");
    char *val = strtok(s, "\0");
    printf("val: %s\n", val);
    int n = atoi(val);
    printf("number: %d\n", n);
    comp = to_binary(n);
    return comp;
  }
  if(strstr(str, "=") != NULL) {
    dest = strtok(str, "=");
  } else {
    dest = translate("null", "dest");
  }
  if(strstr(str, ";") != NULL) {
    comp = strtok(str, ";");
    jump = strtok(NULL, "\0");
    comp = translate(comp, "comp");
    jump = translate(jump, "jump");
  }
  char r_comp[256] = "", r_dest[256] = "", r_jump[256] = "";
  strncpy(r_dest, dest, 256);
  strncpy(r_comp, comp, 256);
  strncpy(r_jump, jump, 256);
  sprintf(result,"%s%s%s%s", b_start, r_comp, r_dest, r_jump);
  char *b = result;
  return b;
}

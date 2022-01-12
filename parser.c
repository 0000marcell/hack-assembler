#include <stdio.h>
#include <string.h>
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

char * parse(char str[]) {
  char b_start[] = "111";
  char *dest = "", *comp = "", *jump = "";
  printf("here!!!\n");
  if(strstr(str, "=") != NULL) {
    dest = strtok(str, "=");
  } else {
    dest = translate("null", "dest");
  }
  printf("here!!!\n");
  if(strstr(str, ";") != NULL) {
    printf("here if!!!\n");
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

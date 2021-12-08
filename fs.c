#include <stdio.h>

// I want one function that is going to return the next line of text 
// everytime is called

int main() {
  FILE *file = fopen("./add/Add.asm", "r");
  char currentline[100];

  while (fgets(currentline, sizeof(currentline), file) != NULL) {
    fprintf(stderr, "got line: %s\n", currentline);
    /* Do something with `currentline` */
  }

  fclose(file);
  /* int i = 0; */
  /* while(i < 14) { */
  /*   fs_read_line("./add/Add.asm"); */
  /*   printf("2: %s\n", fs_buff); */
  /*   i++; */
  /* } */
  /* fclose(fs_fp); */
}

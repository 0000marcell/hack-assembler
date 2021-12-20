#include <stdio.h>
#include <string.h>
 
#define SIZE 40

typedef struct {
  char* key;
  int value;
} item;
 
int main(void)
{
  char c = 'a'; // or whatever your character is
  printf("%c %d", c, c);
}
 
/*****************  Output should be similar to:  *****************
 
The first occurrence of p in 'computer program' is 'puter program'
*/

#include<stdio.h>    
#include<stdlib.h>  
#include<string.h>  

char * to_binary(int n) {
  int a[10], i;    
  for(i=0;n>0;i++) {    
    a[i]=n%2;    
    printf("mod: %d\n", a[i]);
    n=n/2;    
  }    

  char str[2];
  char r[17];
  int j = 0;
  for(i=i-1;i>=0;i--) {    
    sprintf(str, "%d", a[i]);
    r[j] = *strdup(str);
    j++;
  }

  int z = 15 - strlen(r);
  printf("z: %d\n", z);
  char zpad[z] = "";
  for(i = 0; i < z; i++) {
    zpad[i] = '0';
  }
  printf("zpad: %s\n", zpad);
  char concat[17];
  sprintf(concat, "%s%s", zpad, r);
  printf("concat: %s\n", concat);
  char *ret = &r[0];
  return ret;
}

int main(){  
  char *r = to_binary(2);  
  printf("result: %s\n", r);
}



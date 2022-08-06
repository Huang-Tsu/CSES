#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char input;
  int long_len = 1;
  int len = 1;
  char chr = 'Z';

  while( (input=getchar()) != EOF){
    if(input != chr){
      chr = input;
      len = 1;
    }
    else{
      len ++;
      if(len > long_len){
        long_len = len;
      }
    }
  }
  printf("%d\n", long_len);
  return 0;
}

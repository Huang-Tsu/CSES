#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void PrintCode(int code, int n){
  for(int i=n-1; i>=0; i--){
    if((1<<i)&code){
      printf("1");
    }
    else{
      printf("0");
    }
  }
  puts("");
}
int main(){
  int code = 0;
  int n, total;
  int lowbit;

  scanf("%d", &n);
  total = pow(2, n);

  PrintCode(code, n);
  for(int i=1; i<total; i++){
    if(i & 1){  //odd
      if(code&1)  //complement first bit
        code -= 1;
      else
        code += 1;

      PrintCode(code, n);
    }
    else{
      lowbit = code & -code; 
      lowbit <<= 1;
      if(code & lowbit) //complement lowbit-th bit
        code -= lowbit;
      else
        code += lowbit;

      PrintCode(code, n);
    }
  }
  return 0;
}

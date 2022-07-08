#include <stdio.h>
#define MAX ((long long)1e9+7)

long long dp[(int)1e6+1];

int main(){
  int n;
  long long output = 2;
  int counter = 1;
  
  scanf("%d", &n);
  n -= 1;
  while(n != 0){
    //printf("n:%d\n", n);
    //printf("counter:%d\n", counter);
    if(!dp[counter]){
      dp[counter] = output;
        //printf("dp[%d]:%lld\n", counter, dp[counter]);
    }
    output *= dp[counter];
    n -= counter;

    if(counter<<1 > n) counter = 1;
    else counter <<= 1;

    if(output >= MAX)
      output %= MAX;

  }

  printf("%lld\n", output);
}

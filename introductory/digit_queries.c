#include <stdio.h>
#include <math.h>
#include <string.h>

long long my_pow(long long a, long long b){
  long long sum = 1;
  for(int i=1; i<=b; i++){
    sum *= a;
  }
  return sum;
}
int main(){
  unsigned long long q, k;
  unsigned long long times;
  unsigned long long total;
  unsigned long long num, rest, remain;
  char num_chr[32];

  scanf("%lld", &q);
  for(int i=0; i<q; i++){
    times = 2;
    total = 9;
    scanf("%lld", &k);
    if(k<10){
      printf("%lld\n", k);
      continue;
    }
    while(total+times*9*my_pow(10, times-1) < k){
      total += times*9*my_pow(10, times-1);
      times ++;
    }

    rest = k-(total+1);
    num = my_pow(10, times-1) + rest/times;
    remain = rest%(times);

    sprintf(num_chr, "%lld", num);
    printf("%c", num_chr[remain]);
    puts("");
  }
}


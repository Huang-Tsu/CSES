#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef long long ll;

int main(){
  ll n, total = 0;
  ll num, pre_num;

  scanf("%lld", &n);
  scanf("%lld", &pre_num);
  while(scanf("%lld", &num) != EOF){
    if(num < pre_num){
      total += pre_num - num;
    }
    else
      pre_num = num;
  }

  printf("%lld\n", total);
}

#include <stdio.h>
#define MAX 1000000007

/* explanation:
   ex. n = 5 = 151_(2)
    2^n = 2^5 = 2^(101_(2)) = 2^(1*2^2 + 0*2^1 + 1*2^0) = 2^(2^2) * 2^(2^0)
    That is, multiple every two_power whos bit is 1, here is 2^2 and 2^0.
    In another example:1011 will be 2^3, 2^1, 2^0
    two_power is to compute the value of each two power, if this power's bit is 1, then multiple it to the output
*/
int main(){
  int n;
  long long two_power = 2;  //stat from 2^1
  long long output = 1;

  scanf("%d", &n);

  while(n > 0){ //if haven't gone through every bits, do
    if(n & 1){  //if this bit is one
      output *= two_power;  //multiple it to output
      if(output >= MAX){
        output %= MAX;
      }
    }
    two_power *= two_power; //power times two = value times value -> 2^(3*2) = 2^(3+3) = 2^(3) * 2^(3)
    if(two_power >= MAX)
      two_power %= MAX;
    n >>= 1; //n /= 2
  }

  printf("%lld\n", output);

  return 0;
}

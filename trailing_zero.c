#include <stdio.h>

int main(){
  int n;
  int total = 0;

  scanf("%d", &n);
  for(int i=5; i<=n; i*=5){ //count how many mutiple 5^i have?
    total += n/i;
  }
  printf("%d\n", total);

  return 0;
}

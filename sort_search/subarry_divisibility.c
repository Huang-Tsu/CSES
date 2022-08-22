#include <stdio.h>

int main(){
  int n;
  long long prefix = 0;
  long long input;
  long long total = 0;

  scanf("%d", &n);
  long long id_count[200000] = {0};
  id_count[0] = 1;

  for(int i=0; i<n; i++){
    scanf("%lld", &input);
    prefix = (prefix+input)%n;  //could be positive or negative
    id_count[(n+prefix)%n] ++;   //give it a buffer to reduce (%n for the case which prefix is positive)
  }

  for(int i=0; i<n; i++){
    total += (id_count[i]*(id_count[i]-1))/2; //C n 取 2
  }
  printf("%lld\n", total);
  return 0;
}


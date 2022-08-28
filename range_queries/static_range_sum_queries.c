#include <stdio.h>

int main(){
  long long pre_sum[200001] = {0};
  long long sum = 0; 
  int input;
  int n, q, a, b;

  scanf("%d%d", &n, &q);

  for(int i=1; i<n+1; i++){
    scanf("%d", &input); 
    sum += input;
    pre_sum[i] = sum;
  }
  
  for(int i=0; i<q; i++){
    scanf("%d%d", &a, &b);
    printf("%lld\n", pre_sum[b]-pre_sum[a-1]);
  }
  return 0;
}

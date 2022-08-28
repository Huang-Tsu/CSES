#include <stdio.h>

long long g_bit[200001];
int n, q;
int lowbit(int x){
  return x & -x;
}
void Update(int x, int value){
  if(x > n)
    return;

  g_bit[x] += value;
  Update(x+lowbit(x), value);
}
long long FindSum(int x){
  if(x == 0)
    return 0;

  return g_bit[x] + FindSum(x - lowbit(x));
}
int main(){
  int value[200001];
  int a, b, c;
  scanf("%d%d", &n, &q);

  for(int i=1; i<n+1; i++){
    scanf("%d", &value[i]);
    Update(i, value[i]);
  }

  for(int i=0; i<q; i++){
    scanf("%d%d%d", &a, &b, &c);
    if(a == 1){ //update
      Update(b, c-value[b]);
      value[b] = c;
    }
    else{
      printf("%lld\n", FindSum(c)-FindSum(b-1));
    }

  }
  return 0;
}

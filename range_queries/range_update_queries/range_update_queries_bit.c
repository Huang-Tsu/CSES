#include <stdio.h>
int n, q, a, b, c;
long long bit[200002];
void update(int x, long long val){
  for(int i=x; i<n+1; i+=i&(-i)){
    bit[i] += val;
  }
}
void range_update(int l, int r, long long val){
  update(l, val);
  update(r+1, -val);
}
long long query(int k){
  long long sum = 0;
  for(int i=k; i>0; i-=i&(-i)){
    sum += bit[i];
  }
  return sum;
}
int main(){
  scanf("%d%d", &n, &q);
  for(int i=1; i<n+1; i++){
    scanf("%d", &a);
    range_update(i, i, a);
  }
  for(int i=0; i<q; i++){
    scanf("%d", &a);
    if(a==1){
      scanf("%d%d%d", &a, &b, &c);
        range_update(a, b, c);
    }
    else{
      scanf("%d", &c);
        printf("%lld\n", query(c));
    }
  }

  return 0;
}

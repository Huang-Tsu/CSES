#include <stdio.h>

long long min(long long a, long long b){
  return (a<b ? a : b);
}
long long max(long long a, long long b){
  return (a>b ? a : b);
}
int main(){
  int t;
  long long a, b;

  scanf("%d", &t);
  for(int i=0; i<t; i++){
    scanf("%lld%lld", &a, &b);
    if((a+b)%3==0 && min(a, b)*2>=max(a, b)){
      printf("YES\n");
    }
    else{
      printf("NO\n");
    }
  }

  return 0;
}

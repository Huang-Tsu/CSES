#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int g_apple[20];
long long g_total = 0;
long long g_min = INT_MAX;

void Division(int n, long long now){
  if(n==0){
    if(abs(g_total-now-now) < g_min){
      g_min = abs(g_total-now-now);
    }
    return;
  }

  Division(n-1, now);
  Division(n-1, now+g_apple[n-1]);
}
int main(){
  int n;

  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &g_apple[i]);
    g_total += g_apple[i];
  }
  Division(n-1, 0);
  Division(n-1, 0+g_apple[n-1]);

  printf("%lld", g_min);

}

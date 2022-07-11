#include <stdio.h>

int main(){
  int n;
  int total = 0;
  int j;

  scanf("%d", &n);
  for(int i=5; i<=n; i+=5){
    j = i;
    //count how many 5 this number has
    while(j%5==0 && j!=0){  //j is divided by 5 and j is not zero
      total ++;
      j /= 5;
    }
  }
  printf("%d\n", total);

  return 0;
}

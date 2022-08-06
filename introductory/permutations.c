#include <stdio.h>
#include <stdlib.h>

/*  偶數間及奇數間不相臨，若先print奇數再print偶數，只要奇數的最後一個數跟偶數的第一個數差超過1，則必有解
*/
int main(){
  int n, i;

  scanf("%d", &n);

  if(n == 1){
    printf("1\n");
  }
  else if(n < 4){
    printf("NO SOLUTION\n");
  }
  else if(n == 4){  //4算是一個特例
    printf("2 4 1 3\n");
  }
  else{
    for(i=1; i<=n; i+=2){
      printf("%d ", i);
    }
    for(i=2; i<=n; i+=2){
      printf("%d ", i);
    }
    puts("");
  }
  return 0; 
}

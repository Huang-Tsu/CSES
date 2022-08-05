#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX_LEN 1000005

int g_fail[MAX_LEN];
void Fail(char *pattern){
  
  int len = strlen(pattern);

  g_fail[0] = -1;
  for(int i=1, j=-1; i<len; i++){ //i = pattern counter, j = fail counter
    while(j>=0 && pattern[i]!=pattern[j+1]){  //向下遞迴到j==-1 or pattern[i]==pattern[j]時中止
      j = g_fail[j];
    //  printf("j:%d\n", j);
    }
    //check 是哪種情況下出來的
    if(pattern[i]==pattern[j+1]){ //相同字元出來的 
      j++;
    }

    g_fail[i] = j;
  }
}
int main(){
  char string[MAX_LEN];
  char pattern[MAX_LEN];
  int match_cnt = 0;
  int i=0, j=-1;

  fgets(string, MAX_LEN, stdin);
  scanf("%s", pattern);
  Fail(pattern);
  int string_len = strlen(string);
  int pattern_len = strlen(pattern);
  
  while(i<string_len){
    while(j!=-1 && string[i]!=pattern[j+1]){
      j = g_fail[j];
    }
    if(string[i]==pattern[j+1]){
      j++;
      if(j == pattern_len-1){
        match_cnt ++;
        j = g_fail[j];
      }
    }
    i++;
  }

  printf("%d\n", match_cnt);

  return 0;
}

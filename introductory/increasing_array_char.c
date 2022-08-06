#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef long long ll;
#define MAX_SIZE 2200000  //200000 * 11(max_digit+space)
 
char *GetNextNum(char *ptr, ll *num){
  char word[11];
  char *qtr = word;
  if(*ptr && isspace(*ptr)) ptr ++;
  while(*ptr && isdigit(*ptr)) *qtr++ = *ptr++;
  *qtr = '\0';
 
  *num = atoi(word);
  return (qtr!=word? ptr : NULL);
 
 
}
int main(){
  ll n, total = 0;
  ll num, pre_num;
  char *ptr;
 
  scanf("%lld", &n);
  getchar();  //skip \n
  char buffer[MAX_SIZE];
  ptr = buffer;
  fgets(buffer, MAX_SIZE, stdin);
  ptr = GetNextNum(ptr, &pre_num);
  while((ptr = GetNextNum(ptr, &num)) != NULL){
    if(num < pre_num){
      total += pre_num - num;
    }
    else
      pre_num = num;
  }
  printf("%lld\n", total);
}

#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n, x;
  long long pre = 0;
  long long need;
  long long input;
  long long answer = 0;
  unordered_map <long long, int> pre_cnt;
  pre_cnt[pre] ++;  //***important** zero is part of prefix sum
  cin >> n >> x;
  for(int i=0; i<n; i++){
    //pre[R] - pre[L-1] = x;
    //pre[L-1] == pre[R] - x;
    cin >> input;
    pre += input;
    need = pre - x;
    answer += pre_cnt[need];
    pre_cnt[pre] ++;
  }
  cout << answer;

}

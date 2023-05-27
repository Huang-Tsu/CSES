#include <bits/stdc++.h>
using namespace std;
long long real_x(long long x, int min_value, int input_cnt){
  return x + min_value*input_cnt;
}
int main(){
  long long n, x;
  long long answer = 0;
  cin >> n >> x;
  long long pre = 0;
  long long input;
  long long need;
  unordered_map <long long, int> pre_cnt;
  pre_cnt[pre] ++;  //***important*** zero can be possible
  for(int i=0; i<n; i++){
    //pre[R] - pre[L-1] == x
    //pre[L-1] == pre[R] - x;
    cin >> input;
    pre += input;
    need = pre - x;
    answer += pre_cnt[need]; 
    pre_cnt[pre] ++;
  }

  cout << answer << '\n';
}

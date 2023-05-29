#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  int l, r=0;
  cin >> n >> k;
  int arr[n];
  long long answer = 0;
  unordered_map<int, int> diff;
  int diff_cnt = 0;
  int arr_cnt = 0;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  for(l=0; l<n&&r<n; l++){
    while(r<n && diff_cnt<=k){
//        cout << "diff_cnt: " << diff_cnt << '\n';
      diff[arr[r]] ++;
      arr_cnt ++;
      if(diff[arr[r]] == 1){
        diff_cnt ++;
      }
      if(diff_cnt <= k){
        answer += arr_cnt;
        r ++;
      }
    }
    diff[arr[l]] --;
    arr_cnt --;
    if(diff[arr[l]] == 0){
      diff_cnt --;
      if(r < n && diff_cnt <= k){
        answer += arr_cnt;
        r ++;
      }
    }
  }
  cout << answer << '\n';

}


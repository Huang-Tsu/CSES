#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  long long answer, l, r, mid;
  long long total = 0;
  int div_cnt = 0;
  int max = 0;
  for(int i=0; i<n; i++){
    if(arr[i] > max){
      max = arr[i];
    }
  }
  l = max;
  r = LLONG_MAX-max;
  while(l <= r){
    mid = (l+r)/2;
    total = arr[0];
    div_cnt = 1;
    for(int i=1; i<n; i++){
      if(total+arr[i] > mid){
        total = arr[i];
        div_cnt ++;
      }
      else{
        total += arr[i];
      }
    }
    if(div_cnt <=  k){
      r = mid - 1;
      answer = mid;
    }
    else{
      l = mid + 1;
    }
  }
  cout << answer << '\n';
}

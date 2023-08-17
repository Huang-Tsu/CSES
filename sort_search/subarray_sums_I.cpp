#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  long long total = 0;
  long long x;
  long long cnt = 0;
  
  cin >> n >> x;
  vector <long long> arr(n+10);
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
 
  int l, r;
  l = r = 0;
  for(r=0; r<n; r++){
    total += arr[r];
 
    if(total == x){
      cnt ++;
    }
    else if(total < x){
      continue;
    }
    else{ //total > x
      while(l<=r && total > x){
        total -= arr[l++];
      }
      if(total == x){
        cnt ++;
      }
    }
  }
 
  cout << cnt << '\n';
}

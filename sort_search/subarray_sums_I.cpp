#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  long long x;
  cin >> n >> x;
  long long arr[n];
  long long total = 0;
  long long count = 0;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  int l, r;
  l = r = 0;
  total = arr[0];
  while(r < n && l < n){
    if(total == x){
        count ++;
        if(r == n-1){
          break;
        }
        else{
          total += arr[++r];
        }
    }
    else if(l == r){
      if(r == n-1){
        break;
      }
      else{
        total += arr[++r];
      }
    }
    else{
      if(total < x){
        if(r == n-1){
          break;
        }
        else{
          total += arr[++r];
        }
      }
      else if(total > x){
        total -= arr[l++];
      }
    }
  }

  cout << count;
}

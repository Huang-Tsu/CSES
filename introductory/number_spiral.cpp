#include <bits/stdc++.h>
using namespace std;
void solve(){
  long long x, y;
  long long result;
  cin >> y >> x;
  if (x >= y){
    if(x & 1){
      result = x * x; 
      result -= (y-1);
    }
    else{
      result = (x-1) * (x-1) + 1;
        result += (y-1);
    }
  }
  else{
    if(y%2 == 0){
      result = y * y;
      result -= (x-1);
    }
    else{
      result = (y-1) * (y-1) + 1;
        result += (x-1);
    }
  }
  cout << result << '\n';
}
int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}

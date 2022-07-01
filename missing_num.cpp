#include <iostream>
typedef long long ll;
using namespace std;

void solve(){
  ll n, total;
  int input;

  cin>>n;
  total = ((1+n)*n)/2;

  for(int i=0; i<n-1; i++){
    cin >> input;
    total -= input;
  }
  cout << total << '\n';
}
int main(){
  cin.tie(0)->sync_with_stdio(false);
  solve();
  return 0;
}

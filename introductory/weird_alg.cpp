#include <iostream>
typedef long long ll;
using namespace std;
int main(){
  cin.tie(0)->sync_with_stdio(false);
  ll n;
  cin >> n;
  cout << n << ' ';
  while(n!=1){
    if(n&1){  //odd
      n = n*3+1;
    }
    else{
      n /= 2;
    }
    cout << n << ' ';
  }
  cout<<'\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  if(n%4==0){
    cout << "YES\n";
    cout << n/2 << '\n';
    for(int i=1; i<=n; i++){
      if(i%4==0 || i%4==1){
        cout << i << ' ';
      }
    }
    cout <<'\n';
    cout << n/2 << '\n';
    for(int i=2; i<=n; i++){
      if(i%4==2 || i%4==3){
        cout << i << ' ';
      }
    }
    cout << '\n';
  }
  else if(n%4==3){
    cout << "YES\n";
    cout << (n+1)/2 << '\n';
    cout << "1 2 ";
    for(int i=4; i<=n; i++){
      if(i%4==0 || i%4==3){
        cout << i << ' ';
      }
    }
    cout << '\n';
    cout << n/2 << '\n';
    cout << "3 "; 
    for(int i=3; i<=n; i++){
      if(i%4==1 || i%4==2){
        cout << i << ' ';
      }
    }
    cout << '\n';
  }
  else{
    cout << "NO\n";
  }
}


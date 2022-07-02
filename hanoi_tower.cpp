#include <iostream>
#define TOTAL 6   //1 + 2 + 3
using namespace std;


void Tower(int n, int a, int b){  //move n from pos_a to pos_b
  if(n == 1){
    cout << a << " " << b << '\n'; 
    return;
  }

  const int c = TOTAL - a - b;    //c is the half-way point of moving n from a(src) to b(dst)

  Tower(n-1, a, c);         //move n-1 from pos_a to pos_c  //move n-1 to half-way point 
  cout << a << " " << b << '\n';            //move n-th from src to dst
  Tower(n-1, c, b);        //move n-1 from pos_c to pos_b  //move n-1 back from half-way point to dst
  return;
}
int main(){
  int n;
  int total = 0;

  cin >> n;
  for(int i=0; i<n; i++){
    total = total*2 + 1;
  }
  cout << total << '\n';

  Tower(n, 1, 3);
  
  return 0;
}

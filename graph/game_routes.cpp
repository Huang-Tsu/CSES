#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000000007

vector<int> g_level[100005];
int g_dp[100005];

int CountWay(int n){
  if(g_dp[n] != -1) return g_dp[n];

  long long sum = 0;
  for(const auto &i : g_level[n]){
    sum += CountWay(i);
    if(sum >= MAX) sum -= MAX;
  }
  
  g_dp[n] = sum;
  return sum;
}

int main(){
  int n, m, a, b;

  cin >> n >> m;
  g_dp[1] = 1;
  for(int i=2; i<100005; i++){
    g_dp[i] = -1;
  }

  for(int i=0; i<m; i++){
    cin >> a >> b;
    g_level[b].push_back(a);
  }

  cout << CountWay(n) << '\n';
}

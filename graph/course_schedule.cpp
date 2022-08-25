#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> g_adj_list[100001];
int g_visited[100001];
int g_indegree[100001];
int main(){
  vector<int> ans;
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, a, b;
  int now;
  queue<int> q;

  cin >> n >> m;

  for(int i=0; i<m; i++){
    cin >> a >> b;
    g_adj_list[a].push_back(b);
    g_indegree[b] ++;
  }

  for(int i=1; i<n+1; i++){
    if(g_indegree[i] == 0){
      q.push(i);
    }
  }

  while(!q.empty()){
    now = q.front(), q.pop();
    ans.push_back(now);
    for(const auto &iter : g_adj_list[now]){
      g_indegree[iter] --;
      if(g_indegree[iter] == 0){
        q.push(iter);
      }
    }
  }

  if(ans.size() != n){
    cout << "IMPOSSIBLE\n";
  }
  else{
    for(const auto &i : ans){
      cout << i << ' ';
    }
  }
  cout << '\n';

  return 0;
}

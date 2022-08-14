#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>

struct comp{
  bool operator ()(pll a, pll b){
    return a.second > b.second; //smaller one goes first(min heap)
  }
};
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, a, b, c, now_idx, adj_idx;
  vector<pll> weight_list[100001];
  ll dis[100001], temp_weight, now_weight, adj_weight;
  pll vertix_now;
  priority_queue<pll, vector<pll>, comp> pq;
  
  cin >> n >> m;
  for(int i=0; i<m; i++){
    cin >> a >> b >> c; 
    weight_list[a].push_back({b, c});  //{end, cost}
  }
  //initialize
  for(int i=1; i<n+1; i++){//TODO seek for a better way (memset?)
    dis[i] = LLONG_MAX;  
  }
  //start dijkstra 
  dis[1] = 0;
  pq.push({1, 0});
  while(!pq.empty()){
    vertix_now = pq.top(), pq.pop();
    now_idx = vertix_now.first, now_weight = vertix_now.second;
    if(now_weight > dis[now_idx]) //have been visited by shorter route
      continue;
    for(const auto &adj_vertix : weight_list[now_idx]){  //traverse all the neightbours of vertix_now
      adj_idx = adj_vertix.first, adj_weight = adj_vertix.second;
      temp_weight = now_weight + adj_weight;
      if(temp_weight < dis[adj_idx]){
        dis[adj_idx] = temp_weight;
        pq.push({adj_idx, dis[adj_idx]});
      }
    }
  }

  for(int i=1; i<n+1; i++){
    cout << dis[i] << ' ';
  }

}

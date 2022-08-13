#include <iostream>
#include <climits>
#include <queue>
#include <map>
using namespace std;

class Vertix{
 public:
  char visited;
  long long dis;
  map<long, long> adj_list;
};

Vertix g_vertix[100010];
struct comp{
  bool operator()(long long a, long long b) {
    return g_vertix[a].dis >= g_vertix[b].dis;
  }
};
int main(){
  int n, m;
  int vertix_next, vertix_now;
  int a, b, cost;
  long long test_cost;
  cin >> n >> m;
  priority_queue<long long, vector<long long>, comp> prior_q;

  //initialize
  for(int i=1; i<n+1; i++){
    g_vertix[i].visited = 0;
    g_vertix[i].dis = LLONG_MAX;
  }

  for(int i=0; i<m; i++){
    cin >> a >> b >> cost;
    if(a != b){
      if(g_vertix[a].adj_list.find(b)==g_vertix[a].adj_list.end() || cost < g_vertix[a].adj_list[b]){  //not exist or the input one is smaller than the exist one
        g_vertix[a].adj_list[b] = cost;
      }
    }
  }

  g_vertix[1].dis = 0;
  g_vertix[1].visited = 2;
  for(const auto &next_pair : g_vertix[1].adj_list){
    vertix_next = next_pair.first;
    g_vertix[vertix_next].dis = next_pair.second;
    g_vertix[vertix_next].visited = 1;
    prior_q.push(vertix_next);
  }

  while(!prior_q.empty()){
      //cout << "prior_q.size():" << prior_q.size() << '\n';
    vertix_now = prior_q.top(), prior_q.pop();
    if(g_vertix[vertix_now].visited == 2){//vertix exsit
      continue;
    }
      //cout << "vertix_idx:" << vertix_now << '\n';
    g_vertix[vertix_now].visited = 2;
    //add adj_edge to priority_queue
    for(const auto &pair_next : g_vertix[vertix_now].adj_list){
      vertix_next = pair_next.first;
      test_cost = g_vertix[vertix_now].dis+pair_next.second;
      if(g_vertix[vertix_next].visited != 2){
        if(g_vertix[vertix_next].visited == 0){
          g_vertix[vertix_next].visited = 1;
          g_vertix[vertix_next].dis = test_cost;
          prior_q.push(vertix_next);
        }
        else if(test_cost < g_vertix[vertix_next].dis){
          g_vertix[vertix_next].dis = test_cost;
          prior_q.push(vertix_next);
          //prior_q.push(vertix_next);
        }
      }
    }
  }
  for(int i=1; i<n+1; i++){
    cout << g_vertix[i].dis << ' ';
  }

  return 0; 
}

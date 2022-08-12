#include <iostream>
#include <climits>
#include <queue>
using namespace std;

class Edge{
 public:
  int start, end;
  long long cost;
};
class Vertix{
 public:
  char visited;
  vector<int> adj_list;
  long long dis;
};

Edge g_edge[200000];
Vertix g_vertix[100001];
bool comp(int a, int b){
  return g_vertix[a].dis < g_vertix[b].dis;
}
int main(){
  int n, m;
  int vertix_next, vertix_now;
  long long test_cost;
  cin >> n >> m;
  vector<int> prior_q;

  //initialize
  for(int i=1; i<n+1; i++){
    g_vertix[i].visited = 0;
    g_vertix[i].dis = INT_MAX;
  }

  for(int i=0; i<m; i++){
    cin >> g_edge[i].start >> g_edge[i].end >> g_edge[i].cost;
    g_vertix[g_edge[i].start].adj_list.push_back(i);
  }

  g_vertix[1].dis = 0;
  g_vertix[1].visited = 2;
  for(const auto &edge_idx : g_vertix[1].adj_list){
    vertix_next = g_edge[edge_idx].end;
    g_vertix[vertix_next].dis = g_edge[edge_idx].cost;
    g_vertix[vertix_next].visited = 1;
    prior_q.push_back(vertix_next), push_heap(prior_q.begin(), prior_q.end(), comp);
  }

  while(!prior_q.empty()){
      cout << "prior_q.size():" << prior_q.size() << '\n';
      pop_heap(prior_q.begin(), prior_q.end(), comp);
    vertix_now = prior_q.back(), prior_q.pop_back();
    g_vertix[vertix_now].visited = 2;
    //add adj_edge to priority_queue
    for(const auto &edge_idx : g_vertix[vertix_now].adj_list){
      vertix_next = g_edge[edge_idx].end;
      test_cost = g_vertix[vertix_now].dis+g_edge[edge_idx].cost;
      if(g_vertix[vertix_next].visited != 2){
        if(g_vertix[vertix_next].visited == 0){
          g_vertix[vertix_next].visited = 1;
          g_vertix[vertix_next].dis = test_cost;
          prior_q.push_back(vertix_next);
        }
        else if(test_cost < g_vertix[vertix_next].dis){
          g_vertix[vertix_next].dis = test_cost;
          //prior_q.push(vertix_next);
        }
      }
    }
    make_heap(prior_q.begin(), prior_q.end(), comp);
  }
  for(int i=1; i<n+1; i++){
    cout << g_vertix[i].dis << ' ';
  }

  return 0; 
}

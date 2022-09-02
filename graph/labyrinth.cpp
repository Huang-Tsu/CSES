#include <iostream>
#include <queue>
#include <stack>
#include <utility>
  #include <unistd.h>
using namespace std;

char graph[1000][1000];
pair<int, int> start;
pair<int, int> endd;
pair<int, int> now;
queue<pair<int, int> > q;
int visited[1000][1000];
int dy[4] = {0, 1, 0, -1};  //R, D, L, U
int dx[4] = {1, 0, -1, 0};  //R, D, L, U
int pre[1000][1000];
int is_valid(int x, int y){
  return (x>-1 && y>-1 && x<1000 && y<1000 && (graph[y][x]=='.' || graph[y][x]=='B') && (visited[y][x]==0));
}
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  int next_x, next_y, x, y;
  stack<char> s;
  string motion = "RDLU";
  int motion_n;
  int length = 0;
  cin >> n >> m;


  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> graph[i][j];
      if(graph[i][j] == 'A'){
        start = {i, j};
        q.push({i, j});
        visited[i][j] = 1;
      }
      else if(graph[i][j] == 'B'){
        endd = make_pair(i, j);
      }
    }
  }

  while(!q.empty()){
    now = q.front(), q.pop();
    x = now.second;
    y = now.first;
    if(graph[y][x] == 'B'){
      break;
    }
    for(int i=0; i<4; i++){
      next_x = x + dx[i]; 
      next_y = y + dy[i]; 
      if(is_valid(next_x, next_y)){
        q.push({next_y, next_x});
        pre[next_y][next_x] = i;
        visited[next_y][next_x] = 1;
      }
    }
  }

  if(visited[endd.first][endd.second] != 1){
    cout << "NO\n";
    return 0;
  }
  else{
    x = endd.second; 
    y = endd.first;
    while(y!=start.first || x!=start.second){
      motion_n = pre[y][x];
      s.push(motion[motion_n]);  
      x -= dx[motion_n];
      y -= dy[motion_n];
      length ++;
    }
  }
  cout << "YES\n";
  cout << length << '\n';
  while(!s.empty()){
    cout << s.top();
    s.pop();
  }
  cout << '\n';
  return 0;
}

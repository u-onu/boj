#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<bool> visited;

struct record{
  int node, dist;
  record(int node, int dist){
    this->node = node;
    this->dist = dist;
  }
};

int bfs(int start_node, int end_node){
  queue<struct record> q;
  q.push(record(start_node, 0));
  visited[start_node] = true;

  while(!q.empty()){
    struct record temp = q.front();
    q.pop();

    if(temp.node == end_node)
      return temp.dist;
    
    for(int next: edges[temp.node]){
      if(!visited[next]){
        visited[next] = true;
        q.push(record(next, temp.dist + 1));
      }
    }
  }

  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin); 

  int n;
  cin >> n;
  edges.resize(n + 1, vector<int>());
  visited.resize(n + 1);

  int target1, target2;
  cin >> target1 >> target2;

  int m, x, y;
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> x >> y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }

  cout << bfs(target1, target2);
}
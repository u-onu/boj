#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> edges;
int infected_cnt;

void dfs(int node){
  visited[node] = true;
  
  for(int next: edges[node]){
    if(!visited[next]){
      infected_cnt++;
      dfs(next);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n, e;
  cin >> n >> e;
  visited.resize(n + 1);
  edges.resize(n + 1, vector<int>());

  int u, v;
  for(int i = 0; i < e; i++){
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  dfs(1);
  cout << infected_cnt;
}
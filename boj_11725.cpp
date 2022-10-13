#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edge;
vector<int> parents;

void dfs(int node, int parent){
  parents[node] = parent;

  for(int child: edge[node]){
    if(child == parent) continue;
    dfs(child, node);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;
  edge.resize(n + 1, vector<int>());
  parents.resize(n + 1);

  int node1, node2;
  for(int i = 0; i < n; i++){
    cin >> node1 >> node2;
    edge[node1].push_back(node2);
    edge[node2].push_back(node1);
  }

  dfs(1, -1);

  for(int i = 2; i <= n; i++)
    cout << parents[i] << '\n';
}
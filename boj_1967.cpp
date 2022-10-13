#include <bits/stdc++.h>
using namespace std;

struct edge{
  int linked_node, cost;

  edge(int linked_node, int cost){
    this->linked_node = linked_node;
    this->cost = cost;
  }
};

vector<vector<struct edge>> edges;
int max_cost, end_node;

void dfs(int node, int parent, int cost){
  if(cost > max_cost){
    max_cost = cost;
    end_node = node;
  }

  for(struct edge next: edges[node]){
    if(next.linked_node == parent)  continue;
    dfs(next.linked_node, node, cost + next.cost);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;
  edges.resize(n + 1, vector<struct edge>());

  int node1, node2, cost;
  for(int i = 0; i < n - 1; i++){
    cin >> node1 >> node2 >> cost;
    edges[node1].push_back(edge(node2, cost));
    edges[node2].push_back(edge(node1, cost));
  }

  dfs(1, -1, 0);
  dfs(end_node, -1, 0);
  cout << max_cost;
}
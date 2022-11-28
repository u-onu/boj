#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 1001

struct record{
  int from, to, cost;
};

int parent[N];
vector<record> edges;
int n, m;
int min_cost;

bool cmp_cost(record x, record y){
  return x.cost < y.cost;
}

void init(){
  cin >> n >> m;

  // init edges
  edges.resize(m);
  for(int i = 0; i < m; i++)
    cin >> edges[i].from >> edges[i].to >> edges[i].cost;
  sort(edges.begin(), edges.end(), cmp_cost);
  
  // init parent
  for(int i = 1; i <= n; i++)
    parent[i] = i;
}

int find(int node){
  if(parent[node] == node)
    return node;
  else
    return parent[node] = find(parent[node]);
}

void unite(record& r){
  int u = find(r.from);
  int v = find(r.to);

  if(u == v)  return;

  parent[u] = v;
  min_cost += r.cost;
}

void solve(){
  for(record &edge: edges)
    unite(edge);
  
  cout << min_cost << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init();
  solve();
}
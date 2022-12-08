#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 100001

struct edge{
  int from, to, cost;
  bool operator<(edge &e)
    {return cost < e.cost;}
};

vector<edge> edges;
int parent[N];
int min_cost;

int find_parent(int x){
  if(parent[x] == x)
    return x;
  return parent[x] = find_parent(parent[x]);
}

bool union_groups(int x, int y){
  x = find_parent(x);
  y = find_parent(y);
  if(x == y) return false;
  
  if(x < y) parent[y] = x;
  else parent[x] = y;
  return true;
}

void init(){
  int n, m;
  cin >> n >> m;

  edges.resize(m);
  for(int i = 0; i < m; i++)
    cin >> edges[i].from >> edges[i].to >> edges[i].cost;
  sort(edges.begin(), edges.end());
  
  for(int i = 1; i <= n; i++)
    parent[i] = i;
}

void solve(){
  int min_cost;

  min_cost = 0;
  for(edge &e: edges)
    if(union_groups(e.from, e.to)){
      min_cost += e.cost;
    }

  cout << min_cost << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init();
  solve();
}
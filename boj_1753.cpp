#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

#define N 20001

struct edge{
  int node, cost;
  edge(int node, int cost)
    {this->node = node; this->cost = cost;}
  bool operator<(const edge &e) const
    {return cost > e.cost;} // for min-heap
};

vector<edge> edges[N];
int dist[N];
int v, e, k;

void init(){
  cin >> v >> e >> k;

  int u, v, w;
  for(int i = 0; i < e; i++){
    cin >> u >> v >> w;
    edges[u].push_back(edge(v, w));
  }

  fill(dist, dist + N, INT_MAX);
}

void shortest_dist(int from){ // dijkstra algorithm
  priority_queue<edge> pq;
  pq.push(edge(from, 0));
  dist[from] = 0;

  while(pq.empty() == false){
    edge cur = pq.top();
    pq.pop();

    for(edge &next: edges[cur.node])
      if(dist[next.node] > cur.cost + next.cost){
        dist[next.node] = cur.cost + next.cost;
        pq.push(edge(next.node, dist[next.node]));
      }
  }
}

void solve(){
  shortest_dist(k);
  for(int i = 1; i <= v; i++){
    if(dist[i] == INT_MAX)
      cout << "INF" << '\n';
    else
      cout << dist[i] << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init();
  solve();
}
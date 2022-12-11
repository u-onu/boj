#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

#define N 801
#define INF INT_MAX

struct edge{
  int node, cost;
  edge(int node, int cost)
    {this->node = node; this->cost = cost;}
  bool operator<(const edge &e) const
    {return cost > e.cost;} // for min-heap
};

vector<edge> edges[N];
int dist[N];
int n, e;

void init(){
  cin >> n >> e;

  int a, b, c;
  for(int i = 0; i < e; i++){
    cin >> a >> b >> c;
    edges[a].push_back(edge(b, c));
    edges[b].push_back(edge(a, c));
  }
}

void shortest_path(int from){ // dijkstra algorithm
  fill(dist, dist + N, INF);
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
  int v1, v2, s_to_v1, s_to_v2, v1_to_v2, v2_to_v1, v1_to_n, v2_to_n;
  cin >> v1 >> v2;

  shortest_path(1);
  s_to_v1 = dist[v1];
  s_to_v2 = dist[v2];

  shortest_path(n);
  v1_to_n = dist[v1];
  v2_to_n = dist[v2];

  shortest_path(v1);
  v1_to_v2 = v2_to_v1 = dist[v2];

  if(s_to_v1 == INF || v1_to_n == INF || v1_to_v2 == INF)
    cout << -1 << '\n';
  else
    cout << min(s_to_v1 + v1_to_v2 + v2_to_n, s_to_v2 + v2_to_v1 + v1_to_n) << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init();
  solve();
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define N 2001
#define INF 1e8

struct edge{
  int node, cost;
  edge(int node, int cost)
    {this->node = node; this->cost = cost;}
  bool operator<(const edge &e) const
    {return cost > e.cost;}
};

int dist_s[N];
int dist_g[N];
int dist_h[N];
vector<edge> edges[N];
int n, m, t, s, g, h;

void init(){
  int a, b, d;
  cin >> n >> m >> t >> s >> g >> h;

  fill(dist_s, dist_s + N, INF);
  fill(dist_g, dist_g + N, INF);
  fill(dist_h, dist_h + N, INF);

  for(int i = 0; i < N; i++)
    edges[i].clear();
  for(int i = 0; i < m; i++){
    cin >> a >> b >> d;
    edges[a].push_back(edge(b, d));
    edges[b].push_back(edge(a, d));
  }
}

void dijkstra(int dist[], int from){
  priority_queue<edge> min_heap;
  dist[from] = 0;
  min_heap.push(edge(from, 0));

  while(min_heap.empty() == false){
    edge cur = min_heap.top();
    min_heap.pop();

    for(edge &next: edges[cur.node]){
      if(dist[next.node] > cur.cost + next.cost){
        dist[next.node] = cur.cost + next.cost;
        min_heap.push(edge(next.node, dist[next.node]));
      }
    }
  }
}

void solve(){
  vector<int> dests;
  int x, gh;

  dijkstra(dist_s, s);
  dijkstra(dist_g, g);
  dijkstra(dist_h, h);
  gh = dist_g[h];

  for(int i = 0; i < t; i++){
    cin >> x;
    if(dist_s[x] == min(dist_g[s] + gh + dist_h[x], dist_h[s] + gh + dist_g[x]))
      dests.push_back(x);
  }

  sort(dests.begin(), dests.end());
  for(int d: dests)
    cout << d << ' ';
  cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int T; cin >> T;
  while(T--){
    init();
    solve();
  }
}
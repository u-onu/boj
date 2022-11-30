#include <iostream>
#include <map>
using namespace std;

#define N 200000

int parent[N];
int network_size[N];
map<string, int> name;

int find_parent(int x){
  if(parent[x] == x)
    return x;
  return parent[x] = find_parent(parent[x]);
}

void union_groups(int x, int y){
  x = find_parent(x);
  y = find_parent(y);
  if(x == y) return;
  if(x < y){
    parent[y] = x;
    network_size[x] += network_size[y];
  }
  else{
    parent[x] = y;
    network_size[y] += network_size[x];
  }
}

void init(){
  for(int i = 0; i < N; i++){
    parent[i] = i;
    network_size[i] = 1;
  }
  name.clear();
}

void solve(){
  int n;
  cin >> n;

  string a, b;
  int cnt = 1;
  for(int i = 0; i < n; i++){
    cin >> a >> b;

    if(name.find(a) == name.end())
      name[a] = cnt++;
    if(name.find(b) == name.end())
      name[b] = cnt++;

    union_groups(name[a], name[b]);
    cout << network_size[find_parent(name[a])] << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    init();
    solve();
  }
}
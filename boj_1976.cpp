#include <iostream>
using namespace std;

#define MAX_N 201

int parent[MAX_N];
int n, m;

int find_parent(int x){
  if(parent[x] == x)
    return x;
  else
    return parent[x] = find_parent(parent[x]);
}

void union_groups(int x, int y){
  x = find_parent(x);
  y = find_parent(y);
  if(y != x)
    parent[y] = x;
}

void init_parent(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    parent[i] = i;
  
  int link;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> link;
      if(link == 1)
        union_groups(i, j);
    }
  }
}

void solve(){
  int city, p, temp;
  cin >> city;
  p = find_parent(city);

  for(int i = 1; i < m; i++){
    cin >> city;
    temp = find_parent(city);
    if(p != temp){
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
 
  init_parent();
  solve();
}
#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int x){
  if(parent[x] == x)
    return x;
  else
    return parent[x] = find(parent[x]);
}

void merge(int x, int y){
  x = find(x);
  y = find(y);
  if(x != y)
    parent[y] = x;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n, m;
  cin >> n >> m;
  parent.resize(n + 1);

  for(int i = 1; i <= n; i++)
    parent[i] = i;

  int op, a, b;  
  for(int i = 0; i < m; i++){
    cin >> op >> a >> b;

    // merge
    if(op == 0)
      merge(a, b);
    
    // find
    else{
      if(find(a) == find(b)) cout << "YES\n";
      else cout << "NO\n";
    }
  }
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nodes;

bool cut_vertex(int k){
  if(nodes[k].size() != 1)  
    return true;
  else
    return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin); 

  int n;
  cin >> n;
  nodes.resize(n + 1, vector<int>());

  int a, b;
  for(int i = 1; i <= n - 1; i++){
    cin >> a >> b;
    nodes[a].push_back(b);
    nodes[b].push_back(a);
  }

  int q, t, k;
  cin >> q;
  for(int i = 0; i < q; i++){
    cin >> t >> k;

    if(t == 1){
      if(cut_vertex(k))
        cout << "yes\n";
      else
        cout << "no\n";
    }
    
    // all edges of a tree are bridges.
    else cout << "yes\n";
  }
}
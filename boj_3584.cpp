#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;
  vector<int> parents(n + 1);

  int parent, child;
  for(int i = 0; i < n - 1; i++){
    cin >> parent >> child;
    parents[child] = parent;
  }

  int node1, node2;
  cin >> node1 >> node2;

  vector<bool> visited(n + 1, false);
  while(node1 != 0){
    visited[node1] = true;
    node1 = parents[node1];
  }
  while(node2 != 0){
    if(visited[node2]){
      cout << node2 << '\n';
      break;
    }
    node2 = parents[node2];
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int test_case;
  cin >> test_case;
  for(int t = 0; t < test_case; t++)
    solve();  
}
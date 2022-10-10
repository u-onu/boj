#include <bits/stdc++.h>
using namespace std;

int n, m;
bool isused[10];
int arr[10];


void dfs(int depth, int node){
  if(depth == m){
    for(int i = 0; i < m; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }

  for(int i = node; i <= n; i++){
    if(!isused[i]){
      arr[depth] = i;
      isused[i] = true;
      dfs(depth + 1, i);
      isused[i] = false;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  cin >> n >> m;
  dfs(0, 1);
}
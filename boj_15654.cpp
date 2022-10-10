#include <bits/stdc++.h>
using namespace std;

int n, m;
bool isused[10];
int arr[10];

void dfs(int depth, vector<int> &v){
  if(depth == m){
    for(int i = 0; i < m; i++)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }

  for(int i = 0; i < n; i++){
    if(!isused[i]){
      arr[depth] = v[i];
      isused[i] = true;
      dfs(depth + 1, v);
      isused[i] = false;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  cin >> n >> m;
  vector<int> input(n);
  for(int i = 0; i < n; i++)
    cin >> input[i];

  sort(input.begin(), input.end());
  dfs(0, input);
}
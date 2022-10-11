#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool isused_column[15];
bool isused_upward[30];
bool isused_downward[30];

void dfs(int row){
  if(row == n){
    cnt++;
    return;
  }

  for(int x = 0; x < n; x++){
    if(isused_column[x] ||  isused_upward[row + x] || isused_downward[row - x + n])
        continue;
    isused_column[x] = true;
    isused_upward[row + x] = true;
    isused_downward[row - x + n] = true;
    dfs(row + 1);
    isused_column[x] = false;
    isused_upward[row + x] = false;
    isused_downward[row - x + n] = false;     
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  cin >> n;
  dfs(0);
  cout << cnt;
}
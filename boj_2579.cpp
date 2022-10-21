#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;
  vector<int> stair(n + 1);
  for(int i = 1; i <= n; i++)
    cin >> stair[i];

  vector<int> dp(n + 1);
  dp[1] = stair[1];
  dp[2] = stair[1] + stair[2];
  for(int i = 2; i <= n; i++){
    dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
  }

  cout << dp[n];
}
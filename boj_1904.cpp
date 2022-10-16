#include <bits/stdc++.h>
using namespace std;

#define MOD 15746

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin); 

  int n;
  cin >> n;
  vector<int> dp(n + 1);

  dp[1] = 1;
  dp[2] = 2;

  for(int i = 3; i <= n; i++)
    dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
  
  cout << dp[n];
}
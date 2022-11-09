#include <iostream>
#include <algorithm>
#define MAX_N 1000001
using namespace std;

int dp[MAX_N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int n; cin >> n;

  for(int i = 2; i <= n; i++){
    dp[i] = dp[i - 1] + 1;
    if(i % 3 == 0)
      dp[i] = min(dp[i / 3] + 1, dp[i]);
    if(i % 2 == 0)
      dp[i] = min(dp[i / 2] + 1, dp[i]);
  }

  cout << dp[n] << '\n';
}
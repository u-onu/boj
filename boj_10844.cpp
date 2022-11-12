#include <iostream>
#define MAX_N 101
#define MOD (int)1e9
using namespace std;

int dp[10][MAX_N];
int n;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> n;
  for(int i = 1; i <= 9; i++)
    dp[i][1] = 1;

  for(int i = 2; i <= n; i++){
    dp[0][i] = dp[1][i - 1];
    dp[9][i] = dp[8][i - 1];
    for(int j = 1; j <= 8; j++)
      dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % MOD;
  }

  int ans = 0;
  for(int i = 0; i < 10; i++)
    ans = (ans + dp[i][n]) % MOD;
  cout << ans << '\n';
}
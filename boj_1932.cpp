#include <iostream>
#include <cmath>
#define MAX_N 501
using namespace std;

int dp[MAX_N][MAX_N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int n; cin >> n;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++){
      int input; cin >> input;
      dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + input;
    }
  }

  int max_sum = 0;
  for(int i = 1; i <= n; i++)
    max_sum = max(dp[n][i], max_sum);
  
  cout << max_sum << '\n';
}
#include <iostream>
#include <algorithm>
using namespace std;

#define N 10001

int dp[N];
int wine[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int n;
  cin >> n;

  for(int i = 1; i <= n; i++)
    cin >> wine[i];
  
  dp[1] = wine[1];
  dp[2] = wine[1] + wine[2];

  for(int i = 3; i <= n; i++){
    dp[i] = dp[i - 1];
    dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], dp[i]);
    dp[i] = max(dp[i - 2] + wine[i], dp[i]);
  }
  
  cout << dp[n] << '\n';
}
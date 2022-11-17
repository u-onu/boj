#include <iostream>
#include <cmath>
using namespace std;

#define N 31
#define W 15001

int weight[N];
int dp[N][W];
int n;

void init_weight(){
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> weight[i];
}

void init_dp(){
  for(int i = 1; i <= n; i++){
    int w = weight[i];
    dp[i][w] = true;
    for(int j = 1; j < W; j++)
      if(dp[i - 1][j] || dp[i - 1][abs(j - w)] || dp[i - 1][j + w])
        dp[i][j] = true;
  }
}

void solve(){
  int t, x; 
  cin >> t;
  for(int i = 0; i < t; i++){
    cin >> x;
    if(x >= W || dp[n][x] == false)
      cout << 'N' << ' ';
    else
      cout << 'Y' << ' ';
  }
  cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init_weight();
  init_dp();
  solve();
}
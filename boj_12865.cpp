#include <bits/stdc++.h>
#define MAX_N 101
#define MAX_K 100001
using namespace std;

struct item{
  int w, v;
};

struct item items[MAX_N];
int dp[MAX_N][MAX_K];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  // input
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; i++)
    cin >> items[i].w >> items[i].v;
  
  // using up to i items, find max value with weight j; dp[i][j]
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= k; j++){
      // can add item i
      if(j >= items[i].w)
        dp[i][j] = max(dp[i - 1][j - items[i].w] + items[i].v, dp[i - 1][j]);
      // fail to add item i
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  cout << dp[n][k];
}
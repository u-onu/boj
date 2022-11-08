#include <iostream>
#include <cmath>
#define MAX_N 1001
using namespace std;

struct cost{
  int R, G, B;
};

struct cost dp[MAX_N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

   int n; cin >> n;

  int cost_R, cost_G, cost_B;
  for(int i = 1; i <= n; i++){
    cin >> cost_R >> cost_G >> cost_B;
    dp[i].R = min(dp[i - 1].G, dp[i - 1].B) + cost_R;
    dp[i].G = min(dp[i - 1].R, dp[i - 1].B) + cost_G;
    dp[i].B = min(dp[i - 1].R, dp[i - 1].G) + cost_B;
  }

  cout << min(dp[n].R, min(dp[n].G, dp[n].B)) << '\n';
}
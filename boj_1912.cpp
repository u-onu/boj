#include <iostream>
#include <cmath>
#define MAX_N 100001
using namespace std;

int dp[MAX_N] = {-1};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int n; cin >> n;

  int max_sum = -1000;
  for(int i = 1; i <= n; i++){
    int input; cin >> input;
    dp[i] = max(dp[i - 1] + input, input);
    max_sum = max(dp[i], max_sum);
  }

  cout << max_sum << '\n';
}
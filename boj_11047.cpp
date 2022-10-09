#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n, k;
  cin >> n >> k;

  vector<int> coins(n);
  for(int i = 0; i < n; i++)
    cin >> coins[i];
  
  sort(coins.begin(), coins.end(), greater<>());
  int cnt = 0;
  
  for(int i = 0; i < n; i++){
    cnt += k / coins[i];
    k %= coins[i];
  }

  cout << cnt << '\n';
}
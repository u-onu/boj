#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n, m;
  cin >> n >> m;
  vector<int> sum(n + 1);
  sum[0] = 0;

  int input;
  for(int i = 1; i <= n; i++){
    cin >> input;
    sum[i] = sum[i - 1] + input;
  }

  int from, to;
  for(int i = 0; i < m; i++){
    cin >> from >> to;
    cout << sum[to] - sum[from - 1] << '\n';
  }
}
#include <bits/stdc++.h>
using namespace std;

void solve(){
  int x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

  int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  int cond1 = (r1 - r2) * (r1 - r2);
  int cond2 = (r1 + r2) * (r1 + r2);

  if(d == 0){
    if(cond1 == 0) cout << -1 << '\n';
    else cout << 0 << '\n';
  }
  else if(d == cond1 || d == cond2)
    cout << 1 << '\n';
  else if(d > cond1 && d < cond2)
    cout << 2 << '\n';
  else
    cout << 0 << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("init.txt", "r", stdin);

  int t;
  cin >> t;
  for(int i = 0; i < t; i++)
    solve();
}
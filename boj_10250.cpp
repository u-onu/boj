#include <iostream>
using namespace std;

void solve(){
  int h, w, n;
  cin >> h >> w >> n;
  cout << ((n - 1) % h + 1) * 100 + ((n - 1) / h + 1) << '\n';
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int t; cin >> t;
  for(int i = 0; i < t; i++)
    solve();
}
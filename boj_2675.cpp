#include <iostream>
using namespace std;

void solve(){
  int r;
  string s;
  cin >> r >> s;
  
  for(char c: s)
    for(int i = 0; i < r; i++)
      cout << c;
  cout << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int t;
  cin >> t;
  while(t--)
    solve();
}
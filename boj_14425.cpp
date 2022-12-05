#include <iostream>
#include <map>
using namespace std;

map<string, int> s;
int n, m;

void init(){
  cin >> n >> m;
  string input;
  for(int i = 0; i < n; i++){
    cin >> input;
    s[input] = i;
  }
}

void solve(){
  int cnt = 0;
  string x;
  for(int i = 0; i < m; i++){
    cin >> x;
    if(s.count(x) != 0) cnt++;
  }
  cout << cnt << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init();
  solve();
}
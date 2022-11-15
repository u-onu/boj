#include <iostream>
using namespace std;

int cnt;

void hansoo(string& x){
  int k = x.length();
  if(k > 2){
    auto dist = x[1] - x[0];
    for(int i = 0; i < k - 1; i++){
      if(x[i + 1] != x[i] + dist)
        return;
    }
  }
  cnt++;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int n; cin >> n;
  for(int i = 1; i <= n; i++){
    string x = to_string(i);
    hansoo(x);
  }
  cout << cnt << '\n';
}


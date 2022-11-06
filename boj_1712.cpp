#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;
  
  // profit: c * cnt > expense: a + b * cnt
  if(c <= b)
    cout << -1 << '\n';
  else
    cout << a / (c - b) + 1 << '\n';
}
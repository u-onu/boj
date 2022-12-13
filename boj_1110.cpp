#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int n, cur, next, c;
  cin >> n;
  cur = n, next = -1, c = 0;
  while(next != n){
    next = (cur / 10 + cur % 10) % 10;
    next += (cur % 10) * 10;
    cur = next; c++;
  }
  cout << c << '\n';
}
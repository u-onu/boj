#include <iostream>
#include <algorithm>
using namespace std;

#define N 500000

int cards[N];
int n;

void init(){
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> cards[i];
  sort(cards, cards + n);
}

int search(int key){
  int l = 0;
  int r = n - 1;
  while(l <= r){
    int m = (l + r) / 2;
    if(cards[m] == key)
      return 1;
    if(key < cards[m])
      r = m - 1;
    else
      l = m + 1;
  }
  return 0;
}

void solve(){
  int m;
  cin >> m;
  
  int x;
  for(int i = 0; i < m; i++){
    cin >> x;
    cout << search(x) << ' ';
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init();
  solve();
}
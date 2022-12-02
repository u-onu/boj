#include <iostream>
#include <algorithm>
using namespace std;

#define N 1001

int isprime[N];

void init_isprime(){
  fill(isprime, isprime + N, 1);
  isprime[0] = isprime[1] = 0;

  for(int i = 2; i < N; i++){
    if(isprime[i] == 0) continue;
    for(int j = i * 2; j < N; j += i)
      isprime[j] = 0;
  }
}

void solve(){
  int n, x, cnt;
  cin >> n;

  cnt = 0;
  for(int i = 0; i < n; i++){
    cin >> x;
    cnt += isprime[x];
  }

  cout << cnt << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init_isprime();
  solve();
}
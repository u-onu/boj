#include <iostream>
#include <algorithm>
using namespace std;

#define N 300000

int isprime[N];
int cnt_prime[N];

void init(){
  // init isprime
  fill(isprime, isprime + N, 1);
  isprime[0] = isprime[1] = 0;

  for(int i = 2; i < N; i++){
    if(isprime[i] == 0) continue;
    for(int j = i * 2; j < N; j += i)
      isprime[j] = 0;
  }

  // init cnt_prime
  for(int i = 1; i < N; i++)
    cnt_prime[i] = cnt_prime[i - 1] + isprime[i];
}

void solve(){
  int n;
  while(true){
    cin >> n;
    if(n == 0) return;
    cout << cnt_prime[2 * n] - cnt_prime[n] << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init();
  solve();
}
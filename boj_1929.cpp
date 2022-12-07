#include <iostream>
using namespace std;

#define N 1000001
bool isprime[N];

void init_isprime(){
  fill(isprime, isprime + N, true);
  isprime[0] = isprime[1] = false;

  for(int i = 2; i < N; i++){
    if(isprime[i] == true)
      for(int j = i * 2; j < N; j += i)
        isprime[j] = false;
  }
}

void solve(){
  int m, n;
  cin >> m >> n;
  while(m <= n){
    if(isprime[m])
      cout << m << '\n';
    m++;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init_isprime();
  solve();
}
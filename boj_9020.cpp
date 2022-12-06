#include <iostream>
using namespace std;

#define N 10000

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

void print_partition(int n){
  int i = n / 2 + 1;
  while(i--)
    if(isprime[i] && isprime[n - i]){
      cout << i << ' ' << n - i << '\n';
      return;
    }
}

void solve(){
  int t, n;
  cin >> t;
  while(t--){
    cin >> n;
    print_partition(n);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init_isprime();
  solve();
}
#include <iostream>
#define SIZE 1500000 // pisano_period of mod 1e6
#define MOD 1000000
using namespace std;

typedef long long ll;
ll f[SIZE] = {0, 1};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  ll n; cin >> n;
  for(int i = 2; i < SIZE; i++)
    f[i] = (f[i - 1] + f[i - 2]) % MOD;
  cout << f[n % SIZE];
}
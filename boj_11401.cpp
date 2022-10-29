#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll pow(ll x, ll n){
  if(n == 0) return 1;

  if(n % 2 == 1)
    return x * pow(x, n - 1) % MOD;
  else{
    ll half = pow(x, n / 2);
    return half * half % MOD;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  ll n, k;
  cin >> n >> k;

  // A = n*(n-1)*(n-2)* ... *(n-k+1)
  ll A = 1;
  for(int i = n; i >= n - k + 1; i--)
    A = (A * i) % MOD;
  
  // B = k!
  ll B = 1;
  for(int i = k; i >= 1; i--)
    B = (B * i) % MOD;
  
  // (A / B) % p = (A % p) * (B^(p - 2) % p)
  cout << (A * pow(B, MOD - 2)) % MOD;
}
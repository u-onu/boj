#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod;

ll pow(ll x, ll n){
  if(n == 0) return 1;
  
  if(n % 2 == 1) return x * pow(x, n - 1) % mod;
  else{
      ll half = pow(x, n / 2);
      return half * half % mod;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  ll a, b, c;
  cin >> a >> b >> c;
  mod = c;

  cout << pow(a, b);
}
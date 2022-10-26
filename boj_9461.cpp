#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p[101] = {0, 1, 1, 1, 2, 2};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  for(int i = 6; i <= 100; i++)
    p[i] = p[i - 1] + p[i - 5];

  int t, n;
  cin >> t;
  for(int i = 0; i < t; i++){
    cin >> n;
    cout << p[n] << '\n';
  }
}
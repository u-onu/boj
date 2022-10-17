#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> lis(n, 1);

  for(int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < i; j++){
      if(a[i] > a[j]){
        lis[i] = max(lis[j] + 1, lis[i]);
      }
    }
    ans = max(ans, lis[i]);
  }

  cout << ans;
}
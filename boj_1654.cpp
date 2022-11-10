#include <iostream>
#include <algorithm>
#include <climits>
#define MAX_K 10000
using namespace std;

typedef long long ll;
int n, k;
int lines[MAX_K];

void init(){
  cin >> k >> n;
  for(int i = 0; i < k; i++)
    cin >> lines[i];
}

void solve(){
  ll low = 1;
  ll high = INT_MAX;
  ll max_length = 0;

  while(low <= high){
    ll mid = (low + high) / 2;

    int cnt = 0;
    for(int i = 0; i < k; i++)
      cnt += lines[i] / mid;
    
    if(cnt >= n){
      low = mid + 1;
      max_length = max(mid, max_length);
    }
    else
      high = mid - 1;
  }

  cout << max_length << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init();
  solve();
}
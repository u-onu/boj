#include <iostream>
#include <algorithm>
#include <climits>
#define MAX_N 1000000
using namespace std;

typedef long long ll;
int n, m;
int trees[MAX_N];

void init(){
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> trees[i];
}

void solve(){
  ll low = 0;
  ll high = INT_MAX;
  ll max_height = 0;

  while(low <= high){
    ll mid = (low + high) / 2;

    ll sum_length = 0;
    for(int i = 0; i < n; i++)
      sum_length += max(trees[i] - mid, (ll)0);

    if(sum_length >= m){
      max_height = max(mid, max_height);
      low = mid + 1;
    }
    else
      high = mid - 1;
  }
  
  cout << max_height << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init();
  solve();
}
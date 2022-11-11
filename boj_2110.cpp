#include <iostream>
#include <algorithm>
#include <climits>
#define MAX_N 200000
using namespace std;

typedef long long ll;
int n, c;
int pos[MAX_N];

void init(){
  cin >> n >> c;
  for(int i = 0; i < n; i++)
    cin >> pos[i];
  sort(pos, pos + n);
}

void solve(){
  ll low = 0;
  ll high = INT_MAX;
  ll max_dist = 0;

  while(low <= high){
    ll mid = (low + high) / 2;

    int before = pos[0], cnt = 1;
    for(int i = 1; i < n; i++){
      if(before + mid <= pos[i])
        {before = pos[i]; cnt++;}
    }

    if(cnt >= c){
      max_dist = max(mid, max_dist);
      low = mid + 1;
    }
    else
      high = mid - 1;
  }

  cout << max_dist << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init();
  solve();
}
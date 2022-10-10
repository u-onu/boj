#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;
  vector<int> times(n);
  for(int i = 0; i < n; i++)
    cin >> times[i];
  
  sort(times.begin(), times.end());

  int sum_time = 0, before_time = 0;
  for(int i = 0; i < n; i++){
    int cur_time = before_time + times[i];
    sum_time += cur_time;
    before_time = cur_time;
  }

  cout << sum_time;
}
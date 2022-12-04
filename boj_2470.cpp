#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

#define N 100000

int n;
int liquid[N];

void init(){
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> liquid[i];
  sort(liquid, liquid + n);
}

void solve(){
  int left, right, temp, min_abs, res_l, res_r;
  left = 0;
  right = n - 1;
  min_abs = INT_MAX;
  while(left < right){
    temp = liquid[left] + liquid[right];
    if(abs(temp) < min_abs){
      min_abs = abs(temp);
      res_l = left; res_r = right;
      if(min_abs == 0) break;
    }
    if(temp < 0) left++;
    else right--;
  }
  cout << liquid[res_l] << ' ' << liquid[res_r] << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init();
  solve();
}
#include <iostream>
#include <algorithm>
using namespace std;

#define N 100000

int n, x;
int a[N];

void init(){
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  cin >> x;
}

void solve(){
  int cnt, left, right, temp;
  left = 0;
  right = n - 1;
  cnt = 0;
  while(left < right){
    temp = a[left] + a[right];
    if(x == temp){
      cnt++;
      left++; right--;
    }
    else if(x < temp) right--;
    else left++;
  }
  cout << cnt << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init();
  solve();
}
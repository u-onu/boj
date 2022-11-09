#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a;

void init(){
  int n; cin >> n;
  a.resize(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
}

int binary_search(int key){
  int left = 0;
  int right = a.size() - 1;

  while(left <= right){
    int mid = (left + right) / 2;
    if(a[mid] == key)
      return 1;
    else if(a[mid] < key)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return 0;
}

void solve(){
  int m, key;
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> key;
    cout << binary_search(key) << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init();
  solve();
}
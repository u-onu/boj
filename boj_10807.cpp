#include <iostream>
using namespace std;

int cnt[201];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int n, num, v;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num;
    cnt[num + 100]++;
  }
  cin >> v;
  cout << cnt[v + 100] << '\n';
}
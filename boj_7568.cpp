#include <bits/stdc++.h>
using namespace std;

struct record{
  int x, y;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;

  vector<struct record> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].x >> v[i].y;
  }

  vector<int> ranks(n, 1);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(v[i].x < v[j].x && v[i].y < v[j].y)
        ranks[i]++;
    }
  }

  for(int rank: ranks)
    cout << rank << ' ';
}
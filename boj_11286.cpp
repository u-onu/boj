#include <bits/stdc++.h>
using namespace std;

struct compare{
  bool operator()(int x, int y){
    if(abs(x) == abs(y))
      return x > y;
    return abs(x) > abs(y);
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;
  
  int x;
  priority_queue<int, vector<int>, compare> pq;
  for(int i = 0; i < n; i++){
    cin >> x;
    if(x == 0){
      if(pq.empty()) cout << "0\n";
      else{
        cout << pq.top() << '\n';
        pq.pop();
      }
    }
    else pq.push(x);
  }
}
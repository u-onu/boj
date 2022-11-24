#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> q;

void push_x(int x){
  q.push(x);
}

void pop_x(){
  if(q.empty()){
    cout << 0 << '\n';
    return;
  }
  cout << q.top() << '\n';
  q.pop();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
 
  int n;
  cin >> n;

  int x;
  for(int i = 0; i < n; i++){
    cin >> x;

    if(x == 0)
      pop_x();
    else
      push_x(x);
  }
}
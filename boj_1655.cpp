#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  // input
  int n;
  cin >> n;
  vector<int> elements(n);
  for(int i = 0; i < n; i++)
    cin >> elements[i];

  
  priority_queue<int> min_pq, max_pq;
  for(int element: elements){
    // rule 1: max_pq.size() == min_pq.size() or max_pq.size() == min_pq.size() + 1
    if(max_pq.size() > min_pq.size())
      min_pq.push(-element);
    else
      max_pq.push(element);
    
    // rule 2: -min_pq.top() >= max_pq.top()
    if(!min_pq.empty() && !max_pq.empty()){
      if(-min_pq.top() < max_pq.top()){
        int min_top = -min_pq.top(); min_pq.pop();
        int max_top = max_pq.top(); max_pq.pop();

        min_pq.push(-max_top);
        max_pq.push(min_top);
      }
    }

    // print mid value
    cout << max_pq.top() << '\n';
  }

}
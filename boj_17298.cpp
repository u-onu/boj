#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  vector<int> nge(n);
  stack<int> st;
  for(int i = n - 1; i >= 0; i--){
    while(!st.empty() && a[i] >= st.top())
      st.pop();

    if(st.empty()) nge[i] = -1;
    else nge[i] = st.top();
    st.push(a[i]);
  }

  for(int element: nge)
    cout << element << ' ';
}
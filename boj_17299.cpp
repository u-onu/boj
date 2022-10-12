#include <bits/stdc++.h>
using namespace std;

struct data{
  int a, f;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;
  vector<struct data> datas(n);
  vector<int> cnt(1e6 + 1);
  for(int i = 0; i < n; i++){
    int input;
    cin >> input;
    datas[i].a = input;
    cnt[input]++;
  }

  for(int i = 0; i < n; i++)
    datas[i].f = cnt[datas[i].a];
  
  vector<int> ngf(n);
  stack<struct data> st;
  for(int i = n - 1; i >= 0; i--){
    while(!st.empty() && datas[i].f >= st.top().f)
      st.pop();

    if(st.empty()) ngf[i] = -1;
    else ngf[i] = st.top().a;
    st.push(datas[i]);
  }

  for(int ngf_e: ngf)
    cout << ngf_e << ' ';
}
#include <bits/stdc++.h>
using namespace std;

int n, m;
bool isused[10];
vector<int> input;
vector<int> arr;

void dfs(int depth){
  if(depth == m){
    for(int element: arr)
      cout << element << ' ';
    cout << '\n';
    return;
  }

  int previous_num = -1;
  for(int i = 0; i < n; i++){
    if(!isused[i] && input[i] != previous_num){
      arr[depth] = input[i];
      isused[i] = true;
      dfs(depth + 1);
      isused[i] = false;

      previous_num = input[i];
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  cin >> n >> m;
  input.resize(n);
  arr.resize(m);
  for(int i = 0; i < n; i++)
    cin >> input[i];
  
  sort(input.begin(), input.end());
  dfs(0);
}
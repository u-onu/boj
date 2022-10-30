#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;

  char input;
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> input;
    sum += input - '0';
  }

  cout << sum;
}
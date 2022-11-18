#include <iostream>
using namespace std;

#define N 26
#define L 200002

int letters[N][L];

void init_letters(){
  string s;
  cin >> s;

  int len = s.length();
  for(int i = 0; i < len; i++){
    for(int j = 0; j < N; j++)
      letters[j][i + 1] = letters[j][i];
    int temp = s[i] - 'a';
    letters[temp][i + 1]++;
  }
}

void solve(){
  int q; cin >> q;

  char ch;
  int from, to;
  for(int i = 0; i < q; i++){
    cin >> ch >> from >> to;
    cout << letters[ch - 'a'][to + 1] - letters[ch - 'a'][from] << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init_letters();
  solve();
}
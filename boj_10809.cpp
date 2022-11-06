#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  string s;
  cin >> s;

  vector<int> alph(26, -1);
  for(int i = s.length() - 1; i >= 0; i--)
    alph[s[i] - 'a'] = i;

  for(int pos: alph)
    cout << pos << ' ';
}
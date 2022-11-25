#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
 

  vector<int> arr;
  char c;
  while(cin >> c)
    arr.push_back(c - '0');
  sort(arr.begin(), arr.end(), greater<int>());
  for(int x: arr)
    cout << x;
}
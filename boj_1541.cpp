#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  string input;
  cin >> input;

  input.push_back('-'); // end of input is '-'.
  unsigned int minus_index = input.find("-");

  string number = "";
  int min_value = 0;
  for(unsigned int i = 0; i < input.length(); i++){
    if(input[i] == '+' || input[i] == '-'){
      if(i <= minus_index)
        min_value += stoi(number);
      else min_value -= stoi(number);

      number = "";
    }
    else
      number.push_back(input[i]);
  }

  cout << min_value;
}
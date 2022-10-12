#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  string input, bomb_str;
  cin >> input >> bomb_str;
  reverse(input.begin(), input.end());

  stack<char> output;
  for(char c: input){
    output.push(c);

    stack<char> temp;
    for(char bomb_c: bomb_str){
      if(output.empty() || output.top() != bomb_c)
        break;
      output.pop();
      temp.push(bomb_c);
    }

    if(temp.size() != bomb_str.size()){
      while(!temp.empty()){
        output.push(temp.top());
        temp.pop();
      }
    }
  }

  if(output.empty())
    cout << "FRULA";
  else{
    while(!output.empty()){
      cout << output.top();
      output.pop();
    }
  }
}
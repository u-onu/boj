#include <iostream>
using namespace std;

#define MAX_N 1000001

int robot[MAX_N]; // parent
int parts[MAX_N]; // number of parts
int n;

void init(){
  cin >> n;
  for(int i = 1; i < MAX_N; i++){
    robot[i] = i;
    parts[i] = 1;
  }
}

int find_robot(int x){
  if(robot[x] == x)
    return x;
  else
    return robot[x] = find_robot(robot[x]);
}

void union_parts(int x, int y){
  x = find_robot(x);
  y = find_robot(y);
  if(x != y){
    parts[y] += parts[x];
    robot[x] = y;
  }
}

void solve(){
  for(int i = 0; i < n; i++){
    char op;
    cin >> op;

    if(op == 'I'){
      int a, b;
      cin >> a >> b;
      union_parts(a, b);
    }
    else{ // op == 'Q'
      int c;
      cin >> c;
      cout << parts[find_robot(c)] << '\n';
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
 
  init();
  solve();
}
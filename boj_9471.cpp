#include <iostream>
using namespace std;

int pisano_period(int m){
  int r1 = 1; // r1 = F(1) mod m
  int r2 = 1; // r2 = F(2) mod m

  int n = 1; 
  while(!(r1 == 0 && r2 == 1)){
    int temp = (r1 + r2) % m;
    r1 = r2;
    r2 = temp;
    n++;
  }
  return n;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int p;
  cin >> p;

  int n, m;
  for(int i = 0; i < p; i++){
    cin >> n >> m;
    cout << n << ' ' << pisano_period(m) << '\n';
  }
}
#include <iostream>
using namespace std;

int C1, C2;
int f[41];

int fib1(int n){
  if(n == 1 || n == 2)
    {C1++; return 1;}
  return fib1(n - 1) + fib1(n - 2);
}

void fib2(int n){
  f[1] = f[2] = 1;
  for(int i = 3; i <= n; i++)
    {C2++; f[i] = f[i - 1] + f[i - 2];}
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int n; cin >> n;
  fib1(n); fib2(n);
  cout << C1 << ' ' << C2;
}
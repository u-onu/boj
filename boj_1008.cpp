#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  double a, b;
  cin >> a >> b;
  cout.setf(ios::fixed);
  cout.precision(9);
  cout << a / b;
}
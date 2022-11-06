#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int multiplicand, multiplier;
  cin >> multiplicand >> multiplier;

  int res = 0, digit = 1;
  while(multiplier > 0){
    int temp = multiplicand * (multiplier % 10);
    cout << temp << '\n';
    res += digit * temp;
    multiplier /= 10; digit *= 10;
  }
  
  cout << res << '\n';
}
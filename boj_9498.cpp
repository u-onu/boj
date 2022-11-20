#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int score;
  cin >> score;

  int grade = score / 10;
  switch(grade){
    case 10:
    case 9:
      cout << 'A' << '\n';
      break;
    case 8:
      cout << 'B' << '\n';
      break;
    case 7:
      cout << 'C' << '\n';
      break;
    case 6:
      cout << 'D' << '\n';
      break;
    default:
      cout << 'F' << '\n';
      break;
  }
}
#include <iostream>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int king, queen, rook, bishop, knight, pawn;
  cin >> king >> queen >> rook >> bishop >> knight >> pawn;

  cout << 1 - king << ' ';
  cout << 1 - queen << ' ';
  cout << 2 - rook << ' ';
  cout << 2 - bishop << ' ';
  cout << 2 - knight << ' ';
  cout << 8 - pawn << ' ';
}
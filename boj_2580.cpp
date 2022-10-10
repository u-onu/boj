#include <bits/stdc++.h>
using namespace std;

int board[9][9];
vector<struct point> blank_points;
bool isused_row[10][9];
bool isused_column[10][9];
bool isused_box[10][9];
bool print_board;

struct point{
  int y, x;
  point(int y, int x){
    this->y = y;
    this->x = x;
  }
};

void dfs(unsigned int depth){
  if(print_board) return;
  if(depth == blank_points.size()){
    for(int y = 0; y < 9; y++){
      for(int x = 0; x < 9; x++)
        cout << board[y][x] << ' ';
      cout << '\n';
    }
    
    print_board = true;
    return;
  }

  struct point p = blank_points[depth];
  for(int n = 1; n <= 9; n++){
    if(!isused_row[n][p.y] && !isused_column[n][p.x] 
      && !isused_box[n][p.y / 3 + (p.x / 3) * 3]){
        board[p.y][p.x] = n;
        isused_row[n][p.y] = true;
        isused_column[n][p.x] = true;
        isused_box[n][p.y / 3 + (p.x / 3) * 3] = true;
        dfs(depth + 1);
        isused_row[n][p.y] = false;
        isused_column[n][p.x] = false;
        isused_box[n][p.y / 3 + (p.x / 3) * 3] = false;
      }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int number = 0;
  for(int y = 0; y < 9; y++){
    for(int x = 0; x < 9; x++){
      cin >> number;

      if(number == 0)
        blank_points.push_back(point(y, x));
      else{
        board[y][x] = number;
        isused_row[number][y] = true;
        isused_column[number][x] = true;
        isused_box[number][y / 3 + (x / 3) * 3] = true;
      }
    }
  }

  dfs(0);
}
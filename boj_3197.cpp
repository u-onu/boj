#include <bits/stdc++.h>
#define MAX_SIZE 1500
using namespace std;

struct point{
  int y, x;
  point(int y, int x){
    this->y = y, this->x = x;
  }
};

int r, c;
int ly, lx;
char board[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
queue<struct point> water_q, cur_q;

void input(){
  cin >> r >> c;

  char input_c;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> input_c;
      board[i][j] = input_c;

      if(input_c == 'L'){
        ly = i;
        lx = j;
      }
      if(input_c == '.' || input_c == 'L'){
        water_q.push(point(i, j));
      }
    }
  }
}

bool find_swan(){
  queue<struct point> next_q;
  while(!cur_q.empty()){
    struct point temp = cur_q.front();
    cur_q.pop();

    for(int i = 0; i < 4; i++){
      int ny = temp.y + dy[i];
      int nx = temp.x + dx[i];

      if(ny < 0 || ny > r - 1 || nx < 0 || nx > c - 1)
        continue;
      
      if(board[ny][nx] == 'L' && !visited[ny][nx]){
        return true;
      }
      if(board[ny][nx] == '.' && !visited[ny][nx]){
        visited[ny][nx] = true;
        cur_q.push(point(ny, nx));
      }
      if(board[ny][nx] == 'X' && !visited[ny][nx]){
        visited[ny][nx] = true;
        next_q.push(point(ny, nx));
      }
    }
  }

  cur_q = next_q;
  return false;
}

void melt_ice(){
  int water_size = water_q.size();

  while(water_size--){
    struct point temp = water_q.front();
    water_q.pop();

    for(int i = 0; i < 4; i++){
      int ny = temp.y + dy[i];
      int nx = temp.x + dx[i];

      if(ny < 0 || ny > r - 1 || nx < 0 || nx > c - 1)
        continue;
      
      if(board[ny][nx] == 'X'){
        water_q.push(point(ny, nx));
        board[ny][nx] = '.';
      }
    }
  }
}

void solve(){
  cur_q.push(point(ly, lx));
  visited[ly][lx] = true;
  int time = 0;

  while(true){
    if(find_swan()){
      cout << time << '\n';
      return;
    }
    melt_ice();
    time++;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  input();
  solve();
}
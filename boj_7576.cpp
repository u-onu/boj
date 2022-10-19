#include <bits/stdc++.h>
using namespace std;

struct record{
  int y, x, time;
  record(int y, int x, int time){
    this->y = y;
    this->x = x;
    this->time = time;
  }
};

int n, m;
int unripe_tomato_cnt;
vector<vector<int>> box;
queue<struct record> q;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};


int bfs(){
  if(unripe_tomato_cnt == 0)
    return 0;
  
  while(!q.empty()){
    struct record temp = q.front();
    q.pop();
    
    for(int i = 0; i < 4; i++){
      int ny = temp.y + dy[i];
      int nx = temp.x + dx[i];

      if(ny >= 0 && ny < n && nx >= 0 && nx < m){
        if(box[ny][nx] == 0){
          box[ny][nx] = 1;
          unripe_tomato_cnt--;
          if(unripe_tomato_cnt == 0)
            return temp.time;
          q.push(record(ny, nx, temp.time + 1));
        }
      }
    }
  }

  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  cin >> m >> n;
  box.resize(n, vector<int>(m));

  int input;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> input;
      box[i][j] = input;

      if(input == 0)
        unripe_tomato_cnt++;
      else if(input == 1)
        q.push(record(i, j, 1));
    }
  }

  cout << bfs();
}
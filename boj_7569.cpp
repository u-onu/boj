#include <bits/stdc++.h>
using namespace std;

struct record{
  int z, y, x, time;
  record(int z, int y, int x, int time){
    this->z = z;
    this->y = y;
    this->x = x;
    this->time = time;
  }
};

int h, n, m;
int unripe_tomato_cnt;
vector<vector<vector<int>>> box;
queue<struct record> q;
int dz[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dx[6] = {0, 0, 0, 0, 1, -1};


int bfs(){
  if(unripe_tomato_cnt == 0)
    return 0;
  
  while(!q.empty()){
    struct record temp = q.front();
    q.pop();
    
    for(int i = 0; i < 6; i++){
      int nz = temp.z + dz[i];
      int ny = temp.y + dy[i];
      int nx = temp.x + dx[i];

      if(nz >= 0 && nz < h && ny >= 0 && ny < n && nx >= 0 && nx < m){
        if(box[nz][ny][nx] == 0){
          box[nz][ny][nx] = 1;
          unripe_tomato_cnt--;
          if(unripe_tomato_cnt == 0)
            return temp.time;
          q.push(record(nz, ny, nx, temp.time + 1));
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

  cin >> m >> n >> h;
  box.resize(h, vector<vector<int>>(n, vector<int>(m)));

  int input;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < m; k++){
        cin >> input;
        box[i][j][k] = input;

        if(input == 0)
          unripe_tomato_cnt++;
        else if(input == 1)
          q.push(record(i, j, k, 1));
      }
    }
  }

  cout << bfs();
}
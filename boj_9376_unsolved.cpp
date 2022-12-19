#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 102

enum State{
  SPACE, WALL, DOOR
};

struct point{
  int y, x;
  point(int y, int x)
    {this->y = y; this->x = x;}
};

int prison[N][N];
vector<point> prisoners;
int h, w;

int dist_in0[N][N];
int dist_in1[N][N];
int dist_out[N][N];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void init(){
  cin >> h >> w;

  // init prison, prisoners
  memset(prison, SPACE, sizeof(prison));
  prisoners.clear();
  string input;
  for(int i = 1; i <= h; i++){
    cin >> input;
    for(int j = 0; j < w; j++){
      if(input[j] == '*')
        prison[i][j + 1] = WALL;
      else if(input[j] == '#')
        prison[i][j + 1] = DOOR;
      else if(input[j] == '$')
        prisoners.push_back(point(i, j + 1));
    }
  }

  // init dist
  memset(dist_in0, -1, sizeof(dist_in0));
  memset(dist_in1, -1, sizeof(dist_in1));
  memset(dist_out, -1, sizeof(dist_out));
}

void bfs(int dist[N][N], int sy, int sx){
  deque<point> dq;
  dq.push_back(point(sy, sx));
  dist[sy][sx] = 0;

  while(!dq.empty()){
    int cy = dq.front().y;
    int cx = dq.front().x;
    int cost = dist[cy][cx];
    dq.pop_front();

    for(int i = 0; i < 4; i++){
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if(ny < 0 || ny > h + 1 || nx < 0 || nx > w + 1)
        continue;

      int next_state = prison[ny][nx];
      if(next_state == WALL || dist[ny][nx] != -1)
        continue;
      if(next_state == SPACE){
        dist[ny][nx] = cost;
        dq.push_front(point(ny, nx));
      }
      else if(next_state == DOOR){
        dist[ny][nx] = cost + 1;
        dq.push_back(point(ny, nx));
      }
    }
  }
}

void solve(){
  bfs(dist_in0, prisoners[0].y, prisoners[0].x);
  bfs(dist_in1, prisoners[1].y, prisoners[1].x);
  bfs(dist_out, 0, 0);

  int min_doors = 1000000;
  for(int i = 0; i <= h + 1; i++){
    for(int j = 0; j <= w + 1; j++){
      if(prison[i][j] == WALL)
        continue;
      int doors = dist_in0[i][j] + dist_in1[i][j] + dist_out[i][j];
      if(prison[i][j] == DOOR)
        doors -= 2;
      min_doors = min(doors, min_doors);
    }
  }

  cout << min_doors << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int t;
  cin >> t;
  while(t--){
    init();
    solve();
  }
}

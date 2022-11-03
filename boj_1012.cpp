#include <bits/stdc++.h>
#define MAX_SIZE 50
using namespace std;

struct point{
  int y, x;
  point(int y, int x)
    {this->y = y; this->x = x;}
};

int n, m, k;
int field[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void init(){
  memset(field, 0, sizeof(field));
  memset(visited, false, sizeof(visited));
  cin >> n >> m >> k;

  int r, c;
  for(int i = 0; i < k; i++){
    cin >> r >> c;
    field[r][c] = 1;
  }
}

void bfs(int sy, int sx){
  queue<struct point> q;
  q.push(point(sy, sx));
  visited[sy][sx] = true;

  while(!q.empty()){
    int cy = q.front().y;
    int cx = q.front().x;
    q.pop();

    for(int i = 0; i < 4; i++){
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if(ny < 0 || ny > n - 1 || nx < 0 || nx > m - 1)
        continue;

      if(field[ny][nx] == 1 && !visited[ny][nx]){
        visited[ny][nx] = true;
        q.push(point(ny, nx));
      }
    }
  }
}

void solve(){
  int cnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)
      if(field[i][j] == 1 && !visited[i][j])
        {bfs(i, j); cnt++;}
  }
  cout << cnt << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    init();
    solve();
  }
}
#include <bits/stdc++.h>
#define MAX_SIZE 101
using namespace std;

struct point{
  int y, x;
  point(int y, int x){
    this->y = y; this->x = x;
  }
};

struct stick{
  int height;
  char throw_to;
  stick(int height, char throw_to){
    this->height = height;
    this->throw_to = throw_to;
  }
};

int r, c, n;
char cave[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<struct stick> sticks;
vector<struct point> floating_clusters;


void input(){
  cin >> r >> c;
  char input_c;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> input_c;
      cave[i][j] = input_c;
    }
  }

  cin >> n;
  int h;
  for(int i = 0; i < n; i++){
    cin >> h;
    if(i % 2 == 0)
      sticks.push_back(stick(r - h, 'R'));
    else
      sticks.push_back(stick(r - h, 'L'));
  }
}


bool break_mineral(struct stick s){
  if(s.throw_to == 'R'){
    for(int i = 0; i < c; i++){
      if(cave[s.height][i] == 'x'){
        cave[s.height][i] = '.';
        return true;
      }
    }
  }
  else if(s.throw_to == 'L'){
    for(int i = c - 1; i >= 0; i--){
      if(cave[s.height][i] == 'x'){
        cave[s.height][i] = '.';
        return true;
      }
    }
  }

  return false;
}


void visit_fixed_clusters(struct point p){
  queue<struct point> q;
  q.push(p);
  visited[p.y][p.x] = true;

  while(!q.empty()){
    struct point cur = q.front();
    q.pop();
    
    for(int i = 0; i < 4; i++){
      int ny = cur.y + dy[i];
      int nx = cur.x + dx[i];
      if(ny < 0 || ny > r - 1 || nx < 0 || nx > c - 1)
        continue;

      if(cave[ny][nx] == 'x' && !visited[ny][nx]){
        visited[ny][nx] = true;
        q.push(point(ny, nx));
      }
    }
  }
}


void find_floating_clusters(){
  for(int i = 0; i < c; i++){
    if(cave[r - 1][i] == 'x' && !visited[r - 1][i]){
      visit_fixed_clusters(point(r - 1, i));
    }
  }

  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(cave[i][j] == 'x' && !visited[i][j])
        floating_clusters.push_back(point(i, j));
    }
  }
}


int height_from_fixed_cluster(struct point p){
  int height = 0;
  for(int i = p.y + 1; i < r; i++){
    if(cave[i][p.x] == 'x'){
      if(visited[i][p.x]) return height;
      else return -1;
    }
    height++;
  }
  return height;
}


bool cmp_floating_clusters(struct point a, struct point b){
  return a.y > b.y;
}

void drop_floating_clusters(){
  if(floating_clusters.empty()) return;

  int fallen_height = MAX_SIZE - 1;
  for(struct point floating_cluster: floating_clusters){
    int temp = height_from_fixed_cluster(floating_cluster);
    if(temp == -1) continue;
    fallen_height = min(temp, fallen_height);
  }

  sort(floating_clusters.begin(), floating_clusters.end(), cmp_floating_clusters);
  for(struct point floating_cluster: floating_clusters){
    cave[floating_cluster.y][floating_cluster.x] = '.';
    cave[floating_cluster.y + fallen_height][floating_cluster.x] = 'x';
  }
}


void throw_sticks(){
  for(int i = 0; i < n; i++){
    if(break_mineral(sticks[i]) == false)
      continue;
    
    find_floating_clusters();
    drop_floating_clusters();

    floating_clusters.clear();
    memset(visited, false, sizeof(visited));
  }
}


void print_cave(){
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++)
      cout << cave[i][j];
    cout << '\n';
  }
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  input();
  throw_sticks();
  print_cave();
}
#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

struct record{
  int point, time;
  record(int point, int time){
    this->point = point;
    this->time = time;
  }
};

bool visited[MAX];

int bfs(int start_point, int end_point){
  queue<struct record> q;
  q.push(record(start_point, 0));
  visited[start_point] = true;

  while(!q.empty()){
    struct record cur = q.front();
    q.pop();

    if(cur.point == end_point)
      return cur.time;

    int next_point;

    // x - 1
    next_point = cur.point - 1;
    if(next_point >= 0 && !visited[next_point]){
      visited[next_point] = true;
      q.push(record(next_point, cur.time + 1));
    }

    // x + 1
    next_point = cur.point + 1;
    if(next_point < MAX && !visited[next_point]){
      visited[next_point] = true;
      q.push(record(next_point, cur.time + 1));
    }

    // x * 2
    next_point = cur.point * 2;
    if(next_point < MAX && !visited[next_point]){
      visited[next_point] = true;
      q.push(record(next_point, cur.time + 1));
    }    
  }

  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n, k;
  cin >> n >> k;
  cout << bfs(n, k);
}
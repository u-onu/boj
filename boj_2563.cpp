#include <iostream>
using namespace std;

#define W 100
#define B 10

int paper[W][W];

void init_paper(){
  int n; cin >> n;

  int x, y;
  for(int i = 0; i < n; i++){
    cin >> x >> y;

    for(int i = y; i < y + B; i++)
      for(int j = x; j < x + B; j++)
        paper[i][j] = 1;
  }
}

void get_area(){
  int area = 0;
  for(int i = 0; i < W; i++)
    for(int j = 0; j < W; j++)
      area += paper[i][j];
  
  cout << area << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init_paper();
  get_area();
}
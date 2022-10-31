#include <bits/stdc++.h>
#define MOD 1000
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

ll n, b;
matrix A;
matrix ans;

void init(){
  cin >> n >> b;
  A.resize(n, vector<ll>(n));
  ans.resize(n, vector<ll>(n, 0));

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      cin >> A[i][j];
    ans[i][i] = 1;
  }
}

void multiply_matrix(matrix &x, matrix &y){
  matrix temp(n, vector<ll>(n, 0));

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++)
        temp[i][j] += (x[i][k] * y[k][j]);
      temp[i][j] %= MOD;
    }
  }

  copy(temp.begin(), temp.end(), x.begin());
}

void power_matrix(){
  while(b > 0){
    if(b % 2 == 1)
      multiply_matrix(ans, A);
    multiply_matrix(A, A);
    b /= 2;
  }
}

void print_matrix(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      cout << ans[i][j] << ' ';
    cout << '\n';
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  freopen("init.txt", "r", stdin);

  init();
  power_matrix();
  print_matrix();
}
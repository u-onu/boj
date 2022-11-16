#include <iostream>
#include <algorithm>
using namespace std;

#define N 100001
#define INF -10000000

int sum[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int n, k, temp;
  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    cin >> temp;
    sum[i] = sum[i - 1] + temp;
  }

  int max_temp = INF;
  for(int i = k; i <= n; i++)
    max_temp = max(sum[i] - sum[i - k], max_temp);
  
  cout << max_temp << '\n';
}
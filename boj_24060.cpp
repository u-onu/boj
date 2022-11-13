#include <iostream>
#define MAX_N 500000
using namespace std;

int n, k;
int cnt, ans;
int a[MAX_N];
int tmp[MAX_N];

void init();
void merge(int p, int q, int r);
void merge_sort(int p, int r);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init();
  merge_sort(0, n - 1);
  cout << ans << '\n';
}

void init(){
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  cnt = 0; ans = -1;
}


void merge_sort(int p, int r){
  if(p < r){
    int q = (p + r) / 2;
    merge_sort(p, q);
    merge_sort(q + 1, r);
    merge(p, q, r);
  }
}

void merge(int p, int q, int r){
  int i, j, t;

  i = p; j = q + 1; t = 0;
  while(i <= q && j <= r){
    if(a[i] <= a[j])
      tmp[t++] = a[i++];
    else
      tmp[t++] = a[j++];
  }
  while(i <= q)
    tmp[t++] = a[i++];
  while(j <= r)
    tmp[t++] = a[j++];
  
  i = p; t = 0;
  while(i <= r){
    a[i++] = tmp[t++]; cnt++;
    if(cnt == k)
      ans = a[i - 1];
  }
}

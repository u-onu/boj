#include <iostream>
#include <algorithm>
#define MAX_N 10000
using namespace std;

int arr[MAX_N];
int n, k;

void selection_sort(){
  int swap_cnt = 0;

  for(int last = n - 1; last > 0; last--){
    int max_num, max_pos;

    max_num = max_pos = 0;
    for(int i = 0; i <= last; i++)
      if(arr[i] > max_num){
        max_num = arr[i];
        max_pos = i;
      }

    if(last != max_pos){
      arr[max_pos] = arr[last];
      arr[last] = max_num;
      swap_cnt++;

      if(swap_cnt == k){
        cout << arr[max_pos] << ' ' << max_num << '\n';
        return;
      }
    }
  }

  cout << -1 << '\n'; // swap_cnt is less than k
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  
  selection_sort();
}
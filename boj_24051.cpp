#include <iostream>
#define MAX_N 10000
using namespace std;

int n, k;
int a[MAX_N];

void init(){
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> a[i];
}

void insertion_sort(){
  int insert_cnt = 0;

  for(int i = 1; i < n; i++){
    int loc = i - 1;
    int new_item = a[i];

    while(loc >= 0 && new_item < a[loc]){
      a[loc + 1] = a[loc]; insert_cnt++;
      if(insert_cnt == k){
        cout << a[loc + 1] << '\n';
        return;
      }
      loc--;
    }

    if(loc + 1 != i){
      a[loc + 1] = new_item; insert_cnt++;
      if(insert_cnt == k){
        cout << a[loc + 1] << '\n';
        return;
      }
    }
  }

  cout << -1 << '\n'; // insert_cnt is less than k.
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  init();
  insertion_sort();
}
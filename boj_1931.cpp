#include <bits/stdc++.h>
using namespace std;

struct meeting{
  int start, end;
};

bool compare(struct meeting x, struct meeting y){
  if(x.end != y.end)
    return x.end < y.end;
  else
    return x.start < y.start;  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;
  vector<struct meeting> meetings(n);
  for(int i = 0; i < n; i++)
    cin >> meetings[i].start >> meetings[i].end;
  
  sort(meetings.begin(), meetings.end(), compare);

  int cnt = 0, before_end = 0;
  for(int i = 0; i < n; i++){
    if(meetings[i].start >= before_end){
      cnt++;
      before_end = meetings[i].end;
    }
  }

  cout << cnt;
}
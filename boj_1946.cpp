#include <bits/stdc++.h>
using namespace std;

struct grade{
  int document, interview;
};

bool compare_document(struct grade x, struct grade y){
  return x.document < y.document;
}

void solve(){
  int n;
  cin >> n;
  vector<struct grade> applicaants(n);
  for(int i = 0; i < n; i++)
    cin >> applicaants[i].document >> applicaants[i].interview;
  
  sort(applicaants.begin(), applicaants.end(), compare_document);

  int min_interview_grade = n + 1, select_cnt = 0;
  for(struct grade applicant: applicaants){
    if(applicant.interview < min_interview_grade){
      select_cnt++;
      min_interview_grade = applicant.interview;
    }
  }

  cout << select_cnt << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int test_case;
  cin >> test_case;
  for(int t = 0; t < test_case; t++)
    solve();
}
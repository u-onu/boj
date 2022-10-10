#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct gas_station{
  ll price, next_dist;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;
  vector<struct gas_station> gas_stations(n);
  for(int i = 0; i < n - 1; i++)
    cin >> gas_stations[i].next_dist;
  for(int i = 0; i < n; i++)
    cin >> gas_stations[i].price;
  
  ll min_cost = 0, min_price = 1e9;
  for(int i = 0; i < n - 1; i++){
    if(gas_stations[i].price < min_price){
      min_price = gas_stations[i].price;
    }
    min_cost += min_price * gas_stations[i].next_dist;
  }

  cout << min_cost;
}
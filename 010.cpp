#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 998244353, INF = 922337203685477587;
 
int main(){
  ll N;
  cin >> N;
  vector<vector<ll>> p(2, vector<ll>(N + 1, 0));
  for (ll i = 1; i <= N; i++){
    ll ci, pi;
    cin >> ci >> pi;
    ci--;
    p[ci][i] = p[ci][i - 1] + pi;
    p[ci ^ 1][i] = p[ci ^ 1][i - 1];
  }
  
  ll Q;
  cin >> Q;
  for (ll i = 0; i < Q; i++){
    ll l, r;
    cin >> l >> r;
    cout << p[0][r] - p[0][l - 1] << ' ' << p[1][r] - p[1][l - 1] << endl;
  }
}

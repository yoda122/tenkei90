#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 998244353, INF = 922337203685477587;

int main(){
  ll N;
  cin >> N;
  vector<ll> D(N + 1), C(N + 1), S(N + 1);
  vector<pair<ll, ll>> task(N + 1);
  for (ll i = 1; i <= N; i++){
    cin >> D[i] >> C[i] >> S[i];
    task[i] = {D[i], i};
  }
  task[0] = {0, 0};
  sort(task.begin(), task.end());
  
  ll DMAX = 5000;
  vector<vector<ll>> dp(N + 1, vector<ll>(DMAX + 1));
  dp[0][0] = 0;
  for (ll i = 1; i <= N; i++){
    ll idx = task[i].second;

    for (ll j = 0; j <= DMAX; j++){
      dp[i][j] = dp[i - 1][j];
      if (j >= C[idx] && j <= D[idx]){
        if (dp[i - 1][j - C[idx]] != -1){
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - C[idx]] + S[idx]);
        }
      }
    }
  }
  
  ll ans = 0;
  for (ll i = 0; i <= DMAX; i++){
    ans = max(ans, dp[N][i]);
  }
  
  cout << ans << endl;
}

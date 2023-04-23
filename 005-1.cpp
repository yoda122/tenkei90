#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 1000000007, INF = 922337203685477587;
 
int main(){
  ll N, B, K;
  cin >> N >> B >> K;
  vector<ll> C(K);
  for (ll i = 0; i < K; i++){
    cin >> C[i];
  }
  
  vector<vector<ll>> dp(N + 1, vector<ll>(B, 0));
  for (ll i = 0; i < K; i++){
    dp[1][C[i] % B] += 1;
  }
  for (ll i = 1; i < N; i++){
    for (ll j = 0; j < B; j++){
      for (ll k = 0; k < K; k++){
        dp[i + 1][(10 * j + C[k]) % B] += dp[i][j];
        dp[i + 1][(10 * j + C[k]) % B] %= mod;
      }
    }
  }
  
  cout << dp[N][0] << endl;
}

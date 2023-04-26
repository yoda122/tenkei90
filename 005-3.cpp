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
  
  vector<ll> p10(60);
  p10[0] = 10 % B;
  for (ll i = 1; i < 60; i++){
    p10[i] = (p10[i - 1] * p10[i - 1]) % B;
  }
  
  vector<vector<ll>> dp(60, vector<ll>(B, 0));
  for (ll i = 0; i < K; i++){
    dp[0][C[i] % B] += 1;
  }
  for (ll i = 1; i < 60; i++){
    for (ll j = 0; j < B; j++){
      for (ll k = 0; k < B; k++){
        dp[i][(j * p10[i - 1] + k) % B] += (dp[i - 1][j] * dp[i - 1][k]) % mod;
        dp[i][(j * p10[i - 1] + k) % B] %= mod;
      }
    }
  }
  
  vector<ll> ans(B, 0);
  ans[0] = 1;
  for (ll i = 0; i < 60; i++){
    if (N & (1LL << i)){
      vector<ll> nans(B, 0);
      for (ll j = 0; j < B; j++){
        for (ll k = 0; k < B; k++){
          nans[(j * p10[i] + k) % B] += (ans[j] * dp[i][k]) % mod;
          nans[(j * p10[i] + k) % B] %= mod;
        }
      }
      ans = nans;
    }
  }
  
  cout << ans[0] << endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 1000000007, INF = 922337203685477587;
 
int main(){
  ll N;
  string S;
  cin >> N >> S;
  S = "x" + S;
  
  string tar = "atcoder";
  ll tarlen = 8;
  vector<vector<ll>> dp(N + 1, vector<ll>(tarlen, 0));
  dp[0][0] = 1;
  for (ll i = 1; i <= N; i++){
    for (ll j = 0; j < tarlen - 1; j++){
      if (S[i] == tar[j]){
        dp[i][j] += dp[i - 1][j];
        dp[i][j + 1] += dp[i - 1][j];
        dp[i][j] %= mod;
        dp[i][j + 1] %= mod;
      }
      else{
        dp[i][j] += dp[i - 1][j];
        dp[i][j] %= mod;
      }
    }
    dp[i][tarlen - 1] += dp[i - 1][tarlen - 1];
    dp[i][tarlen - 1] %= mod;
  }
  
  cout << dp[N][tarlen - 1] << endl;
}

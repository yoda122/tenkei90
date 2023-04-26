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
  
  vector<vector<vector<ll>>> A(60, vector<vector<ll>>(B, vector<ll>(B, 0)));
  for (ll j = 0; j < B; j++){
    for (ll k = 0; k < K; k++){
      A[0][(10 * j + C[k]) % B][j] += 1;
    }
  }
  
  for (ll i = 1; i < 60; i++){
    for (ll j = 0; j < B; j++){
      for (ll k = 0; k < B; k++){
        for (ll l = 0; l < B; l++){
          A[i][j][k] += A[i - 1][j][l] * A[i - 1][l][k];
          A[i][j][k] %= mod;
        }
      }
    }
  }
  
  vector<ll> ans(B, 0);
  for (ll i = 0; i < K; i++){
    ans[C[i] % B] += 1;
  }
  ll keta = 0;
  N--;
  while (N > 0){
    if (N % 2 == 1){
      vector<ll> nans(B, 0);
      for (ll i = 0; i < B; i++){
        for (ll j = 0; j < B; j++){
          nans[i] += A[keta][i][j] * ans[j];
          nans[i] %= mod;
        }
      }
      ans = nans;
    }
    N /= 2;
    keta++;
  }
  
  cout << ans[0] << endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 998244353, INF = 922337203685477587;
 
int main(){
  ll H, W;
  cin >> H >> W;
  
  vector<vector<ll>> A(H, vector<ll>(W));
  for (ll i = 0; i < H; i++){
    for (ll j = 0; j < W; j++){
      cin >> A[i][j];
    }
  }
  
  vector<ll> sumH(H, 0), sumW(W, 0);
  for (ll i = 0; i < H; i++){
    for (ll j = 0; j < W; j++){
      sumH[i] += A[i][j];
      sumW[j] += A[i][j];
    }
  }
  
  for (ll i = 0; i < H; i++){
    for (ll j = 0; j < W; j++){
      cout << sumH[i] + sumW[j] - A[i][j] << ' ';
    }
    cout << endl;
  }
}

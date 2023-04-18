#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 998244353, INF = 922337203685477587;
 
int main(){
  ll N, L, K;
  cin >> N >> L >> K;
  
  vector<ll> A(N + 2);
  A[0] = 0;
  A[N + 1] = L;
  for (ll i = 1; i <= N; i++){
    cin >> A[i];
  }
  
  ll l = 0, r = L;
  while (r - l > 1){
    ll m = (r + l) / 2;
    ll now = 0, p = 0;
    for (ll i = 1; i <= N + 1; i++){
      now += A[i] - A[i - 1];
      if (now >= m){
        p++;
        now = 0;
      }
    }
    
    if (p >= K + 1){
      l = m;
    }
    else{
      r = m;
    }
  }
  
  cout << l << endl;
}

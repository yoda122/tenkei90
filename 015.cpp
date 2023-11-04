#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 1000000007, INF = 922337203685477587;

ll ruijo(ll a, ll b) {
  ll res = 1;
  for (a %= mod; b; a = a * a % mod, b >>= 1)
    if (b & 1) res = res * a % mod;
  return res;
}

ll Lmax = 100000;//Lの最大値
vector<ll> kaijo(Lmax + 1), kaijorev(Lmax + 1);
 
void Cnum_init(){
  kaijo[0] = 1;
  kaijo[1] = 1;
  for (ll i = 2; i <= Lmax; i++){
    kaijo[i] = (kaijo[i - 1] * i) % mod;
  }
  
  kaijorev[Lmax] = ruijo(kaijo[Lmax], mod - 2);
  for (ll i = Lmax - 1; i >= 0; i--){
    kaijorev[i] = (kaijorev[i + 1] * (i + 1)) % mod;
  }
}
 
ll Cnum(ll L, ll R){
  ll ret = (kaijo[L] * kaijorev[R]) % mod;
  ret *= kaijorev[L - R];
  ret %= mod;
  
  return ret;
}

int main(){
  ll N;
  cin >> N;
  
  Cnum_init();
  
  for (ll k = 1; k <= N; k++){
    ll ans = 0;
    for (ll a = 1; a <= N; a++){
      ll l = N - (k - 1) * (a - 1);
      if (l < a) break;
      
      ans += Cnum(l, a);
      ans %= mod;
    }
    
    cout << ans << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 998244353, INF = 922337203685477587;

int main(){
  ll N;
  cin >> N;
  vector<ll> D(N), C(N), S(N);
  for (ll i = 0; i < N; i++){
    cin >> D[i] >> C[i] >> S[i];
  }
  
  ll ans = 0;
  for (ll bit = 0; bit < (1 << N); bit++){   
    vector<pair<ll, ll>> task(0);
    for (ll j = 0; j < N; j++){
      if (bit & (1 << j)){
        task.push_back({D[j], j});
      }
    }
    sort(task.begin(), task.end());
    
    ll now = 0, rew = 0;
    bool ok = true;
    for (pair<ll, ll> t : task){
      ll idx = t.second;
      if (now + C[idx] <= D[idx]){
        rew += S[idx];
        now += C[idx];
      }
      else{
        ok = false;
        break;
      }
    }
    
    if (ok){
      ans = max(ans, rew);
    }
  }
  
  cout << ans << endl;
}

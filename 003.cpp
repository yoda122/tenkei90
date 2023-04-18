#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 998244353, INF = 922337203685477587;
 
int main(){
  ll N;
  cin >> N;
  vector<vector<ll>> G(N + 1, vector<ll>(0));
  for (ll i = 0; i < N - 1; i++){
    ll a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  ll r;
  for (ll i = 1; i <= N; i++){
    if (G[i].size() == 1){
      r = i;
      break;
    }
  }
  
  vector<ll> dist(N + 1, -1);
  dist[r] = 0;
  queue<ll> que;
  que.push(r);
  while (!que.empty()){
    ll tar = que.front();
    que.pop();
    for (ll k : G[tar]){
      if (dist[k] == -1){
        dist[k] = dist[tar] + 1;
        que.push(k);
      }
    }
  }
  
  ll u, now = -1;
  for (ll i = 1; i <= N; i++){
    if (dist[i] > now){
      u = i;
      now = dist[i];
    }
  }
  
  vector<ll> dist2(N + 1, -1);
  dist2[u] = 0;
  que.push(u);
  while (!que.empty()){
    ll tar = que.front();
    que.pop();
    for (ll k : G[tar]){
      if (dist2[k] == -1){
        dist2[k] = dist2[tar] + 1;
        que.push(k);
      }
    }
  }
  
  ll ans = -1;
  for (ll i = 1; i <= N; i++){
    ans = max(ans, dist2[i]);
  }
  ans++;
  cout << ans << endl;
}

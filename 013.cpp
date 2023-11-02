#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 998244353, INF = 922337203685477587;

int main(){
  ll N, M;
  cin >> N >> M;
  
  vector<vector<pair<ll, ll>>> G(N + 1, vector<pair<ll, ll>>(0));
  for (ll i = 0; i < M; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }
  
  vector<ll> cost1(N + 1, INF);
  priority_queue<pair<ll, ll>> que;
  cost1[1] = 0;
  que.push({0, 1});
  while (!que.empty()){
    pair<ll, ll> p = que.top();
    ll tar = p.second;
    que.pop();
    
    for (pair<ll, ll> k : G[tar]){
      if (cost1[k.first] > cost1[tar] + k.second){
        cost1[k.first] = cost1[tar] + k.second;
        que.push({cost1[k.first] * -1, k.first});
      }
    }
  }
  
  vector<ll> costN(N + 1, INF);
  costN[N] = 0;
  que.push({0, N});
  while (!que.empty()){
    pair<ll, ll> p = que.top();
    ll tar = p.second;
    que.pop();
    
    for (pair<ll, ll> k : G[tar]){
      if (costN[k.first] > costN[tar] + k.second){
        costN[k.first] = costN[tar] + k.second;
        que.push({costN[k.first] * -1, k.first});
      }
    }
  }
  
  for (ll i = 1; i <= N; i++){
    cout << cost1[i] + costN[i] << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 998244353, INF = 922337203685477587;

class UnionFind{
  public:
  vector<ll> par;
  vector<ll> siz;
  
  UnionFind(ll N): par(N), siz(N, 1){
    for (ll i = 0; i < N; i++){
      par[i] = i;
    }
  }
  
  ll root(ll x){
    while (par[x] != x){
      x = par[x];
    }
  
    return x;
  }
 
  void heigo(ll x, ll y){
    ll rx = root(x), ry = root(y);
    if (rx == ry) return;
    
    if (siz[rx] < siz[ry]) swap(rx, ry);
    par[ry] = rx;
    siz[rx] += siz[ry];
  }
  
  ll size(ll x){
    return siz[root(x)];
  }
  
  bool issame(ll x, ll y){
    return root(x) == root(y);
  }
};

int main(){
  ll H, W, Q;
  cin >> H >> W >> Q;
  
  UnionFind uf((H + 1) * (W + 1));
  vector<vector<bool>> field(H + 1, vector<bool>(W + 1, false));
  vector<ll> dx = {1, 0, -1, 0}, dy = {0, -1, 0, 1};
  for (ll q = 0; q < Q; q++){
    ll t;
    cin >> t;
    
    if (t == 1){
      ll r, c;
      cin >> r >> c;
      
      field[r][c] = true;
      for (ll i = 0; i < 4; i++){
        if (r + dy[i] <= H && r + dy[i] >= 1 && c + dx[i] <= W && c + dx[i] >= 1){
          if (field[r + dy[i]][c + dx[i]]){
            uf.heigo((r + dy[i]) * W + (c + dx[i]), r * W + c);
          }
        }
      }
    }
    if (t == 2){
      ll ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      
      if (uf.issame(ra * W + ca, rb * W + cb) && field[ra][ca] && field[rb][cb]){
        cout << "Yes" << endl;
      }
      else{
        cout << "No" << endl;
      }
    }
  }
}

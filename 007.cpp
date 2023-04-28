#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 998244353, INF = 922337203685477587;
 
int main(){
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  
  ll Q;
  cin >> Q;
  vector<ll> B(Q);
  for (ll i = 0; i < Q; i++){
    cin >> B[i];
  }
  
  for (ll i = 0; i < Q; i++){
    auto itr = lower_bound(A.begin(), A.end(), B[i]);
    ll cand = INF;
    if (itr != A.end()){
      cand = min(cand, *itr - B[i]);
    }
    if (itr != A.begin()){
      itr--;
      cand = min(cand, B[i] - *itr);
    }
    cout << cand << endl;
  }
}

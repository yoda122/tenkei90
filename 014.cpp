#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 998244353, INF = 922337203685477587;

int main(){
  ll N;
  cin >> N;
  
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++){
    cin >> A[i];
  }
  for (ll i = 0; i < N; i++){
    cin >> B[i];
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  
  ll ans = 0;
  for (ll i = 0; i < N; i++){
    ans += abs(A[i] - B[i]);
  }
  cout << ans << endl;
}

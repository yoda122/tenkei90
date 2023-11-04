#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 998244353, INF = 922337203685477587;

int main(){
  ll N, A, B, C;
  cin >> N >> A >> B >> C;
  
  ll ans = INF, L = 10000;
  for (ll a = 0; a < L; a++){
    for (ll b = 0; a + b < L; b++){
      ll rem = N - a * A - b * B;
      if (rem < 0) break;
      
      if (rem % C == 0){
        ans = min(ans, a + b + rem / C);
      }
    }
  }
  
  cout << ans << endl;
}

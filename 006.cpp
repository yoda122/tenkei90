#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 998244353, INF = 922337203685477587;
 
int main(){
  ll N, K;
  string S;
  cin >> N >> K >> S;
  
  set<pair<char, ll>> st;
  string ans = "";
  ll pos = -1;
  for (ll i = 0; i < N - K; i++){
    st.insert({S[i], i});
  }
  
  for (ll i = 0; i < K; i++){
    st.insert({S[N - K + i], N - K + i});
    auto itr = st.begin();
    ans += itr->first;
    for (ll j = pos + 1; j <= itr->second; j++){
      st.erase({S[j], j});
    }
    pos = itr->second;
  }
  
  cout << ans << endl;
}

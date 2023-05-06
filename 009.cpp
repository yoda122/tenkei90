#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 998244353, INF = 922337203685477587;
 
int main(){
  ll N;
  cin >> N;
  vector<double> X(N), Y(N);
  for (ll i = 0; i < N; i++){
    cin >> X[i] >> Y[i];
  }
  
  double ans = 0;
  for (ll i = 0; i < N; i++){
    vector<double> ang(0);
    for (ll j = 0; j < N; j++){
      if (i == j) continue;
      
      double a = atan2(Y[j] - Y[i], X[j] - X[i]) * 180 / 3.1415926535;
      if (a < 0) a += 360;
      ang.push_back(a);
    }
    sort(ang.begin(), ang.end());
    
    for (double j : ang){
      double tar = 180 + j;
      if (tar >= 360) tar -= 360;
      auto itr = lower_bound(ang.begin(), ang.end(), tar);
      double cand = 180 - abs(tar - *itr);
      if (itr != ang.begin()){
        itr--;
        cand = max(cand, 180 - abs(tar - *itr));
      }
      ans = max(ans, cand);
    }
  }
  
  cout << fixed << setprecision(10);
  cout << ans << endl;
}

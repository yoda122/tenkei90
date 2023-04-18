#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll z = 0, mod = 998244353, INF = 922337203685477587;
 
vector<string> ans(0);
ll N;
 
void search(string now, ll rem){
  if ((ll)(now.size()) == N){
    if (rem == 0) ans.push_back(now);
  }
  else{
    if (rem > 0){
      search(now + ')', rem - 1);
    }
    search(now + '(', rem + 1);
  }
}
 
int main(){
  cin >> N;
  search("", 0);
  sort(ans.begin(), ans.end());
  for (string s : ans){
    cout << s << endl;
  }
}

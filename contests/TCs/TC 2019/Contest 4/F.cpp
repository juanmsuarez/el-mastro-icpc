#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
   int n; cin >> n;
   while(n--){
      ll x; cin >> x;
      ll res = 0;
      for(ll p=5;p<=x;p*=5) res+=x/p;
      cout << res << endl;
   }
   return 0;
}

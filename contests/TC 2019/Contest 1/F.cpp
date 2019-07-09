#include <bits/stdc++.h>
#define forsn(i,s,n) for(int i = (int) s; i < (int)n;i++)
#define forn(i,n) forsn(i,0,n)
using namespace std;

#define pb emplace_back
#define si(v) (int)((v).size())
#define fst first
#define snd second
typedef  vector<int> vi;
typedef  pair<int,int> pii;

int n,k,a;

int f(int y){
    return (y+1)/(a+1);
}

int main(){
   cin >> n >> k >> a;
   set<pii> s;  
   s.emplace(1,n);
   int m, ships = f(n); cin >> m;
   forn(i,m){
       int x; cin >> x;
       auto l = s.lower_bound(make_pair(x,0));
       if(l == s.end() || l->fst > x) l--;
       int fst = l->fst, snd = l->snd;
       ships -= f(snd-fst+1);
       int r1 = x-1-fst+1, r2 = snd-(x+1)+1;
       ships += f(r1) + f(r2);
       if(ships < k) return cout << i+1 << endl, 0;
       s.erase(l);
       if(r1 > 0) s.emplace(fst,x-1);
       if(r2 > 0) s.emplace(x+1,snd);
   }
   return cout << "-1\n", 0;
}

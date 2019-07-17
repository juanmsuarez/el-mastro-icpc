
#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(int i = (int)s; i < (int) n;i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i = (int)(n-1); i >= (int) s;i--)
#define dforn(i,n) dforsn(i,0,n)
#define si(a) ((int)(a).size())
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
using pii = pair<int,int>;
using ll = long long int;
using vi = vector<int>;


int main(){
        fastio;

        string s;
        cin >> s;
        ll white=0;
        ll res=0;
        dforn(i,si(s)){
            if(s[i]=='W')white++;
            else res+=white;
        }

        cout << res << endl;


        return 0; 
}

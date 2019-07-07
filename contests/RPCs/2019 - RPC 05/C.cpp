#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define D(a) cerr << #a << " = " << a << endl
#else
	#define D(a)
	#define cerr false && cerr
#endif
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define dforsn(i,s,n) for(int i=int(n-1);i>=int(s);i--)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) dforsn(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define all(a) a.begin(),a.end()
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define snd second
#define fst first
#define endl '\n'
using pii = pair<int,int>;
using vi = vector<int>;
using ll = long long;

#define entry pair<ll,pii>

int main() {
	fastio;
	
    int n,m;
    cin >> n >> m;

    if((ll(n)*ll(n-1))/2 < m){
        cout << "no" << endl;
    }
    else{
        D("jaja");
        vector<ll> seq(n);
        forn(i,n){
            cin >> seq[i];
        }
        vector<ll> difs(m);
        int ind=0;
        priority_queue<entry>pq;
        forn(i,n-1){
            entry a(-(seq[i+1]-seq[i]),pii(i,i+1));
            pq.push(a);
        }
        while(ind<m){
            entry a = pq.top();
            pq.pop();
            difs[ind++]= -a.fst;
            pii p = a.snd;
            p.snd++;
            if(p.snd<n){
                entry b(-(seq[p.snd]-seq[p.fst]),p);
                pq.push(b);  
            } 
        }
        sort(all(difs));
        #ifdef LOCAL
            forn(i,m)cerr <<difs[i] << " ";
            cerr << endl;
        #endif

        bool res = true;
        vector<ll> wires(m);
        forn(i,m){ 
            cin >> wires[i]; 
        }
        sort(all(wires));
        forn(i,m){
            res &= (wires[i] >= difs[i]);
        }
        cout << (res?"yes":"no") << endl;
    }


	
	return 0;
}


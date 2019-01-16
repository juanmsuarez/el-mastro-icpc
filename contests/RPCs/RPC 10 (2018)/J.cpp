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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

int main() {
	fastio;

    int m,g;
    while(cin >> m >> g){
        int c;
        cin >> c;
        vi incop(c);
        forn(i,c){
            int I;
            cin >> I;          
            forn(j,I){
                int ci;
                cin >> ci;
                incop[i]|= (1<<(ci-1));
            }
        }
        vi group(g);
        forn(i,g){
            int L;
            cin >> L;
            forn(j,L){
                int gi;
                cin >> gi;
                group[i]|=(1<<(gi-1));
            }
        }

        int maxgroups=0,minmel=0;
        for(int bm=0;bm< (1<<m);bm++){
            bool compat=true;
            for(int i:incop){
                compat= compat&& __builtin_popcount(bm&i)<=1;
            }
            if(compat){
                int cantg=0;
                for(int gr:group){
                    if(gr&bm)cantg++;
                }
                if(cantg>maxgroups){
                    maxgroups=cantg;
                    minmel=__builtin_popcount(bm);
                }
                else if(cantg==maxgroups){
                    minmel = min(minmel,__builtin_popcount(bm));
                }
            }
        }
        cout << maxgroups << " " << minmel << endl;
    }

	return 0;
}

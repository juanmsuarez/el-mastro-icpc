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

const int MAXN = 1000+10;
int lp[MAXN+1],P[MAXN+1],sp=0; // prime_density(n) ~= n/ln(n)

void sieve(){ // O(N)
	forsn(i,2,MAXN+1){
		if(lp[i] == 0) lp[i] = i, P[sp++] = i;
		for(int j=0; j < sp && P[j] <= lp[i] && i*P[j] <= MAXN; j++) lp[i*P[j]] = P[j]; 
	}
}

struct factnum{
    vi exps;

    factnum(int x){
        exps = vi(MAXN,0);
        while(x != 1) exps[lp[x]]++, x /= lp[x];
    }

    void mult(int x){
        while(x != 1) exps[lp[x]]++, x /= lp[x];
    }
    void mult(factnum x){
        forn(i,MAXN)exps[i]+=x.exps[i];
    }
    void div(int x){
        while(x != 1) exps[lp[x]]--, x /= lp[x];
    }
    void div(factnum x){
        forn(i,MAXN)exps[i]-=x.exps[i];
    }
    bool dividedBy(factnum x){
        forsn(i,2,MAXN)if(x.exps[i]>exps[i])return false;
        return true;
    }
    bool one(){
        forsn(i,2,MAXN)if(exps[i])return false;
        return true;        
    }
    ll val(){
        ll res = 1; 
        forsn(i,2,MAXN){
            forn(j,exps[i])res*=i;
        }
        return res;
    }
};
int N;
vi best;


void factorialize(factnum n,vi act){
    //cerr << n.val() << endl;
    if(n.one()){
        if(!si(best) ||si(best)>si(act))best=act;
        return;
    }
    int last;
    dforsn(i,2,MAXN)
        if(n.exps[i]){last=i;break;}
    //D(last);

    factnum guess(1);
    forsn(i,2,last)guess.mult(i);
    int ind = last;
    guess.val();
    if(n.dividedBy(guess)){
        //cerr << "Im in B)"<<endl;
        n.div(guess);
        while(n.dividedBy(factnum(ind))&&(lp[ind]!=ind||n.exps[ind])&&ind!=N){
            //D(ind);
            n.div(ind);
            guess.mult(ind);
            act.pb(ind);
            factorialize(n,act); 
            act.pop_back();
            ind++;
        }
    } 
}
void factorialize(int n){
    factnum nf(1);
    forsn(i,2,n+1)nf.mult(i);
    factorialize(nf,vi());
}

int main() {
	fastio;
	
    int n;
    cin >> n;
    N=n;


    sieve();
    factorialize(n);
	
    if(si(best)){
        sort(all(best));
        cout << n << "! = ";
        string s = "";
        for(int a:best){
            cout << s << a<< "!";
            s = " * ";
        }
        cout << endl;
    }
    else cout << "No solution" << endl;


	return 0;
}


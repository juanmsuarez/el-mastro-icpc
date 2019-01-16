#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)((n)-1);i>=int(s);i--)
#define si(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define endl '\n'
#ifdef LOCAL
    #define DBG(a) cerr << #a << "=" << a << endl
#else
    #define DBG(a)
#endif
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int ll;

const int MAXP = 1e7;

int criba[MAXP+1];
void crearcriba(){
	int w[] = {4,2,4,2,4,6,2,6};
	for(int p=25;p<=MAXP;p+=10) criba[p]=5;
	for(int p=9;p<=MAXP;p+=6) criba[p]=3; 
	for(int p=4;p<=MAXP;p+=2) criba[p]=2;
	for(int p=7,cur=0;p*p<=MAXP;p+=w[cur++&7]) if (!criba[p]) 
		for(int j=p*p;j<=MAXP;j+=(p<<1)) if(!criba[j]) criba[j]=p;
    criba[0]=criba[1]=1;
}

int main() {
    fastio;

    crearcriba();

    int k; string n;
    while (cin >> k >> n) {
        int act;
        bool can = true;
        //cerr << n << endl;
        for (int i = 0; i < si(n); i += k) {
            act = 0;
            //cerr << i << endl;
            forsn(j, i, i+k) act = act*10+(n[j]-'0');
            //cerr << "chequeo " << act << endl;
            if (criba[act]) {
                //cerr << "no es " << endl;
                can = false;
                break;
            }
        }
        cout << (can ? ":)" : ":(") << endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forsn(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
using ll = long long;

const int A = 1e6;
int lp[A+1], P[A+1], elp[A+1], d[A+1];

void sieve() {
	int sp = 0;
	forsn(i, 2, A+1) {
		if (lp[i] == 0) lp[i] = i, P[sp++] = i;
		for (int j = 0; j < sp && P[j] <= lp[i] && i*P[j] <= A; j++) lp[i*P[j]] = P[j];
	}
}

void precalc() {
    d[1] = 1;
    forsn(n, 2, A+1) {
        int m = n / lp[n];
        if (lp[n] == lp[m]) {
            elp[n] = elp[m]+1;
            d[n] = d[m] / (elp[m] + 1) * (elp[n] + 1);
        }
        else {
            elp[n] = 1;
            d[n] = d[m] * (elp[n] + 1);
        }
    }
}

int main(){
    fastio;

	sieve();
    precalc();

	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;

        int g = __gcd(a, b);
		cout << d[g] << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n-1);i>=int(s);i--)
#define si(a) ((int)(a).size())
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int tint;

int phi (int n) {
	int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            result -= result / i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    if (n > 1)
        result -= result / n;

    return result;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	#ifdef LOCAL 
		freopen("in.txt","r",stdin); 
	#endif
	
	tint k;
	cin >> k;
	
	if (k == 1) {
		cout << "0/1" << endl;
		return 0;
	}
	else
		k--;
	
	tint j = 1;
	tint sum = phi(1), pre = 0;
	
	while (sum < k) {
		j++;
		pre = sum;
		sum += phi(j);
	}
	
	tint i = 1;
	while (pre < k) {
		if (__gcd(i,j)==1)
			pre++;
		i++;
	}
	
	if (i > 0) i--;
	
	cout << i << '/' << j << endl;

	return 0;
}
	

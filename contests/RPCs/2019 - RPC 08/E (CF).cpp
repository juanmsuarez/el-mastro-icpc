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

int damage, initial_health_sum;
map<pair<vi, vi>, double> memo;

void normalize(vi &minions) {
    sort(all(minions));
    if (minions.front() == 0) minions.erase(minions.begin());
}

void deal_damage(vi &minions, int pos) {
    minions[pos]--;
    normalize(minions);
}

int health_sum(vi &minions_a, vi &minions_b) {
    int sum = 0;
    for (int &health : minions_a) sum += health;
    for (int &health : minions_b) sum += health;
    return sum;
}

double dp(vi a, vi b) {
    if (b.empty()) return 1;
    if (initial_health_sum - damage == health_sum(a, b)) return 0;

    auto state = mp(a, b);

    if (memo.count(state)) return memo[state];
    double &ans = memo[state];
    
    int n = si(a), m = si(b);
    double transition_prob = 1. / (n + m); 

    forn(i, n) {
        vi na = a; deal_damage(na, i); 
        ans += transition_prob * dp(na, b);
    }

    forn(i, m) {
        vi nb = b; deal_damage(nb, i);
        ans += transition_prob * dp(a, nb);
    }

    return ans;
}

int main() {
	fastio;
	
    int n, m; cin >> n >> m >> damage;
    vi minions_a(n); for (int &health : minions_a) cin >> health;
    vi minions_b(m); for (int &health : minions_b) cin >> health;

    sort(all(minions_a));
    sort(all(minions_b));

    initial_health_sum = health_sum(minions_a, minions_b);

    cout << dp(minions_a, minions_b) << endl;
	
	return 0;
}

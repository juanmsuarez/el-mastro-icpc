#include <bits/stdc++.h>
using namespace std;

const int B = 12, Z = 102;
const int TRY = 2*Z;

typedef __int128 ll;
const ll INF = ll(1)<<100;

void print(ll x) {
    if (x < 10) cout << int(x);
    else {
        print(x/10);
        cout << int(x%10);
    }
}

int b, z, s[B], f[B][Z];
pair<ll,ll> ans;
ll mod[B], rest[B][Z];

ll gcd(ll a, ll b) { return a ? gcd(b%a,a) : b; }

pair<ll,ll> chinese(int zoo) {
    ll r = 0, m = 1;
    for (int i = 0; i < b; i++) {
        ll ri = rest[i][zoo], mi = mod[i], iter = mi;
        while (iter-- && r % mi != ri) r += m;
        if (r % mi != ri) return make_pair(INF,INF);
        m = m / gcd(m,mi) * mi;
    }
    return make_pair(r,m);
}

int main() {
    cin >> b >> z;
    for (int i = 0; i < b; i++) {
        cin >> s[i]; --s[i];
        for (int j = 0; j < z; j++) 
            cin >> f[i][j], f[i][j]--;
    }
    ans = make_pair(INF,INF);

    vector<int> pos(&s[0], &s[b]);
    for (int t = 0; t < TRY; ++t) {
        bool allEq = 1;
        for (int i = 1; i < b; i++) allEq &= pos[i] == pos[0];
        if (allEq) ans = min(ans, make_pair(ll(t), ll(pos[0])));
        for (int i = 0; i < b; i++) pos[i] = f[i][pos[i]];
    }

    memset(rest, -1, sizeof rest);
    for (int i = 0; i < b; i++) {
        vector<int> list, used(z, -1);
        int s = ::s[i], t = 0;
        auto &f = ::f[i];
        while (used[s] == -1) {
            list.push_back(s);
            used[s] = t++;
            s = f[s];
        }
        mod[i] = t - used[s];
        for (int j = used[s]; j < t; j++) 
            rest[i][list[j]] = j%mod[i];
    }

    for (int zoo = 0; zoo < z; zoo++) {
        auto cand = chinese(zoo);
        while (cand.first < TRY) cand.first += cand.second;
        ans = min(ans, make_pair(cand.first, ll(zoo)));
    }

    if (ans.first == INF) cout << "*"; 
    else {
        print(ans.second+1);
        cout << ' ';
        print(ans.first);
    }
    return 0;
}

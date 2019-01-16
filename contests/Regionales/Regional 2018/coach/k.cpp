#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const vi BAD = {};

pair<vi,vi> part(const vi &v, int d) {
    int n = v.size();
    vi cls(n,-1);
    int j = 0;
    for (int i = 0; i < n; i++) if (cls[i] == -1) {
        j = max(j, i+1);
        while (j < n && (v[j]-v[i] < d || cls[j] != -1)) ++j;
        if (j < n && cls[j] == -1 && v[j]-v[i] == d) {
            cls[i] = 0; cls[j] = 1;
        }
        else return make_pair(BAD, BAD);
    }
    vi a[2];
    for (int i = 0; i < n; i++) a[cls[i]].push_back(v[i]);
    return make_pair(a[0], a[1]);
}

vector<vi> ans;
vi tmp;
void go(const vi &v) {
    if (v == BAD) return;
    if (v.size() == 1) {
        if (v[0] == 0) ans.push_back(tmp);
        return;
    }
    auto d = v[1] - v[0];
    vi plus, minus; tie(plus, minus) = part(v,d);

    tmp.push_back(+d); go(plus); tmp.pop_back();
    tmp.push_back(-d); go(minus); tmp.pop_back();
}

int main() {
    int n; cin >> n;
    vector<int> v(1<<n);
    for (int i = 0; i < int(1<<n); i++) cin >> v[i];
    sort(v.begin(), v.end());
    go(v);
    for (auto &v : ans) sort(v.begin(), v.end());
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (auto &v : ans) {
        for (int i = 0; i < n; i++) 
            cout << v[i] << (i+1 == n ? '\n' : ' ');
    }
    return 0;
}


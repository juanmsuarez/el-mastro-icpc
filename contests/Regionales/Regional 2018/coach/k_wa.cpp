#include <bits/stdc++.h>
using namespace std;

vector<int> go(const vector<int> &v, int d) {
    vector<int> ans;
    int n = v.size();
    vector<bool> used(n);
    int j = 0;
    for (int i = 0; i < n; i++) if (!used[i]) {
        while (j <= i) ++j;
        while (j < n && v[j]-v[i] < d) ++j;
        if (j < n && v[j]-v[i] == d) {
            used[j] = 1;
            ans.push_back(v[j]);
        }
        else return vector<int>();
    }
    return ans;
}

vector<vector<int>> all;
vector<int> ans;
void go(vector<int> v) {
    if (v.size() == 1) {
        if (v[0] == 0) all.push_back(ans);
        return;
    }

    auto d = v[1] - v[0];
    if (binary_search(v.begin(), v.end(), -d)) {
        auto nv = go(v, d);
        if (!nv.empty()) {
            ans.push_back(-d);
            go(nv);
            ans.pop_back();
        }
    }

    if (binary_search(v.begin(), v.end(), +d)) {
        for (auto &x : v) x = -x;
        reverse(v.begin(), v.end());
        auto nv = go(v, d);
        if (!nv.empty()) {
            for (auto &x : nv) x = -x;
            reverse(nv.begin(), nv.end());
            ans.push_back(+d);
            go(nv);
            ans.pop_back();
        }
    }
}

int main() {
    int n; cin >> n;
    vector<int> v(1<<n);
    for (int i = 0; i < (1<<n); i++) cin >> v[i];
    sort(v.begin(), v.end());
    go(v);
    for (auto &v : all) sort(v.begin(), v.end());
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (auto &v : all) {
        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}

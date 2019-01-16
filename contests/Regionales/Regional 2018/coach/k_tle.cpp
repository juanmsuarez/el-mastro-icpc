#include <bits/stdc++.h>
using namespace std;

multiset<int> from_left(multiset<int> c, int d) {
    multiset<int> ans;
    while (!c.empty()) {
        auto mn = *c.begin(), nxt = mn+d;
        if (c.count(nxt)) {
            ans.insert(nxt);
            c.erase(c.find(mn));
            c.erase(c.find(nxt));
        }
        else {
            ans.clear();
            return ans;
        }
    }
    return ans;
}

multiset<int> from_right(multiset<int> c, int d) {
    multiset<int> ans;
    while (!c.empty()) {
        auto mx = *c.rbegin(), prv = mx-d;
        if (c.count(prv)) {
            ans.insert(prv);
            c.erase(c.find(mx));
            c.erase(c.find(prv));
        }
        else {
            ans.clear();
            return ans;
        }
    }
    return ans;
}

vector<vector<int>> all;
vector<int> ans;
void go(multiset<int> c) {
    if (c.size() == 1) {
        if (*c.begin() == 0) all.push_back(ans);
        return;
    }
    auto d = *(++c.begin()) - *c.begin();
    auto lft = from_left(c,d);
    if (!lft.empty() && c.count(-d)) {
        ans.push_back(-d);
        go(lft);
        ans.pop_back();
    }

    auto rgt = from_right(c,d);
    if (!rgt.empty() && d && c.count(+d)) {
        ans.push_back(+d);
        go(rgt);
        ans.pop_back();
    }
}

int main() {
    multiset<int> c;
    int n; cin >> n;
    int iter = 1<<n; while (iter--) {
        int x; cin >> x;
        c.insert(x);
    }
    go(c);
    for (auto &v : all) sort(v.begin(), v.end());
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (auto v : all) {
        string sep = "";
        for (auto x : v) {
            cout << sep << x;
            sep = " ";
        }
        cout << endl;
    }
    return 0;
}

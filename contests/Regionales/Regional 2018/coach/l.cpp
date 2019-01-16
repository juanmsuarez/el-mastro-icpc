#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int bit[N];
void add(int x) { while (x < N) bit[x]++, x += x&(-x); }
int get(int x) { 
    int ans = 0; 
    while (x) ans += bit[x], x -= x&(-x); 
    return ans;
}

struct query {
    int ind, n;
};

int q, maxdiv[N];
vector<int> toadd[N];
vector<query> qs[N];

int main() {
    fill_n(maxdiv, N, 1);
    for (int d = 2; d < N; d++) {
        if (maxdiv[d] == 1) {
            for (int x = d; x < N; x += d)
                maxdiv[x] = max(maxdiv[x], d);
        }
    }
    for (int x = 2; x < N; x++) toadd[maxdiv[x]].push_back(x);

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int n,d; scanf("%d %d", &n, &d);
        qs[d].emplace_back((query){i,n});
    }

    vector<int> ans(q);
    for (int p = 2; p < N; p++) {
        for (auto x : toadd[p]) add(x);
        for (auto &qi : qs[p]) ans[qi.ind] = get(qi.n);
    }
    for (auto x : ans) printf("%d\n", x);
    return 0;
}

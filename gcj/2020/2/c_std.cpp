#include <bits/stdc++.h>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef pair<llong, llong> pll;

struct cmp {
    bool operator()(pll a, pll b) {
        return a.fs * b.se - a.se * b.fs < 0;
    }
};

int n;
pll P[101];
int par[101];
int sz[101];

int find(int x) {
    if (par[x]) return par[x] = find(par[x]);
    return x;
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    par[y] = x;
    sz[x] += sz[y];
    sz[y] = 0;
}

int solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> P[i].fs >> P[i].se;
    }
    map<pll, vector<pll>, cmp> mp;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            pll d = pll(P[i].fs - P[j].fs, P[i].se - P[j].se);
            if (d.se < 0) d.fs *= -1, d.se *= -1;
            else if (d.se == 0 && d.fs < 0) d.fs *= -1;
            mp[d].emplace_back(i, j);
        }
    }
    int ans = 2;
    for (auto _ : mp) {
        for (int i = 1; i <= n; ++i) {
            par[i] = 0;
            sz[i] = 1;
        }
        for (pll i : _.se) {
            merge(i.fs, i.se);
        }
        priority_queue<int> E, O;
        for (int i = 1; i <= n; ++i) {
            if (sz[i] <= 1) continue;
            ((sz[i] & 1) ? O : E).push(sz[i]);
        }
        int m = 2;
        while (int(O.size()) > 1) {
            E.push(O.top() - 1); O.pop();
            E.push(O.top() - 3); O.pop();
            m += 4;
        }
        if (int(O.size()) > 1 && !E.empty() && E.top() > 5) {
            int x = E.top(); E.pop();
            E.push(O.top() - 1); O.pop();
            E.push(O.top() - 1); O.pop();
            E.push(x - 6);
            m += 8;
        }
        while (!O.empty()) m += O.top() / 2 * 2, O.pop();
        while (!E.empty()) m += E.top() / 2 * 2, E.pop();
        ans = max(ans, m);
    }
    return min(ans, n);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}

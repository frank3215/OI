#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 305, MOD = 1000000007;
ll modpow(ll a, int b) {
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
    }
    return res;
}
ll inv[MAXN], tmp[MAXN];
struct Poly {
    vector<int> po;
    int n;
    Poly(int m = 0) { po.resize(n = m); }
    int &operator[](int x) { return po[x]; }
    const int &operator[](int x) const { return po[x]; }
    Poly operator+(const Poly &p) const {
        Poly r(max(n, p.n));
        for (int i = 0; i < r.n; i++) r[i] = ((i < n ? po[i] : 0) + (i < p.n ? p[i] : 0)) % MOD;
        return r;
    }
    Poly operator*(const Poly &p) const {
        Poly r(n + p.n - 1);
        for (int i = 0; i < p.n; i++) tmp[i] = p[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p.n; j++) r[i + j] = (tmp[j] * po[i] + r[i + j]) % MOD;
            for (int j = 1; j < p.n; j++) tmp[j - 1] = (tmp[j - 1] + tmp[j] * j) % MOD;
        }
        return r;
    }
    Poly inter() const {
        Poly r(n + 1);
        for (int i = 0; i < n; i++) r[i + 1] = po[i] * inv[i + 1] % MOD;
        return r;
    }
    ll operator()(int x) const {
        ll res = 0, mul = 1;
        for (int i = 0; i < n; i++) {
            res = (res + mul * po[i]) % MOD;
            mul = mul * (x - i + MOD) % MOD;
        }
        return res;
    }
};
struct Func {
    vector<Poly> p;
    vector<int> x;
    Func op(const Func &f, int tp) const {
        Func r;
        int sa = x.size(), sb = f.x.size();
        for (int a = 0, b = 0, pos = 0;;) {
            r.x.push_back(pos);
            r.p.push_back(tp ? p[a] * f.p[b] : p[a] + f.p[b]);
            if (a + 1 == sa && b + 1 == sb)
                break;
            if (b + 1 == sb || (a + 1 < sa && x[a + 1] < f.x[b + 1]))
                pos = x[++a];
            else
                pos = f.x[++b];
            while (a + 1 < sa && x[a + 1] <= pos) ++a;
            while (b + 1 < sb && f.x[b + 1] <= pos) ++b;
        }
        return r;
    }
    Func lim(int a, int b) const {
        Func r;
        Poly o(1);
        r.p.push_back(o), r.x.push_back(0);
        int t = x.size();
        for (int i = 0; i < t; i++)
            if (x[i] <= b && (i + 1 == t || x[i + 1] > a)) {
                r.p.push_back(p[i]);
                r.x.push_back(max(x[i], a));
            }
        r.x.push_back(b + 1);
        r.p.push_back(o);
        return r;
    }
    Func inter() {
        int t = x.size();
        Func f;
        for (int i = 0; i < t; i++) {
            f.p.push_back(p[i].inter());
            f.x.push_back(x[i]);
            if (i > 0)
                f.p[i][0] = (f.p[i][0] - f.p[i](x[i]) + f.p[i - 1](x[i]) + MOD) % MOD;
        }
        return f;
    }
    ll sum() { return inter().p.back()[0]; }
} f[10005];
int vis[305][305], A[305], B[305], tot, n;
void dfs(int l, int r) {
    if (vis[l][r])
        return;
    int now = vis[l][r] = ++tot;
    Poly p(1);
    f[tot].p.push_back(p);
    f[tot].x.push_back(0);
    if (l > r) {
        f[tot].p[0][0] = 1;
        return;
    }
    for (int i = l; i <= r; i++)
        if (abs((r - i) - (i - l)) <= 2) {
            dfs(l, i - 1);
            dfs(i + 1, r);
            Func a = f[vis[l][i - 1]], b = f[vis[i + 1][r]];
            if (l < i)
                a = a.op(a.inter(), 0);
            if (i < r)
                b = b.inter();
            f[now] = f[now].op(a.op(b, 1).lim(A[i], B[i]), 0);
        }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", A + i, B + i);
    inv[1] = 1;
    for (int i = 2; i < 305; i++) inv[i] = MOD - (ll)MOD / i * inv[MOD % i] % MOD;
    dfs(1, n);
    printf("%lld\n", f[vis[1][n]].sum());
    return 0;
}

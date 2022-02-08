#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+10, maxt = 2*maxn*20;

int n, rt1[maxn], rt2[maxn];

struct seg{
	int t[maxt], ls[maxt], rs[maxt], tot;
	void clear() {
		memset(t, 0, sizeof(t));
		memset(ls, 0, sizeof(ls));
		memset(rs, 0, sizeof(rs));
		tot = 0;
	}
	int add(int u, int l, int r, int x) {
		int v = ++tot;
		assert(tot < maxt);
		t[v] = t[u], ls[v] = ls[u], rs[v] = rs[u];
		if (l == r) {
			++t[v];
			return v;
		}
		int m = l+r>>1;
		if (x <= m) ls[v] = add(ls[v], l, m, x);
		else rs[v] = add(rs[v], m+1, r, x);
		t[v] = t[ls[v]]+t[rs[v]];
		return v;
	}
	int query(int u, int v, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return t[v]-t[u];
		}
		int ret = 0;
		int m = (l+r)>>1;
		if (L <= m) ret += query(ls[u], ls[v], l, m, L, R);
		if (R > m) ret += query(rs[u], rs[v], m+1, r, L, R);
		return ret;
	}
}s;

struct graph{
	int head[maxn], to[maxn<<1], nxt[maxn<<1], tot;
	int fa[maxn], siz[maxn], dfn[maxn], cnt;
	void clear() {
		memset(head, 0, sizeof(head)); tot = 0; cnt = 0;
	}
	void add(int u, int v) {
		nxt[++tot] = head[u]; to[tot] = v; head[u] = tot;
	}
	void dfs1(int u, int f) {
		fa[u] = f;
		siz[u] = 1;
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if (v == f) continue;
			dfs1(v, u);
			siz[u] += siz[v];
		}
	}
	void dfs2(int u, int f) {
		if (u != 1) {
			rt1[cnt+1] = s.add(rt1[cnt], 1, n, siz[u]);
			rt2[u] = s.add(rt2[f], 1, n, siz[u]);
		}
		dfn[u] = ++cnt;
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if (v == f) continue;
			dfs2(v, u);
		}
	}
	int solve(int u) {
		int ret = 0, mx = 0, w = 0, sx = 0, x = 0;
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i], S;
			if (v == fa[u]) {
				S = n-siz[u];
			} else {
				S = siz[v];
			}
			if (S > mx) {
				sx = mx; x = w; mx = S; w = v;
			} else if (S > sx) {
				sx = S; x = v;
			}
		}
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if (n-2*mx > 0 && v != w) {
				if (v != fa[u]) {
					ret += s.query(rt1[dfn[v]-1], rt1[dfn[v]+siz[v]-1], 1, n, 1, n-2*mx);
				} else {
					ret += s.query(0, rt1[n], 1, n, 1, n-2*mx);
					ret -= s.query(rt1[dfn[u]-1], rt1[dfn[u]+siz[u]-1], 1, n, 1, n-2*mx);
					ret -= s.query(0, rt2[fa[u]], 1, n, 1, n-2*mx);
					ret += s.query(0, rt2[u], 1, n, 2*mx, n-1);
				}
			}
			if (v == w && 2*mx-n <= n-2*sx) {
				if (v != fa[u]) {
					ret += s.query(rt1[dfn[v]-1], rt1[dfn[v]+siz[v]-1], 1, n, 2*mx-n, n-2*sx);
				} else {
					ret += s.query(0, rt1[n], 1, n, 2*mx-n, n-2*sx);
					ret -= s.query(rt1[dfn[u]-1], rt1[dfn[u]+siz[u]-1], 1, n, 2*mx-n, n-2*sx);
					ret -= s.query(0, rt2[fa[u]], 1, n, 2*mx-n, n-2*sx);
					ret += s.query(0, rt2[u], 1, n, 2*sx, 2*n-2*mx);
				}
			}
		}
		return ret;
	}
}g;


void solve() {
	scanf("%d", &n);
	g.clear();
	s.clear();
	for (int i = 1; i <= n-1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g.add(u,v), g.add(v,u);
	}
	g.dfs1(1,0);
	g.dfs2(1,0);
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += (long long)i*g.solve(i);
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("centroid.in", "r", stdin);
	freopen("centroid.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) solve();
}

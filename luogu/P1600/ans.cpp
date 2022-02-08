#include <bits/stdc++.h>
using namespace std;

const int mx = 3e5+10, LOG = 20, inf = 1e9;

int n, m, ans[mx], s[mx], t[mx], w[mx];
int head[mx], nxt[mx<<1], to[mx<<1], tot;
int dep[mx] = {-1}, fa[mx][LOG];
int down[mx<<2], up[mx<<1];
vector<pair<int, int> > v[mx];

void add(int u, int v) {
	++tot;
	nxt[tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}

void dfs0(int u) {
	for (int i = 1; i < LOG; ++i) {
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for (int e = head[u], v; e; e = nxt[e]) {
		if ((v=to[e]) == fa[u][0]) continue;
		fa[v][0] = u;
		dep[v] = dep[u]+1;
		dfs0(v);
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = LOG-1; ~i; --i)
		if (dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	if (u == v) return u;
	for (int i = LOG-1; ~i; --i)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

#define pb push_back
#define mp make_pair
#define fi first
#define se second

void addr(int s, int t, int w=0) {
	assert(dep[s] != dep[t]);
	if (dep[s] < dep[t]) w += inf, swap(s, t);
	v[s].pb(mp(w, 1));
	v[t].pb(mp(w, -1));
}

void dfs(int u) {
	ans[u] -= up[dep[u]+w[u]] + down[(mx<<1) + dep[u]-w[u]];
	for (int e = head[u]; e; e = nxt[e]) {
		if (to[e] == fa[u][0]) continue;
		dfs(to[e]);
	}
	for (int i = 0; i < (int)v[u].size(); ++i) {
		if (v[u][i].fi > inf/2) down[(mx<<1) + v[u][i].fi-inf] += v[u][i].se;
		else up[v[u][i].fi] += v[u][i].se;
	}
	ans[u] += up[dep[u]+w[u]] + down[(mx<<1) + dep[u]-w[u]];
}

int main() {
	scanf("%d%d", &n, &m);
	int u, v;
	for (int i = 0; i < n-1; ++i) {
		scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	dfs0(1);
	for (int i = 1; i <= n; ++i) scanf("%d", w+i);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", s+i, t+i);
		u = lca(s[i], t[i]);
		if (u == s[i]) addr(fa[s[i]][0], t[i], dep[s[i]]);
		else if (u == t[i]) addr(s[i], fa[t[i]][0], dep[s[i]]);
		else {
			addr(s[i], fa[u][0], dep[s[i]]);
			addr(u, t[i], dep[u] - (dep[s[i]]-dep[u]));
		}
	}
	dfs(1);
	for (int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i==n]);
}

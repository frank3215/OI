#include <bits/stdc++.h>
#define print //printf
using namespace std;

const int maxn = 3e5+10, maxlogn = 20;

int n;
int hd[maxn], nxt[maxn<<1], to[maxn<<1], tot;
int sz[maxn], f[maxn], g[maxn], son[maxn][maxlogn];
long long ans;

void add(int u, int v) {
	nxt[++tot] = hd[u];
	to[tot] = v;
	hd[u] = tot;
}

void reset(int u) {
	print("reset(%d)\n", u);
	son[u][0] = f[u];
	for (int i = 1; i < maxlogn; ++i) {
		son[u][i] = son[son[u][i-1]][i-1];
	}
	for (int i = 0; i < maxlogn; ++i) print("%d%c", son[u][i], " \n"[i+1==maxlogn]);
}

void dfs1(int u, int p) {
	sz[u] = 1;
	f[u] = g[u] = 0;
	for (int i = hd[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v == p) continue;
		dfs1(v, u);
		sz[u] += sz[v];
		if (sz[v] > sz[f[u]]) g[u] = f[u], f[u] = v;
		else if (sz[v] > sz[g[u]]) g[u] = v;
	}
	reset(u);
}

void check(int u) {
	int p = u;
	for (int i = maxlogn-1; ~i; --i) {
		if (son[u][i] && 2*sz[son[u][i]] > sz[p]) u = son[u][i];
	}
	ans += u;
	if (son[u][0] && sz[p] <= 2*sz[f[u]]) ans += f[u];
	print("check(%d) => (%d) => %lld\n", p, u, ans);
}

void dfs2(int u, int p) {
	print("dfs2(%d)\n", u);
	int siz = sz[u], of = f[u];
	for (int i = hd[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v == p) continue;
		print("%d->%d\n", u, v);
		check(v);
		sz[u] = n-sz[v];
		f[u] = of;
		if (v == f[u]) f[u] = g[u];
		if (sz[p] > sz[f[u]]) f[u] = p;
		reset(u);
		check(u);
		dfs2(v, u);
	}
	f[u] = of;
	reset(u);
	sz[u] = siz;
}

void solve() {
	memset(hd, 0, sizeof(hd)), tot = 0;
	scanf("%d", &n);
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	ans = 0;
	dfs1(1, 0);
	dfs2(1, 0);
	printf("%lld\n", ans);
}

int main() {
	freopen("centroid.in", "r", stdin);
	freopen("centroid.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) solve();
}

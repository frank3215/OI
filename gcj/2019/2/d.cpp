#include <bits/stdc++.h>

#define debug //printf

using namespace std;

const int maxn = 1e5+10, MOD = 1000000007;

int g[maxn], r1[maxn], r2[maxn], vis[maxn];
vector<int> e[maxn], v;
bool loop;

void init() {
	v.clear();
	for (int i = 0; i < maxn; ++i) e[i].clear();
//	memset(vis, 0, sizeof(vis));
	loop = 0;
}

void con(int x, int y) {
	debug("%d->%d\n", x, y);
	e[x].push_back(y);
}

void dfs(int u) {
	debug(" [%d(%d)]\n", u, vis[u]);
	if (vis[u] == 2) {
		loop |= (bool)g[u];
		return;
	}
	vis[u]++;
	for (int i = 0; i < e[u].size(); ++i) {
		int v = e[u][i];
		debug("%d=>%d\n", u, v);
		dfs(v);
	}
	vis[u]--;
	v.push_back(u);
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> r1[i] >> r2[i];
		con(r1[i], i);
		con(r2[i], i);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> g[i];
	}
	dfs(1);
	if (loop) {
		puts("UNBOUNDED");
		return;
	}
	else {
		for (int i = 0; i < (int)v.size()-1; ++i) {
			int u = v[i];
			g[r1[u]] = (g[r1[u]]+g[u])%MOD;
			g[r2[u]] = (g[r2[u]]+g[u])%MOD;
			debug("(%d):%d ::> (%d):%d, (%d):%d\n", u, g[u], r1[u], g[r1[u]], r2[u], g[r2[u]]);
			g[u] = 0;
		}
		printf("%d\n", g[1]);
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		init();
		solve();
	}
}

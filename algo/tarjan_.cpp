#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e4+10;

int m, n, val[maxn], ans;
vector<int> g[maxn];
int dfn[maxn], top[maxn], cnt, scc[maxn], ins[maxn], tot;
stack<int> s;
int vis[maxn], f[maxn];

void dfs(int u) {
	dfn[u] = top[u] = ++tot;
	s.push(u);
	ins[u] = 1;
	for (int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		if (!dfn[v]) {
			dfs(v);
			top[u] = min(top[u], top[v]);
		} else if (ins[v]) {
			top[u] = min(top[u], dfn[v]);
		}
	}
	if (top[u] == dfn[u]) {
		++cnt;
		do {
			ins[s.top()] = 0;
			scc[s.top()] = cnt;
			val[cnt] += val[s.top()];
			s.pop();
		} while (ins[u]);
	}
}

int dp(int u) {
	if (vis[u]) return f[u];
	vis[u] = 1;
	f[u] = val[u];
	for (int i = 0; i < (int)g[u].size(); ++i)
		f[u] = max(f[u], val[u]+dp(g[u][i]));
	return f[u];
}

void con(int u, int v) {
	g[u].push_back(v);
}

int main() {
	scanf("%d%d", &n, &m);
	cnt = n;
	for (int i = 1; i <= n; ++i)
		scanf("%d", val+i);
	int u, v;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &u, &v);
		con(u, v);
	}
	for (int i = 1; i <= n; ++i) {
		if (!dfn[i]) dfs(i);
//		printf("%d %d\n", i, scc[i]);
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < (int)g[i].size(); ++j) {
			if (scc[i] != scc[g[i][j]])
				g[scc[i]].push_back(scc[g[i][j]]);
		}
	for (int i = n+1; i <= cnt; ++i) {
//		printf("%d %d %d\n", i, dp(i), val[i]);
		ans = max(ans, dp(i));
	}
	printf("%d\n", ans);
}

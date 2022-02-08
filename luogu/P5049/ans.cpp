#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+10;

int n, m, p, r;
bool ret, vis[maxn], onloop[maxn];
vector<int> g[maxn];
stack<int> s;

bool dfs0(int u, int f, bool pr) {
	if (vis[u]) {
		if (!p) p = u;
		return true;
	}
	vis[u] = 1;
	if (pr) printf("%d ", u);
	for (int i = 0; i < (int)g[u].size(); ++i) {
		if (g[u][i] == f) continue;
		onloop[u] |= dfs0(g[u][i], u, pr);
	}
	return onloop[u] && u != p;
}

void dfs1(int u, int f) {
	if (vis[u]) return;
	if (onloop[u] && !ret && s.size() && s.top() < u) {
		ret = true;
		return;
	}
	vis[u] = 1;
	printf("%d ", u);
	for (int i = 0, j; i < (int)g[u].size(); ++i) {
		if (g[u][i] == f) continue;
		if (onloop[u]) {
			for (j = i+1; j < (int)g[u].size(); ++j)
				if (!vis[g[u][j]]) {
					s.push(g[u][j]);
					break;
				}
		}
		dfs1(g[u][i], u);
		if (onloop[u] && j < (int)g[u].size()) s.pop();
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int u, v;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) sort(g[i].begin(), g[i].end());
	dfs0(1, 0, m != n);
	if (m == n) {
		memset(vis, 0, sizeof(vis));
		dfs1(1, 0);
	}
}

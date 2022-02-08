#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+10, maxm = 2e5+10;

int n, m;
vector<int> g[maxn];
int a[maxm], b[maxm];
int v[maxn][maxn], w[maxn][maxn], vis2[maxn];
int rt;

inline void add(int a,int b){g[a].push_back(b);}

inline void dfs2(int u) {
	v[rt][u] = vis2[u] = 1;
	for (auto y: g[u]) {
		if (!vis2[y]) dfs2(y);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", a+i, b+i);
		add(a[i], b[i]);
	}
	for (rt = 1; rt <= n; ++rt) {
		memset(vis2, 0, sizeof(vis2));
		vis2[rt] = 1;
		for (auto x: g[rt]) {
			if (!vis2[x]) dfs2(x);
			else w[rt][x] = 1;
		}
		memset(vis2, 0, sizeof(vis2));
		vis2[rt] = 1;
		reverse(g[rt].begin(), g[rt].end());
		for (auto x: g[rt]) {
			if (!vis2[x]) dfs2(x);
			else w[rt][x] = 1;
		}
	}
	for (int i = 1; i <= m; ++i) {
		puts(v[b[i]][a[i]]^w[a[i]][b[i]]?"diff":"same");
	}
}

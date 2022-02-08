#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+10, maxm = 2e5+10;

int n, m;
int a[maxm], b[maxm];
int x[maxm], v[maxn][maxn], y[maxm], vis1[maxn], vis2[maxn];
int rt;
int *vis;
vector<int> to[maxn], num[maxn]; int tot;

void add(int a,int b){
	to[a].push_back(b);
	num[a].push_back(++tot);
}

void dfs2(int u) {
	v[rt][u] = 1;
	for (int v: to[u]) {
		if (!vis[v]) {
			vis[v] = vis[u];
			dfs2(v);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", a+i, b+i);
		add(a[i], b[i]);
	}
	for (rt = 1; rt <= n; ++rt) {
		memset(vis1, 0, sizeof(vis1));
		memset(vis2, 0, sizeof(vis2));
		vis1[rt] = vis2[rt] = rt;
		vis = vis1;
		for (int v: to[rt]) {
			if (!vis[v]) vis[v] = v, dfs2(v);
		}
		vis = vis2;
		reverse(to[rt].begin(), to[rt].end());
		reverse(num[rt].begin(), num[rt].end());
		for (int i = 0; i < (int)to[rt].size(); ++i) {
			int v = to[rt][i], e = num[rt][i];
			if (!vis[v]) vis[v] = v, dfs2(v);
			if (vis2[v] == vis1[v]) y[e] = false;
			else y[e] = true;
		}
	}
	for (int i = 1; i <= m; ++i) {
		puts(v[b[i]][a[i]]^y[i]?"diff":"same");
	}
}


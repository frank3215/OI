#include <bits/stdc++.h>
using namespace std;

void pushup(int u) {
	mx[u] = max(mx[ls[u]], mx[rs[u]]);
	c[u] = 0;
	if (mx[ls[u]] == mx[u]) c[u] += c[ls[u]];
	if (mx[rs[u]] == mx[u]) c[u] += c[rs[u]];
}

void merge(int &u, int v, int l, int r) {
	if (!u || !v) {
		u = u+v;
		return;
	}
	if (l == r) return;
	int m = l+r>>1;
	merge(ls[u], ls[v], l, m);
	merge(rs[u], rs[v], m+1, r);
	pushup(u);
}

void insert(int &u, int x, int l, int r) {
	if (!u) u = ++tot;
	if (l == r) {
		mx[u]++;
		return;
	}
	int m = (l+r)>>1;
	if (x <= m) insert(ls[u], x, l, m);
	else insert(rs[u], x, m+1, r);
	pushup(u);
}

pair<int,int> query(int u, int L, int R, int l, int r) {
	if (l <= L && R <= r) return make_pair(
}

void dfs(int u, int f) {
	insert(seg[u], c[u], 1, n);
	for (int i = 0; i < (int)g[u].size(); ++i) {
		int v = g[u][i];
		if (v == f) continue;
		dfs(v, u);
		merge(seg[u], seg[v]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", c+i);
	}
	int x, y;
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 0);
}

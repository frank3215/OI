// POJ3694
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10, maxm = 2e5+10;

int n, m, q;

struct graph{
	int head[maxn], nxt[maxm<<1], to[maxm<<1], tot;
	void add(int a, int b) {
		nxt[++tot] = head[a], to[tot] = b, head[a] = tot;
	}
	void clear() {
		tot = 1;
		memset(head, 0, sizeof(head));
	}
};

struct Solve : graph{
	int ans;
	int fa[maxn], f[maxn], dep[maxn];
	void clear() {
		graph::clear();
		memset(fa, 0, sizeof(fa));
		memset(f, 0, sizeof(f));
		memset(dep, 0, sizeof(dep));
		ans = 0;
	}
	void init(int u, int F) {
		fa[u] = F;
		dep[u] = dep[F] + 1;
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if (v == F) continue;
			init(v, u);
		}
	}
	int find(int u) {
		return f[u]?f[u]=find(f[u]):u;
	}
	int query(int u, int v) {
		while ((u=find(u)) != (v=find(v))) {	
			if (dep[u] < dep[v]) swap(u, v);
			f[u] = fa[u];
			--ans;
		}
		return ans;
	}
}h;

struct Tarjan: graph{
	int dfn[maxn], low[maxn], cnt;
	int bridge[maxm<<1], c[maxn];
	int dcc;
	void clear() {
		graph::clear();
		memset(c, 0, sizeof(c));
		memset(bridge, 0, sizeof(bridge));
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		dcc = cnt = 0;
	}
	void tarjan(int u, int fa) {
		dfn[u] = low[u] = ++cnt;
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if ((i^1) == fa) continue;
			if (dfn[v]) low[u] = min(dfn[v], low[u]);
			else {
				tarjan(v, i);
				low[u] = min(low[v], low[u]);
				if (low[v] > dfn[u]) bridge[i] = bridge[i^1] = true;
			}
		}
	}
	void dfs(int u) {
		c[u] = dcc;
		for (int i = head[u]; i; i = nxt[i]) {
			int v = to[i];
			if (bridge[i] || c[v]) continue;
			dfs(v);
		}
	}
	void shrink(Solve &h) {
		tarjan(1, 0);
		for (int i = 1; i <= n; ++i)
			if (!c[i]) ++dcc, dfs(i);
//		printf("[%d]\n", dcc);
//		for (int i = 1; i <= n; ++i) printf("%d%c", c[i], " \n"[i==n]);
		h.ans = 0;
		for (int i = 2; i <= tot; ++i) {
			int a = to[i^1], b = to[i];
			if (c[a] == c[b]) continue;
//			printf("%d %d\n", i, bridge[i]);
//			printf("%d(%d) %d(%d) %d\n", a, c[a], b, c[b], h.ans);
			h.add(c[a], c[b]);
			h.ans++;
		}
		h.ans /= 2;
//		printf("[%d]\n", h.ans);
		h.init(1, 0);
	}
}g;

int kase;

bool solve() {
	scanf("%d%d", &n, &m);
	if (m == 0) return false;
	g.clear();
	h.clear();
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		g.add(a,b), g.add(b,a);
	}
	g.shrink(h);
	scanf("%d", &q);
	printf("Case %d:\n", ++kase);
	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", h.query(g.c[a], g.c[b]));
	}
	puts("");
	return true;
}

int main() {
	while (solve());
}

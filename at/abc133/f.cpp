#include <bits/stdc++.h>
using namespace std;

struct ans{
	int len, cnt, clen;
};
struct tmp{
	int cnt, clen;
};
struct edge{
	int b, c, d;
};

struct graph{
	vector<edge> e[maxn];
	int fa[maxn][maxlogn], dep[maxn];
	void add(int a, int b, int c, int d) {
		e[a].push_back((edge){b, c, d});
	}
	void addq(int a, int b) {
		q[a].push_back(b);
	}
	void add2(int a, int b, int c, int d) {
		add(a, b, c, d), add(b, a, c, d);
	}
	void init(int u) {
		if (!fa[u][0]) {
			dep[0][0] = -1;
			init(t.rt[u], 1, n-1);
		}
		for (int i = 1; i < maxlogn; ++i) {
			fa[u][i] = fa[fa[u][i-1]][i-1];
			len[u][i] = len[u][i-1]+len[fa[u][i-1]][i-1];
		}
		for (int i = 0; i < e[u].size(); ++i) {
			int v = e[u][i].b;
			if (v == fa[u][0]) continue;
			t.rt[v] = t.rt[u];
			fa[v][0] = u;
			len[v][0] = e[u][i].d;
			dep[v] = dep[u]+1;
			dfs(v, u);
		}
	}
	int lca(int u, int v) {
		if (dep[u] < dep[v]) swap(u, v);
		for (int i = maxlogn-1; ~i; --i)
			if (dep[fa[u][i]] >= v) {
				u = fa[u][i];
			}
		for (int i = maxlogn-1; u != v; i = mau(0, i-1)) {
			if (i == 0 || fa[u][i] != fa[v][i]) {
				u = fa[u][i];
				v = fa[v][i];
			}
		}
		return u;
	}
	vector<pair<int, int> > q[maxq];
	ans a[maxq];
	tmp t[maxn];
	int len;

	void get(int u) {
		for (int i = 0; i < e[u].size(); ++i) {
			edge &d = e[u][i];
			if (d.b == fa[u][0]) continue;
			t[d.c].cnt++;
			t[d.c].clen+=d.d;
			get(d.b);
		}
		for (int i = 0; i < q[u].size(); ++i) {
			ans
		}
	}
}g;

int main() {
	scanf("%d%d", &N, &q);
	for (int i = 0; i < N-1; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
	}
}

#include <bits/stdc++.h>
#define debug //printf
using namespace std;

const int maxn = 1e5+10, maxlogn = 20;

int n;

namespace pers_seg{
	const int maxx = maxn*maxlogn;
	struct val{
		int cnt, len;
		void add(int l) {
			cnt++;
			len += l;
		}
	};
	struct node{
		val v;
		node *ls, *rs;
	}t[maxx];
	int tot;
	node *rt[maxn];
	void copy(node *&x) {
		t[++tot] = *x;
		x = t+tot;
	}
	void init(node *&u, int l, int r) {
		debug("pers_seg::init [%d, %d]\n", l, r);
		u = t+(++tot);
		if (l == r) return;
		int m = (l+r)>>1;
		init(u->ls, l, m);
		init(u->rs, m+1, r);
	}
	void modify(node *&u, int l, int r, int x, const val &y) {
		assert(u);
		debug("pers_seg::modify [%d, %d]:%d\n", l, r, x);
		copy(u);
		if (l == r) {
			u->v = y;
			return;
		}
		int m = (l+r)>>1;
		if (x <= m) modify(u->ls, l, m, x, y);
		else modify(u->rs, m+1, r, x, y);
	}
	const val& get(node *u, int l, int r, int x) {
		debug("pers_seg::get [%d, %d]:%d", l, r, x);
		assert(u);
		debug("(%d)\n", u-t);
		if (l == r) return u->v;
		int m = (l+r)>>1;
		if (x <= m) return get(u->ls, l, m, x);
		else return get(u->rs, m+1, r, x);
	}
}

using namespace pers_seg;

namespace graph{
	struct edge{
		int b, c, d;
	};
	vector<edge> e[maxn];
	int fa[maxn][maxlogn], len[maxn], dep[maxn];
	void add(int a, int b, int c, int d) {
		e[a].push_back((edge){b, c, d});
	}
	void add2(int a, int b, int c, int d) {
		add(a, b, c, d), add(b, a, c, d);
	}
	void init(int u) {
		debug("graph::init %d %d\n", u, fa[u][0]);
		if (!fa[u][0]) {
			dep[0] = -1;
			init(rt[u], 1, n-1);
		}
		for (int i = 1; i < maxlogn; ++i) fa[u][i] = fa[fa[u][i-1]][i-1];
		for (int i = 0; i < e[u].size(); ++i) {
			edge E = e[u][i];
			int v = E.b, c = E.c, d = E.d;
			if (v == fa[u][0]) continue;

			rt[v] = rt[u];
			val tmp = get(rt[v], 1, n-1, c);
			tmp.add(d);
			modify(rt[v], 1, n-1, c, tmp);
			fa[v][0] = u;
			len[v] = len[u]+e[u][i].d;
			dep[v] = dep[u]+1;

			init(v);
		}
	}
	int lca(int u, int v) {
		debug("graph::lca %d{%d} %d{%d}", u, dep[u], v, dep[v]);
		if (dep[u] < dep[v]) swap(u, v);
		for (int i = maxlogn-1; ~i; --i)
			if (dep[fa[u][i]] >= dep[v]) {
				u = fa[u][i];
			}
		debug(" [%d %d]", u, v);
		for (int i = maxlogn-1; u != v; i = max(0, i-1)) {
			if (i == 0 || fa[u][i] != fa[v][i]) {
				u = fa[u][i];
				v = fa[v][i];
			}
		}
		debug(" (%d)\n", u);
		return u;
	}
	int query(int x, int y, int u, int v) {
		debug("graph::query %d %d %d %d\n", x, y, u, v);
		int l = lca(u, v);
		val vu = get(rt[u], 1, n-1, x), vv = get(rt[v], 1, n-1, x), vl = get(rt[l], 1, n-1, x);
		int ans = len[u]+len[v]-2*len[l];
		ans -= (vu.len+vv.len-2*vl.len);
		ans += (vu.cnt+vv.cnt-2*vl.cnt)*y;
		return ans;
	}
}
using namespace graph;

int main() {
	int q;
	scanf("%d%d", &n, &q);
	int a, b, c, d;
	for (int i = 0; i < n-1; i++) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		add2(a, b, c, d);
	}
	init(1);
	while (q--) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", query(a, b, c, d));
	}
}

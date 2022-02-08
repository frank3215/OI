#include <bits/stdc++.h>
#define _d //puts
#define _dbg //printf
using namespace std;

const int maxn = 1e4+10, maxm = 5e4+10, maxlogn = 15;

int n, m;
pair<int, int> tmp[maxm];
int dep[maxn], fa[maxn][maxlogn], mn[maxn][maxlogn];

struct edge{
	int v, w;
	edge *n;
	bool operator <(const edge &e) const {
		return w < e.w;
	}
};

struct ufs{
	int f[maxn];
	int operator [](const int x) const { return f[x]; }
	int find(int x) {
		return f[x]>0?f[x]=find(f[x]):x;
	}
	bool merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) return false;
		if (f[fx] > f[fy]) swap(fx, fy);
		if (f[fx] == f[fy]) f[fx]--;
		f[fy] = fx;
		return true;
	}
}f;

struct graph{
	edge *h[maxn], e[maxm<<1];
	int tot;
	void _add(int u, int v, int w) {
		assert(u && v);
		e[tot] = (edge){v,w,h[u]};
		h[u] = e+tot;
		tot++;
	}
	void add(int u, int v, int w) { _add(u,v,w), _add(v,u,w); }
	void generate(pair<int, int> t[], graph &g, ufs &f) {
		for (int i = 0; i < m; ++i) t[i] = make_pair(e[i<<1].w, i<<1);
		sort(t, t+m, greater<pair<int, int> >());
		for (int i = 0; i < m; ++i) {
			int U = e[t[i].second+1].v, V = e[t[i].second].v;
//			_dbg(" %d %d\n", U, V);
			if (f.merge(U, V)) {
				g.add(U, V, t[i].first);
			}
		}
	}
	void init_tree(int u, int dep[], int fa[][maxlogn], int mn[][maxlogn]) {
		if (!dep[u]) dep[u] = 1;
		_dbg("\t%d %d\n", u, dep[u]);
		for (int k = 1; k < maxlogn; ++k) {
			int t = fa[u][k-1];
			fa[u][k] = fa[t][k-1];
			mn[u][k] = min(mn[u][k-1], mn[t][k-1]);
		}
		for (edge *E = h[u]; E; E = E->n) {
			if (E->v != fa[u][0]) {
				dep[E->v] = dep[u]+1;
				fa[E->v][0] = u;
				mn[E->v][0] = E->w;
				init_tree(E->v, dep, fa, mn);
			}
		}
	}
#define _jump(u, i) ans=min(ans,mn[u][i]); u=fa[u][i];
	int get_ans(int u, int v, int dep[]) {
		if (dep[u] < dep[v]) swap(u, v);
		int ans = 1e9;
	_d("1");
			_dbg(" %d(%d) %d(%d)\n", u, dep[u], v, dep[v]);
		for (int i = maxlogn-1; ~i; --i)
			if (dep[fa[u][i]] >= dep[v]) {
				_jump(u,i);
			}
	_d("2");
			_dbg(" %d(%d) %d(%d)\n", u, dep[u], v, dep[v]);
		if (u == v) return ans;
		for (int i = maxlogn-1; ~i; --i) {
			_dbg(" %d(%d) %d(%d)\n", u, dep[u], v, dep[v]);
			if (fa[u][i] != fa[v][i]) {
				_jump(v, i);
				_jump(u, i);
			}
		}
		_jump(u, 0);
		_jump(v, 0);
	_d("3");
		return u?ans:-1;
	}
}g, h;

int main() {
	scanf("%d%d", &n, &m);
	int x, y, z;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		g.add(x,y,z);
	}
	g.generate(tmp, h, f);
	for (int i = 1; i <= n; ++i)
		_dbg("%d %d\n", i, dep[i]);
	for (int i = 1; i <= n; ++i) {
		if (!dep[i])
			h.init_tree(i, dep, fa, mn);
	}
	scanf("%d", &z);
	while (z--) {
		scanf("%d%d", &x, &y);
		printf("%d\n", h.get_ans(x, y, dep));
	}
}

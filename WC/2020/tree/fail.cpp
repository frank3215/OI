#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

const int N = 5e5+10;

int n;
int head[N], nxt[N<<1], to[N<<1], tot;
int st[N];

void add(int u, int v) { nxt[++tot] = head[u], to[tot] = v, head[u] = tot; }
#define trav(u,e,v) for (int e = head[u], v; e && (v = to[e], 1); e = nxt[e])

int t[N];

void modify(int *t, int x, int d) {
	for (; x < N; x += x&-x) t[x] += d;
}
int query(int *t, int x) {
	int ret = 0;
	for (; x; x -= x&-x) ret += t[x];
	return ret;
}

int dfn[N], top[N], son[N], siz[N], fa[N], tim;
set<pair<int,int> > ia[N], oa[N], ib[N], ob[N];
typedef set<pair<int,int> > LOL[N];

int a, b;

void dfs1(int u, int f) {
	fa[u] = f;
	siz[u] = 1;
	trav(u,e,v) {
		if (v == f) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs2(int u, int tp) {
	dfn[u] = ++tim;
	top[u] = tp;
	if (son[u]) dfs2(son[u], tp);
	trav(u,e,v) {
		if (v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}

int Top(int v, LOL out) {
	int ret = v;
	while (v) {
		if (!out[top[v]].empty()) {
			ret = out[top[v]].begin()->se;
		}
		v = fa[top[v]];
	}
	return ret;
}

int Bottom(int v, LOL in) {
	while (v) {
		if (!in[top[v]].empty()) {
			return prev(in[top[v]].end())->se;
		}
		v = fa[top[v]];
	}
	return 0;
}

void expand(int v) {
	a++;
	modify(ti, u, 1);
	oa[top[v]].erase(mp(dfn[v], v));
	ia[top[v]].insert(mp(dfn[v], v));
	in.insert(mp(siz[v], v));
	out.erase(mp(siz[v], v));
}

void ierase(int u) {
	--a;
	modify(ti, u, -1);
	ia[top[u]].erase(mp(dfn[u], u));
	oa[top[u]].insert(mp(dfn[u], u));
	in.erase(mp(siz[v], v));
	out.insert(mp(siz[v], v));
}

signed main() {
#ifndef STDIO
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
	scanf("%d", &n);
	FOR(i,0,n-1) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	// Init
	dfs1(1,0);
	dfs2(1,1);
	a = 0;
	b = 1;
	// Init done
	int q;
	scanf("%d", &q);
	while (q--) {
		int t, v;
		scanf("%d%d", &t, &v);
		st[v] ^= 1;
		if (t == 1) {
			modify(t, v, 1);
			if (v == 1 || query(ti,dfn[v]+siz[v]-1)-query(ti,dfn[v]-1) > 0) {
				modify(ti, v, 1);
				ia[top[v]].insert(mp(dfn[v], v)); ++a;
				if (in.begin()->fi < a) {
					int u = in.begin()->se; in.erase(in.begin());
					ierase(u);
				}
			}
			else {
				oa[top[v]].insert(mp(dfn[v], v));
				int u = Top(v, oa);
				if (query(t,dfn[u]+siz[u]-1)-query(t,dfn[u]-1) > a) {
					expand(u, ia, oa);
				}
			}
		} else {
			modify(t, v, -1);
			if (v == 1 || query(ti, dfn[v]+siz[v]-1)-query(ti, dfn[v]-1) > 0) {
				modify(ti, v, -1);
				ia[top[v]].erase(mp(dfn[v], v)); --a;
				if (prev(out.end())->fi > a) {
					int u = prev(out.end())->se; out.erase(prev(out.end()));
					expand(u);
				}
			}
			if (u && query(t,dfn[u]+siz[u]-1)-query(dfn[u]-1) > b) {
				expand(v, ia, oa);
			}
		}
		printf("%d\n", a);
	}
}

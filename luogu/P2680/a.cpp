#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+10, maxlogn = 21;
int n, m, u[maxn], v[maxn];
int head[maxn], nxt[maxn<<1], to[maxn<<1], cost[maxn<<1], tot;
int len[maxn];
int fa[maxn][maxlogn], up[maxn][maxlogn], dep[maxn], dis[maxn];
int din[maxn], dout[maxn], cnt;
pair<int, int> p[maxn];

void add(int x, int y, int z) {
	++tot;
	nxt[tot] = head[x];
	to[tot] = y;
	cost[tot] = z;
	head[x] = tot;
}

void init(int u) {
	din[u] = ++cnt;
	if (!fa[u][0]) dep[u] = 1;
	for (int i = 1; i < maxlogn; ++i) {
		int g = fa[u][i-1];
		fa[u][i] = fa[g][i-1];
		up[u][i] = max(up[u][i-1], up[g][i-1]);
	}
	for (int e = head[u]; e; e = nxt[e]) {
		int v = to[e];
		if (v == fa[u][0]) continue;
		dep[v] = dep[u]+1;
		dis[v] = dis[u]+cost[e];
		up[v][0] = cost[e];
		fa[v][0] = u;
		init(v);
	}
	dout[u] = ++cnt;
}

int level;

pair<int, int> lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	int mx = 0;
	for (int i = maxlogn-1; ~i; --i) {
		if (dep[fa[u][i]] >= dep[v]) {
			mx = max(mx, up[u][i]);
			u = fa[u][i];
		}
	}
	for (int i = maxlogn-1; u != v; i?--i:i) {
		if (!i || fa[u][i] != fa[v][i]) {
			mx = max(mx, max(up[u][i], up[v][i]));
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return make_pair(u, mx);
}

struct route{
	int u, v;
	route(int U=0, int V=0) { u=U, v=V; }
	bool empty() { return u == v; }
	void clean() { if (dep[u] < dep[v]) swap(u, v); }
}NO, r[maxn];

route merge(route R, route r) {
	if (R.empty() && r.empty()) return NO;
	else if (R.empty()) return r;
	else if (r.empty()) return R;
	else {
		R.clean(), r.clean();
		if (R.v == r.v) return (route){R.u, r.u};
		else assert(0);
	}
}
route inter(route, route);

route inter(route R, route r) {
	if (R.empty() || r.empty()) return NO;
	R.clean(), r.clean();
	int L = lca(R.u, R.v).first, l = lca(r.u, r.v).first;
	if (L == R.v && l == r.v) {
		if (dep[L] < dep[l]) {
			swap(L, l);
			swap(R, r);
		}
		if (din[r.v] <= din[R.v] && din[R.v] <= din[r.u] && dout[r.v] >= dout[R.v] && dout[R.v] >= dout[r.u]) return route(lca(R.u, r.u).first, L);
		else return NO;
	}
	if (L == R.v) {
		swap(R, r);
		swap(L, l);
	}
	return merge(inter(route(R.u, L), r), inter(route(R.v, L), r));
}

int main() {
	scanf("%d%d", &n, &m);
	int x, y, z;
	for (int i = 1; i <= n-1; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	init(1);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &r[i].u, &r[i].v);
		len[i] = dis[r[i].u]+dis[r[i].v]-2*dis[lca(r[i].u, r[i].v).first];
		p[i] = make_pair(len[i], i);
	}
	sort(p+1, p+m+1);
	int ans = p[m].first;
	route cur = r[p[m].second];
	for (int i = m-1; i; --i) {
		cur = inter(cur, r[p[i].second]);
		if (cur.empty()) break;
		ans = min(ans, max(p[i-1], p[m].first-lca(cur.u, cur.v).second));
	}
	cout << ans << endl;
}

#include <bits/stdc++.h>
#define debug //fflush(stdout), printf
#define X first
#define Y second
using namespace std;

const int maxN = 70000+10, logN = 17, maxm = maxN*logN*logN;
const int maxx = maxN*logN*logN;

typedef long long ll;

int n, m, w, h;

namespace graph{
	typedef pair<int, int> qnode;
	const int maxn = maxx;

	int head[maxn], nxt[maxm], to[maxm], c[maxm], tot;
	int dis[maxn];

	void adde(int u, int v, int w=0) {
//		debug("  CONNECT %d %d %d\n", u, v, w);
		++tot;
		nxt[tot] = head[u];
		to[tot] = v;
		c[tot] = w;
		head[u] = tot;
//		debug("END CONNECT %d %d %d\n", u, v, w);
	}

	void dijkstra(int s) {
		debug("DIJKSTRA %d\n", s);
		priority_queue<qnode, vector<qnode>, greater<qnode> > pq;
		memset(dis, 0x3f, sizeof(dis));
		pq.push(make_pair(dis[s] = 0, s));
		while (!pq.empty()) {
			qnode u = pq.top(); pq.pop();
			debug(" %d, %d\n", u.X, u.Y);
			if (u.X > dis[u.Y]) continue;
			for (int e = head[u.Y]; e; e = nxt[e]) {
				int v = to[e];
				debug("  %d->%d:%d\n", e, u.Y, v, c[e]);
				debug("   %d %d\n", u.X+c[e], dis[v]);
				if (u.X+c[e] < dis[v]) {
					dis[v] = u.X+c[e];
					pq.push(make_pair(dis[v], v));
				}
			}
		}
	}
}

namespace segtree{
#undef debug
#define debug //printf
	using namespace graph;
	int rt, tot, seg[maxx], ch[maxx][2];
	int x, y, i;
	int L, R, D, U;
	void add1(int &u, int l, int r, int fa=0) {
		if (!u) {
			u = ++tot;
			if (fa) adde(fa, u);
		}
		debug(" ADD1 %d: [%d, %d]\n", u, l, r);
		if (l == r) {
			adde(u, i, 0);
			return;
		}
		int m = (l+r)>>1;
		if (x <= m) add1(ch[u][0], l, m, u);
		else add1(ch[u][1], m+1, r, u);
	}
	void add2(int &u, int l, int r, int fa=0) {
		if (!u) {
			u = ++tot;
			if (fa) adde(fa, u);
		}
		debug("ADD2 %d: [%d, %d]\n", u, l, r);
		add1(seg[u], 1, w);
		if (l == r) return;
		int m = (l+r)>>1;
		if (y <= m) add2(ch[u][0], l, m, u);
		else add2(ch[u][1], m+1, r, u);
	}
	void addp(int X, int Y, int I) {
		x = X, y = Y, i = I;
		add2(rt, 1, h);
	}
	void con1(int u, int l, int r) {
		if (!u) return;
		debug(" CON1 %d: [%d, %d]\n", u, l, r);
		if (L <= l && r <= R) {
			adde(x, u, y);
			return;
		}
		int m = (l+r)>>1;
		if (L <= m) con1(ch[u][0], l, m);
		if (R > m) con1(ch[u][1], m+1, r);
	}
	void con2(int x, int d, int u) {
		if (!x) return;
		debug("CON2 %d: [%d, %d]\n", x, d, u);
		if (D <= d && u <= U) {
			con1(seg[x], 1, w);
			return;
		}
		int m = (u+d)>>1;
		if (D <= m) con2(ch[x][0], d, m);
		if (U > m) con2(ch[x][1], m+1, u);
	}
	void conp(int p, int t, int l, int r, int d, int u) {
		x = p, y = t;
		L=l, R=r, D=d, U=u;
		con2(rt, 1, h);
	}
}

namespace cgf {
	using namespace graph;
	using namespace segtree;
//	int x[maxn], y[maxn], pos[maxn][maxn], p[maxn], t[maxn], L[maxn], R[maxn], D[maxn], U[maxn];
	void solve() {
		freopen("jump.in", "r", stdin);
		freopen("jump.out", "w", stdout);
		scanf("%d%d%d%d", &n, &m, &w, &h);
		segtree::tot = n;
		int x, y, p, t, L, R, D, U;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &x, &y);
			addp(x, y, i);
		}
		debug("TOT: %d\n", segtree::tot);
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d%d%d%d%d", &p, &t, &L, &R, &D, &U);
			conp(p, t, L, R, D, U);
/*			for (int I = L[i]; I <= R[i]; ++I)
				for (int J = D[i]; J <= U[i]; ++J) if (pos[I][J]) {
					connect(p[i], pos[I][J], t[i]);
				}*/
		}
		dijkstra(1);
		for (int i = 2; i <= n; ++i)
			printf("%d\n", dis[i]);
	}
}

int main() {
	cgf::solve();
}

#include <bits/stdc++.h>
#define int long long
#define debug printf
#define dbg(x) cout << #x << " = " << x << endl
using namespace std;

const int INF = 1ll<<60, maxn = 1e5+10, maxlogn = 18;
inline void cmin(int &x, int y) { x = min(x, y); }

int n, m, p[maxn];
int head[maxn], nxt[maxn<<2], to[maxn<<2], tot;
int dep[maxn], fa[maxn][maxlogn], f[maxn][2], g[maxn][2], fh[maxn][maxlogn][2][2];
char type[3];

void print(int ff[2][2]) {
	debug("[[%lld][%lld]][[%lld][%lld]]\n", ff[0][0], ff[0][1], ff[1][0], ff[1][1]);
}

void print() {
	for (int i = 1; i <= n; ++i) {
		debug("%d %d\n", f[i][0], f[i][1]);
		for (int k = 0; k < 3; ++k)
			for (int _1 = 0; _1 < 2; ++_1)
				for (int _2 = 0; _2 < 2; ++_2)
					debug("fh[%d][%d][%d][%d] = %lld\n", i, k, _1, _2, fh[i][k][_1][_2]);
		debug("\n");
	}
}

void add(int u, int v) {
	++tot;
	nxt[tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}

void dfs(int u) {
	dep[u] = dep[fa[u][0]]+1;
	f[u][1] = p[u];
	for (int e = head[u]; e; e = nxt[e]) {
		int v = to[e];
		if (v == fa[u][0]) continue;
		fa[v][0] = u;
		dfs(v);
		f[u][1] += min(f[v][0], f[v][1]);
		f[u][0] += f[v][1];
	}
}

int lca(int u, int v) {
	assert(dep[u] >= dep[v]);
	for (int k = maxlogn-1; ~k; --k) {
		if (dep[fa[u][k]] >= dep[v]) {
			u = fa[u][k];
		}
	}
	if (u == v) return v;
	for (int k = maxlogn-1; ~k; --k) {
		if (fa[u][k] != fa[v][k]) {
			u = fa[u][k];
			v = fa[v][k];
		}
	}
	return fa[v][0];
}

int get(int u, int v, int ff[2][2]) {
	assert(u != v);
	ff[0][0] = ff[1][1] = 0;
	ff[0][1] = ff[1][0] = INF;
	for (int k = maxlogn-1; ~k; --k) {
		if (dep[fa[u][k]] > dep[v]) {
			int nf[2][2] = {{INF, INF}, {INF, INF}};
			for (int _1 = 0; _1 < 2; ++_1)
				for (int _2 = 0; _2 < 2; ++_2) {
					for (int _3 = 0; _3 < 2; ++_3) {
						cmin(nf[_1][_2], ff[_1][_3]+fh[u][k][_3][_2]);
					}
				}
			memcpy(ff, nf, sizeof(nf));
			u = fa[u][k];
		}
	}
	assert(fa[u][0] == v);
	return u;
}

int solve(int a, int x, int b, int y) {
	if (dep[a] < dep[b]) {
		swap(a, b);
		swap(x, y);
	}
	int c = lca(a, b);
//	debug("%d %d: %d\n", a, b, c);
	int af[2][2], bf[2][2], cf[2][2];
	if (b == c) {
		get(a, fa[b][0], af);
		get(b, 0, bf);
//		print(af);
//		print(bf);
		return f[a][x]+af[x][y]+min(bf[y][1], bf[y][0]);
	}
	int na = get(a, c, af), nb = get(b, c, bf);
	get(c, 0, cf);
//	print(af);
//	print(bf);
//	print(cf);
//	dbg(f[c][0]), dbg(f[a][1]), dbg(f[b][1]), dbg(cf[0][0]), dbg(cf[0][1]);
	return min(
			f[c][0]-f[na][1]-f[nb][1]+min(cf[0][0],cf[0][1]) + f[a][x]+af[x][1] + f[b][y]+bf[y][1],
			f[c][1]-min(f[na][0], f[na][1])-min(f[nb][0], f[nb][1])+min(cf[1][0],cf[1][1]) + f[a][x]+min(af[x][1],af[x][0]) + f[b][y]+min(bf[y][1],bf[y][0])
			);
}

signed main() {
	scanf("%lld%lld%s", &n, &m, type);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", p+i);
	int u, v;
	for (int i = 0; i < n-1; ++i) {
		scanf("%lld%lld", &u, &v);
		add(u, v), add(v, u);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		fh[i][0][0][0] = INF;
		fh[i][0][1][0] = f[fa[i][0]][0] - f[i][1];
		fh[i][0][0][1] = f[fa[i][0]][1] - min(f[i][0], f[i][1]);
		fh[i][0][1][1] = f[fa[i][0]][1] - min(f[i][0], f[i][1]);
	}
	for (int k = 1; k < maxlogn; ++k) {
		for (int i = 1; i <= n; ++i) {
			int tmp = fa[i][k-1];
			fa[i][k] = fa[tmp][k-1];
			for (int _1 = 0; _1 < 2; ++_1)
				for (int _2 = 0; _2 < 2; ++_2) {
					fh[i][k][_1][_2] = INF;
					for (int _3 = 0; _3 < 2; ++_3)
						cmin(fh[i][k][_1][_2], fh[i][k-1][_1][_3]+fh[tmp][k-1][_3][_2]);
				}

		}
	}
//	print();
	int a, x, b, y;
	while (m--) {
		scanf("%lld%lld%lld%lld", &a, &x, &b, &y);
		int ans = solve(a, x, b, y);
		printf("%lld\n", ans < INF ? ans : -1);
	}
}

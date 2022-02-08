#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, P = 1e9+7;

int n, m;

int qpow(int a, int x) {
	int ret = 1;
	for (; x; a = 1ll*a*a%P, x >>= 1)
		if (x&1) ret = 1ll*ret*a%P;
	return ret;
}

#define clean(x) memset(x, 0, sizeof(x));
struct graph{
	int id;
	int head[N], nxt[N<<1], to[N<<1], tot;
	int deg[N];
	void clear() {
		tot = 1;
		memset(head, 0, sizeof(head));
		memset(deg, 0, sizeof(deg));
	}
	graph() { clear(); }
	void add(int u, int v) {
		++tot;
		++deg[u];
		nxt[tot] = head[u];
		to[tot] = v;
		head[u] = tot;
	}
	void add2(int u, int v) {
//		printf("ADD%d: %d<->%d\n", id, u, v);
		add(u, v), add(v, u);
	}
};

struct forest: graph{
	int val[N], dp[N], fa[N], root[N];
	int vis[N], zero, ans;
	void clear() {
		graph::clear();
		clean(vis);
		clean(val);
		clean(dp);
		clean(fa);
		zero = ans = 0;
	}
	forest(): graph() { id = 0, clear(); }
	int dfs1(int u, int f) {
		fa[u] = f;
		root[u] = f?root[f]:u;
		vis[u] = 1;
		dp[u] = val[u];
		for (int e = head[u]; e; e = nxt[e]) {
			int v = to[e];
			if (v == f) continue;
			dp[u] += dfs1(v, u);
		}
		return dp[u];
	}
	void init() {
		for (int i = 1; i <= n; ++i)
			if (!vis[i]) {
				zero += dfs1(i, 0)%2;
			}
	}
	int calc(int M, int u=0) {
		if (!u) return zero?0:qpow(2,M);
		int tmp = zero;
		tmp -= dp[root[u]]%2;
		--M;
//		printf("(%d,%d)", M, tmp);
		for (int e = head[u]; e; e = nxt[e]) {
			int v = to[e];
			if (v == fa[u]) {
				tmp += (dp[root[u]]-dp[u])%2;
			} else {
				tmp += dp[v]%2;
			}
			++M;
		}
//		printf("->(%d,%d)", M, tmp);
		return tmp?0:qpow(2,M);
	}
}h;
struct Tarjan : graph{
	int dfn[N], low[N], cnt;
	int dcc;
	stack<int> s;
	void clear() {
		graph::clear();
		clean(dfn);
		clean(low);
		dcc = cnt = 0;
		while (!s.empty()) s.pop();
	}
	Tarjan(): graph() { id = 1, clear(); }
	void tarjan(int u, int f, forest &g) {
		dfn[u] = low[u] = ++cnt;
		s.push(u);
		for (int e = head[u]; e; e = nxt[e]) {
			if (e == (f^1)) continue;
			int v = to[e];
			if (dfn[v]) {
				low[u] = min(low[u], dfn[v]);
			} else {
				tarjan(v, e, g);
				low[u] = min(low[u], low[v]);
				if (low[v] >= dfn[u]) {
					++dcc;
					int z;
					do {
						z = s.top(); s.pop();
						g.add2(z, n+dcc);
					} while (z != v);
					g.add2(u, n+dcc);
				}
			}
		}
	}
	int tarjan(forest &g) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (!dfn[i]) {
				tarjan(i, 0, g);
				++cnt;
			}
		}
		return cnt;
	}
}g;

char s[N];

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g.add2(u, v);
	}
	scanf("%s", s+1);
	for (int i = 1; i <= n; ++i) h.val[i] = s[i]-'0';
	int cnt = g.tarjan(h);
	h.init();
//	printf("[%d]\n", cnt);
	for (int i = 0; i <= n; ++i) {
		printf("%d%c", h.calc((m-g.deg[i])-(n-(i!=0))+cnt, i), " \n"[i==n]);
	}
	g.clear();
	h.clear();
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) solve();
}

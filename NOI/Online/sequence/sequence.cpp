#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

int n, m;
int a[maxn], b[maxn];
int t[maxn], u[maxn], v[maxn];

struct graph{
	int head[maxn], to[maxn<<1], nxt[maxn<<1], vis[maxn], tot;
	long long val[maxn];
	void clear() {
		memset(head, 0, sizeof(head));
		memset(vis, 0, sizeof(vis));
		memset(val, 0, sizeof(val));
		tot = 0;
	}
	void add(int u, int v) {
		++tot;
		nxt[tot] = head[u];
		to[tot] = v;
		head[u] = tot;
	}
	void add2(int u, int v) {
//		printf("ADD2: %d %d\n", u, v);
		add(u, v);
		add(v, u);
	}
	long long dfs1(int u) {
		long long ret = val[u];
		for (int e = head[u]; e; e = nxt[e]) {
			int v = to[e];
			if (!vis[v]) {
				vis[v] = vis[u];
				ret += dfs1(v);
			}
		}
		return ret;
	}
	int dfs2(int u) {
		int ret = 2;
		vis[u] = 1;
		for (int e = head[u]; e; e = nxt[e]) {
			int v = to[e];
			ret--;
			if (!vis[v]) {
				ret += dfs2(v);
				val[u] -= val[v], val[v] = 0;
			}
		}
		return ret;
	}
}g, h;

void solve() {
	g.clear();
	h.clear();
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", b+i);
		g.val[i] = a[i]-b[i];
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", t+i, u+i, v+i);
		if (t[i] == 2) g.add2(u[i], v[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (!g.vis[i]) {
			++cnt;
			g.vis[i] = cnt;
			h.val[cnt] = g.dfs1(i);
//			printf(" %d %d %lld\n", i, cnt, h.val[cnt]);
		}
//		printf("%d: %d\n", i, g.vis[i]);
	}
	for (int i = 1; i <= m; ++i) {
		if (t[i] == 1) h.add2(g.vis[u[i]], g.vis[v[i]]);
	}
	bool ans = true;
	for (int i = 1; i <= cnt; ++i) {
		if (!h.vis[i]) {
			int ret = h.dfs2(i);
//			printf("%d %d %lld\n", i, ret, h.val[i]);
			if (ret <= 0) ans &= (h.val[i]%2 == 0);
			else ans &= (h.val[i] == 0);
		}
	}
	puts(ans?"YES":"NO");
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}

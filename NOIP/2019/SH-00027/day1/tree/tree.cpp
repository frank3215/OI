#include <bits/stdc++.h>
#define print //printf
using namespace std;

const int maxn = 2000+10;

int n, p[maxn];
int head[maxn], nx[maxn<<1], to[maxn<<1], deg[maxn], tot;
void add(int u, int v) {
	++deg[u];
	++tot;
	nx[tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}

int beg[maxn], end[maxn], nxt[maxn<<1], pre[maxn<<1];

int dfs(int u, int f=0) {
	int ret = n+1;
	if (f == 0) {
		if (beg[u]) return dfs(to[beg[u]], beg[u]^1);
		int hd = end[u], cnt = 0;
		for (; hd > 0; hd = pre[hd]) cnt++;
		for (int e = head[u]; e; e = nx[e]) {
			if (pre[e] || (hd == e && cnt != deg[u])) continue;
			ret = min(dfs(to[e], e^1), ret);
		}
		return ret;
	}
	if (nxt[f]) return dfs(to[nxt[f]], nxt[f]^1);
	if (f == end[u]) return u;
	int hd = f, siz = 1;
	for (int e = pre[f]; e > 0; e = pre[e]) {
		hd = e;
		siz++;
	}
	if (end[u] == 0 && nxt[f] == 0 && (hd != beg[u] || deg[u] == siz))
		ret = min(ret, u);
	for (int e = head[u]; e; e = nx[e]) {
		if (e == f || pre[e] || beg[u] == e || e == hd) continue;
		ret = min(ret, dfs(to[e], e^1));
	}
	return ret;
}

bool modify(int u, int v, int f=0) {
	if (u == v) {
		end[v] = f;
		return true;
	}
	for (int e = head[u]; e; e = nx[e]) {
		if (e == f) continue;
		if (modify(to[e], v, e^1)) {
			if (f == 0) beg[u] = e;
			else nxt[f] = e, pre[e] = f;
			return true;
		}
	}
	return false;
}

void solve() {
	memset(head, 0, sizeof(head));
	memset(nx, 0, sizeof(nx));
	memset(beg, 0, sizeof(beg));
	memset(end, 0, sizeof(end));
	memset(pre, 0, sizeof(pre));
	memset(nxt, 0, sizeof(nxt));
	memset(deg, 0, sizeof(deg));
	memset(p, 0, sizeof(p));
	tot = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", p+i);
	}
	int u, v;
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	for (int i = 1; i <= n; ++i) {
		int ans = dfs(p[i]);
		printf("%d ", ans);
		assert(modify(p[i], ans));
	}
	putchar('\n');
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) solve();
}

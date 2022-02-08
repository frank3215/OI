#include <bits/stdc++.h>
#define print //printf
#define puts //puts
#define clear(x) memset(x, 0, sizeof(x))

using std::min;

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
	puts("BEGIN");
	int endb = end[u], esiz = end[u]!=0;
	for (; pre[endb] > 0; endb = pre[endb]) esiz++;
	int bege = beg[u], bsiz = beg[u]!=0;
	for (; nxt[bege] > 0; bege = nxt[bege]) bsiz++;
	int cnt = 0;
	for (int e = head[u]; e; e = nx[e]) if (!pre[e]) ++cnt;
	if (esiz == deg[u] && !beg[u]) { beg[u] = endb; bege = end[u]; bsiz = esiz; }
	if (bsiz == deg[u] && !end[u]) { end[u] = bege; endb = beg[u]; esiz = bsiz; }
	if (beg[u] && end[u] && bsiz+esiz == deg[u]) { nxt[bege] = endb; pre[endb] = bege; endb = beg[u]; bege = end[u]; bsiz = esiz = deg[u]; cnt = 1; }
	if (cnt == 3 && beg[u] && end[u]) {
		for (int e = head[u]; e; e = nx[e])
			if (e != beg[u] && e != end[u] && e != bege && e != endb) {
				if (!pre[e]) pre[e] = bege, nxt[bege] = e;
				if (!nxt[e]) nxt[e] = endb, pre[endb] = e;
			}
		bege = end[u];
		endb = beg[u];
		bsiz = esiz = n;
		cnt = 1;
	}
	if (cnt == 2 && beg[u] && !end[u]) {
		for (int e = head[u]; e; e = nx[e])
			if (e != beg[u] && e != bege) {
				if (!pre[e]) pre[e] = bege, nxt[bege] = e;
				if (!nxt[e]) end[u] = e;
			}
		bege = end[u];
		endb = beg[u];
		bsiz = esiz = n;
		cnt = 1;
	}
	if (cnt == 2 && !beg[u] && end[u]) {
		for (int e = head[u]; e; e = nx[e])
			if (e != end[u] && e != endb) {
				if (!pre[e]) beg[u] = e;
				if (!nxt[e]) nxt[e] = endb, pre[endb] = e;
			}
		bege = end[u];
		endb = beg[u];
		bsiz = esiz = n;
		cnt = 1;
	}
	if (cnt == 1 && !beg[u] && !end[u]) {
		for (int e = head[u]; e; e = nx[e]) {
			if (!pre[e]) beg[u] = e;
			if (!nxt[e]) end[u] = e;
		}
		bege = end[u];
		endb = beg[u];
		bsiz = esiz = n;
		cnt = 1;
	}
	puts("OK");

	int ret = n+1;
	if (f == 0) {
		if (beg[u]) return dfs(to[beg[u]], beg[u]^1);
		for (int e = head[u]; e; e = nx[e]) {
			if (pre[e] || e == endb) continue;
			ret = min(dfs(to[e], e^1), ret);
		}
		return ret;
	}
	if (nxt[f]) return dfs(to[nxt[f]], nxt[f]^1);
	if (f == end[u]) return u;
	if (end[u] == 0 && nxt[f] == 0 && f != bege) ret = min(ret, u);
	int fbeg = f;
	for (; pre[fbeg] > 0; fbeg = pre[fbeg]);
	for (int e = head[u]; e; e = nx[e]) {
		if (pre[e] || e == fbeg || e == beg[u]) continue;
		if (f == bege && e == endb) continue;
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
	clear(head); clear(nx); clear(beg); clear(end); clear(pre); clear(nxt); clear(deg); clear(p);
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
//	puts("OK");
	for (int i = 1; i <= n; ++i) {
		int ans = dfs(p[i]);
		printf("%d ", ans); fflush(stdout);
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

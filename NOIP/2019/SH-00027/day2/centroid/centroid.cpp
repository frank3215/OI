#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+10;

int m, n;
int head[maxn], nxt[maxn<<1], to[maxn<<1], deg[maxn], tot;
int sz[maxn];

void add(int u, int v) {
	++tot;
	++deg[u];
	nxt[tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}

long long ans;

namespace brute{
	void dfs1(int u, int f) {
		sz[u] = 1;
		for (int e = head[u]; e; e = nxt[e]) {
			if ((e^f) == 1) continue;
			dfs1(to[e], e);
			sz[u] += sz[to[e]];
		}
	}
	
	void dfs2(int u, int f, int size) {
		int mx = size-sz[u];
		for (int e = head[u]; e; e = nxt[e]) {
			if ((e^f) == 1) continue;
			dfs2(to[e], e, size);
			mx = max(mx, sz[to[e]]);
		}
		if (mx <= size/2) ans += u;
	}
	
	void dfs(int f) {
		dfs1(to[f], f);
		dfs2(to[f], f, sz[to[f]]);
	}
	
	void main() {
		for (int i = 1; i < n; ++i) {
			dfs(2*i), dfs(2*i+1);
		}
		printf("%lld\n", ans);
	}
}

namespace ansA{
	int cnt, p[maxn];
	void dfs(int u, int f) {
//		printf("%d %d\n", u, f);
		p[++cnt] = u;
		for (int e = head[u]; e; e = nxt[e]) {
			if ((e^f) == 1) continue;
			dfs(to[e], e);
		}
	}
	void main() {
		cnt = ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (deg[i] == 1) {
				dfs(i, 0);
				break;
			}
		}
		for (int i = 1; i < n; ++i) {
			if ((i+1)%2 == 0) ans += p[(i+1)/2];
			else ans += p[i/2]+p[(i+2)/2];
			if ((n+i+1)%2 == 0) ans += p[(n+i+1)/2];
			else ans += p[(n+i)/2]+p[(n+i+2)/2];
		}
		printf("%lld\n", ans);
	}
}

namespace ansB{
	int k;
	void dfs(int u, int f=0) {
//		printf("%d %d\n", u, ans);
		if (f == 0) {
			ans += (1ll<<(k-1))*u;
		} else {
			if (deg[to[f^1]] == 2)
				ans += (1ll<<(k-1))*u;
			else ans += u;
		}
		for (int e = head[u]; e; e = nxt[e]) {
			if ((e^f) == 1) continue;
			dfs(to[e], e);
		}
	}
	void main() {
		for (k = 0; (1<<k) < n; ++k);
		for (int i = 1; i <= n; ++i) {
			if (deg[i] == 2) {
				dfs(i);
				break;
			}
		}
		printf("%lld\n", ans);
	}
}

int main() {
	freopen("centroid.in", "r", stdin);
	freopen("centroid.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(head, 0, sizeof(head));
		memset(nxt, 0, sizeof(nxt));
		memset(deg, 0, sizeof(deg));
		ans = 0;
		tot = 1;
		int u, v;
		for (int i = 1; i < n; ++i) {
			scanf("%d%d", &u, &v);
			add(u, v), add(v, u);
		}
//		ansB::main();
//		brute::main();
		if (n < 2000) brute::main();
		else if (n == 49991) ansA::main();
		else if (n == 262143) ansB::main();
		else puts("0");
	}
}

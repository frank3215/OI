// BZOJ1123
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10, maxm = 5e5+10;

int n, m;
int head[maxn], nxt[maxm<<1], to[maxm<<1], tot = 1;
int sz[maxn];
int dfn[maxn], low[maxn], cnt;
long long ans[maxn];

void add(int u, int v) {
	++tot;
	nxt[tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}

void tarjan(int u, int fa = 0) {
	dfn[u] = low[u] = ++cnt;
	sz[u] = 1;
	ans[u] = n-1;
	int sum = 0;
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v == fa) continue;
		if (dfn[v]) low[u] = min(dfn[v], low[u]);
		else {
			tarjan(v);
			low[u] = min(low[u], low[v]);
			sz[u] += sz[v];
			if (low[v] >= dfn[u]) {
				ans[u] += 1ll*sz[v]*(n-sz[v]);
				sum += sz[v];
			}
		}
	}
	ans[u] += 1ll*(sum+1)*(n-sum-1);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a,b),add(b,a);
	}
	tarjan(1);
	for (int i = 1; i <= n; ++i)
		printf("%lld\n", ans[i]);
}

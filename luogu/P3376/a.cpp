#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+10, maxm = 1e5+10, inf = 1e9;

int n, m, s, t;
int head[maxn], nxt[maxm<<1], to[maxm<<1], f[maxm<<1], tot = 1;
int dep[maxn], cur[maxn];
long long ans = 0;

void _add(int u, int v, int w) {
	++tot;
	assert(tot < (maxm<<1));
	nxt[tot] = head[u];
	to[tot] = v;
	f[tot] = w;
	head[u] = tot;
}
void add(int u, int v, int w) {
	_add(u, v, w), _add(v, u, 0);
}

bool bfs() {
	queue<int> q;
	q.push(s);
	memset(dep, -1, sizeof(dep));
	dep[s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int e = head[u]; e; e = nxt[e]) {
			if (!f[e]) continue;
			int v = to[e];
			if (dep[v] == -1) {
				dep[v] = dep[u]+1;
				q.push(v);
			}
		}
	}
	return dep[t] != -1;
}

int dfs(int u, int rest = inf) {
	assert(rest != 0);
	if (u == t) return rest;
	int ret = 0;
	for (int &e = cur[u]; e; e = nxt[e]) {
		if (!f[e]) continue;
		int v = to[e], w = f[e];
		if (dep[v] == dep[u]+1) {
			int tmp = dfs(v, min(rest, w));
			ret += tmp;
			f[e^1] += tmp;
			rest -= tmp;
			f[e] -= tmp;
		}
		if (rest == 0) return ret;
	}
	return ret;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	int u, v, w;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}
	while (bfs()) {
		memcpy(cur, head, sizeof(cur));
		ans += dfs(s);
	}
	printf("%lld\n", ans);
}

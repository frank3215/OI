//Minimum cost maximum flow
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using std::min;
const int maxn = 1e6+10, maxm = 1e7+10, inf = 1e9;
int tot = 1, head[maxn], nxt[2*maxm], to[2*maxm], r[2*maxm], c[2*maxm];
int d[maxn], cur[maxn], vis[maxn], pre[maxn], cost[maxn];
int m, n, s, t, ans[2];
void con(int u, int v, int w, int d) {
	++tot;
	r[tot] = w;
	to[tot] = v;
	nxt[tot] = head[u];
	c[tot] = d;
	head[u] = tot;
}
void con2(int u, int v, int w, int d) {
	con(u, v, w, d), con(v, u, 0, -d);
}
int spfa(int s, int t) {
	memset(cost, 0x3f, sizeof(cost));
	memset(vis, 0, sizeof(vis));
	memset(pre, 0, sizeof(pre));
	std::queue<int> q;
	q.push(s);
	vis[s] = 1;
	cost[s] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = 0;
		for (int e = head[u]; e; e = nxt[e]) {
			int v = to[e], w = c[e];
			if (r[e] && cost[u]+w < cost[v]) {
				pre[v] = e;
				if (!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}
				cost[v] = cost[u]+w;
			}
		}
	}
	return cost[t] != cost[0];
}
void get(int t) {
	int flow = inf;
	for (int u=t, e; (e = pre[u]); u = to[e^1]) {
		flow = min(flow, r[e]);
	}
	for (int u=t, e; (e = pre[u]); u = to[e^1]) {
		r[e] -= flow;
		r[e^1] += flow;
	}
	ans[0] += flow;
	ans[1] += flow*cost[t];
}
int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	int u, v, w, d;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d%d", &u, &v, &w, &d);
		con2(u, v, w, d);
	}
	while(spfa(s,t)) {
		get(t);
		puts("done");
	}
	printf("%d %d\n", ans[0], ans[1]);
}

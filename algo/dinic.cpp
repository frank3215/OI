#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using std::min;
const int maxn = 1e6+10, maxm = 1e7+10, inf = 1e9;
int tot = 1, head[maxn], nxt[2*maxm], to[2*maxm], r[2*maxm];
int d[maxn], cur[maxn];
int m, n, s, t, ans;
namespace dinic{
	void con(int u, int v, int w) {
		++tot;
		r[tot] = w;
		to[tot] = v;
		nxt[tot] = head[u];
		head[u] = tot;
	}
	void con2(int u, int v, int w) {
		con(u, v, w), con(v, u, 0);
	}
	int bfs(int s, int t) {
		memset(d, 0, sizeof(d));
		std::queue<int> q;
		q.push(s);
		d[s] = 1;
		while(!q.empty()) {
			int u = q.front(); q.pop();
	//		printf(" %d %d\n", u, d[u]);
			for (int e = head[u]; e; e = nxt[e]) {
				int v = to[e];
	//			printf("[%d %d %d]\n", v, d[v], r[e]);
				if (r[e] && !d[v]) {
					d[v] = d[u] + 1;
					q.push(v);
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			cur[i] = head[i];
		}
	//	printf(" %d\n", d[t]);
		return d[t];
	}
	int dfs(int u, int b) {
	//	printf("(%d %d %d)\n", u, d[u], b);
		int res = 0;
		if (u == t) return b;
		for (int &e = cur[u]; e; e = nxt[e]) {
			int v = to[e];
	//		printf("%d(%d %d %d)\n", e, v, d[v], r[e]);
			if (d[v] != d[u]+1 || !r[e]) continue;
			int tmp = dfs(v, min(b, r[e]));
			b -= tmp;
			r[e] -= tmp;
			r[e^1] += tmp;
			res += tmp;
			if (b == 0) break;
		}
		return res;
	}
}
int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	int u, v, w;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		con2(u, v, w);
	}
	while(bfs(s,t)) {
		ans += dfs(s,inf);
	}
	printf("%d\n", ans);
}

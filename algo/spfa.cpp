#include <cstdio>
#include <queue>
#include <cstring>
const int maxn = 1e6, maxm = 1e7;
int tot=1, head[maxn], nxt[maxm<<1], to[maxm<<1], c[maxm<<1];
int vis[maxn], dis[maxn];
int m, n, s, t;
void con(int u, int v, int w=0) {
	++tot;
	nxt[tot] = head[u];
	head[u] = tot;
	to[tot] = v;
	c[tot] = w;
}
void con2(int u, int v, int w) {
	con(u, v, w);
	con(v, u, w);
}
void spfa(int s) {
	std::queue<int> q;
	q.push(s);
	vis[s] = 1;
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
//		printf("(%d %d)\n", u, dis[u]);
		vis[u] = 0;
		for (int e = head[u]; e; e = nxt[e]) {
			int v = to[e], w = c[e];
//			printf("[%d %d]\n", v, w);
			if (dis[u]+w < dis[v]) {
				if (!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}
				dis[v] = dis[u]+w;
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	int u, v, w;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		con2(u, v, w);
	}
	spfa(s);
	printf("%d\n", dis[t]);
}

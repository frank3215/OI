#include <cstdio>
int tot=1, head[maxn], nxt[maxn], to[maxn], c[maxn];
void con(int u, int v, int w=0) {
	++tot;
	nxt[tot] = head[u];
	head[u] = nxt[tot];
	to[tot] = v;
	c[tot] = w;
}
void con2(int u, int v, int w) {
	con(u, v, w);
	con(v, u, w);
}

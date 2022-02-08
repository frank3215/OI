#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+10, maxm = maxn<<1;

int n;
int head[maxn], nxt[maxm], to[maxm], tot = 1;
double p[maxm], q[maxn], f[maxn], g[maxn];

void add(int a, int b, double c) {
	++tot;
	nxt[tot] = head[a];
	to[tot] = b;
	p[tot] = c;
	head[a] = tot;
}
void add2(int a, int b, double c) { con(a,b,c), con(b,a,c); }

void dfs1(int u, int f) {
	f[u] = 1-q[u];
	for (int e = head[u]; e; e = nxt[e]) {
		if (to[u] == f) continue;
		dfs1(to[u], u);
		f[u] *= (1-f[to[u]]*p[e]);
	}
	f[u] = 1-f[u];
}

void dfs2(int u, int f) {
	if (f) {
		if (f[f] == 1) {
			f[u] = 1-(1-f[u])*(1-f[to[f^1]]*p[f])/(1-f[u]*p[f]);
		}
	}
	for (int e = head[u]; e; e = nxt[e]) {
		if ((u^f) == 1) continue;
		dfs2(to[e], e);
	}
}

int main() {
	scanf("%d",&n);
	for (int i = 0; i < n-1; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		con2(a,b,c/100.0);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%lf", q+i);
		q[i] /= 100.0;
	}
	dfs1(1);
	dfs2(1);
}

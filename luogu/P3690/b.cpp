#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int val[N], r[N], ch[N][2], fa[N], tot, ans[N];
int n, m, op, x, y;

bool isroot(int u) { return ch[fa[u]][0]!=u && ch[fa[u]][1]!=u; }
bool which(int u) { assert(!isroot(u)); return ch[fa[u]][1]==u; }
void pushup(int u) { ans[u] = ans[ch[u][0]]^val[u]^ans[ch[u][1]]; }
void rotate(int u) {
	int f = fa[u], w = which(u);
	fa[u] = fa[f];
	if (!isroot(f)) ch[fa[f]][which(f)] = u;
	fa[ch[u][!w]] = f, ch[f][w] = ch[u][!w];
	fa[f] = u, ch[u][!w] = f;
	pushup(f), pushup(u);
}
void rev(int u) {
	if (!u) return;
	swap(ch[u][0], ch[u][1]);
	r[u] ^= 1;
}
void pushdown(int u) {
	if (r[u]) {
		rev(ch[u][0]), rev(ch[u][1]);
		r[u] = 0;
	}
}
int st[N], tp;
void update(int u) {
	if (!isroot(u)) update(fa[u]);
	pushdown(u);
}
void splay(int u) {
	update(u);
	for (; !isroot(u);) {
		if (!isroot(fa[u])) rotate(which(u)==which(fa[u])?fa[u]:u);
		rotate(u);
	}
}

void access(int u) {
	int preu = u;
	for (int v = 0; u; v = u, u = fa[u]) {
		splay(u), ch[u][1] = v, pushup(u);
	}
	splay(preu);
}
void makeroot(int u) {
	access(u);
	rev(u);
}
int find(int u) {
	access(u);
	while (pushdown(u), ch[u][0]) u = ch[u][0];
	splay(u);
	return u;
}
void split(int u, int v) {
	makeroot(u);
	access(v);
}
bool link(int u, int v) {
	makeroot(u);
	if (find(v) == u) return false;
	fa[u] = v;
	return true;
}
bool cut(int u, int v) {
	makeroot(u);
	if (find(v) != u || fa[v] != u || ch[v][0]) return false;
	fa[v] = ch[u][1] = 0;
	pushup(u);
	return true;
}

signed main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", val+i);
	while (m--) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 0) {
			split(x, y);
			printf("%d\n", ans[y]);
		}
		if (op == 1) {
			link(x, y);
		}
		if (op == 2) {
			cut(x, y);
		}
		if (op == 3) {
			splay(x);
			val[x] = y;
			pushup(x);
		}
	}
}

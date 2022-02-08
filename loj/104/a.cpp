#include <bits/stdc++.h>
//#define int long long
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
using namespace std;

const int N = 1e5+10;

int rt, ch[N][2], fa[N], key[N], cnt[N], siz[N], tot;

void pushup(int u) {
	siz[u] = siz[ch[u][1]] + cnt[u] + siz[ch[u][0]];
}
bool which(int u) { return ch[fa[u]][1] == u; }
void rotate(int u) {
	assert(fa[u]);
	int f = fa[u], gf = fa[f], w = which(u), fw = which(f);
	ch[gf][fw] = u, fa[u] = gf;
	ch[f][w] = ch[u][!w], fa[ch[u][!w]] = f;
	ch[u][!w] = f, fa[f] = u;
	pushup(f), pushup(u);
}
void splay(int u) {
	for (int f; f = fa[u];) {
		if (fa[f])
			rotate(which(u)==which(f)?f:u);
		rotate(u);
	}
	rt = u;
}

int kth(int k) {
	int u = rt;
	while (1) {
		if (k <= siz[ch[u][0]]) {
			u = ch[u][0];
		} else if (k <= siz[ch[u][0]]+cnt[u]) {
			break;
		} else {
			k -= siz[ch[u][0]]+cnt[u];
			u = ch[u][1];
		}
	}
	splay(u);
	return key[u];
}
int pre(bool w) {
	int u = ch[rt][w];
	while (ch[u][!w]) u = ch[u][!w];
	splay(u);
	return key[u];
}

void del(int u) {
	assert(u == rt);
	if (!ch[u][0] && !ch[u][1]) {
		rt = 0;
	} else if (!ch[u][1]) {
		rt = ch[u][0];
		fa[rt] = 0;
	} else if (!ch[u][0]) {
		rt = ch[u][1];
		fa[rt] = 0;
	} else {
		pre(0);
		ch[rt][1] = ch[u][1];
		fa[ch[u][1]] = rt;
	}
}
void modify(int x, int d) {
	int u = rt, f = 0;
	while (u && key[u] != x) f = u, u = ch[u][key[u]<x];
	if (u) cnt[u]+=d;
	else {
		u = ++tot;
		if (f) ch[f][key[f]<x] = u;
		fa[u] = f;
		key[u] = x;
		cnt[u] = d;
	}
	splay(u);
	if (!cnt[u]) del(u);
}
int rank(int x) {
	modify(x,0);
	return siz[ch[rt][0]]+1;
}

signed main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int op, x;
		scanf("%d%d", &op, &x);
		if (1 == op) modify(x, 1);
		if (2 == op) modify(x, -1);
		if (3 == op) printf("%d\n", ::rank(x));
		if (4 == op) printf("%d\n", kth(x));
		if (5 == op) modify(x,1),printf("%d\n", pre(0)), modify(x,-1);
		if (6 == op) modify(x,1),printf("%d\n", pre(1)), modify(x,-1);
		//printf("rt=%d\n", rt);
		//FOR(i,1,tot+1) printf(" %d(fa=%d val=%d) %d %d\n", i, fa[i], key[i], ch[i][0], ch[i][1]);
	}
}


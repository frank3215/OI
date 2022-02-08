#include <bits/stdc++.h>
#define NDEBUG
using namespace std;

const int maxn = 1e5+10;

int n, m, i;
int ch[maxn][2], fa[maxn], rev[maxn], val[maxn], tot[maxn];

inline bool isroot(int x) {
	return x != ch[fa[x]][0] && x != ch[fa[x]][1];
}
inline bool which(int x) {
	assert(!isroot(x));
	return x == ch[fa[x]][1];
}
void reverse(int x) {
	if (!x) return;
	rev[x] ^= 1;
	swap(ch[x][0], ch[x][1]);
}
void pushdown(int x) {
	if (rev[x]) {
		reverse(ch[x][0]);
		reverse(ch[x][1]);
	}
	rev[x] = 0;
}
void pushup(int x) {
	tot[x] = tot[ch[x][0]]^val[x]^tot[ch[x][1]];
}
void rotate(int x) {
	assert(!isroot(x));
	int w = which(x), f = fa[x], g = fa[f];
	assert(!rev[x] && !rev[f]);
	if (!isroot(f)) {
		int fw = which(f);
		assert(!rev[g]);
		ch[g][fw] = x;
	}
	fa[x] = g;
	ch[f][w] = ch[x][!w]; fa[ch[f][w]] = f;
	ch[x][!w] = f; fa[f] = x;
	pushup(f), pushup(x);
}
void update(int x) {
	if (!isroot(x)) update(fa[x]);
	pushdown(x);
}
void splay(int x) {
	update(x);
	int cnt = 0;
	for (; !isroot(x);) {
		int f = fa[x];
		if (!isroot(f)) rotate(which(f) == which(x) ? f : x);
		rotate(x);
		++cnt;
	}
//	if (i > 100001) printf("splay:%d\n", cnt);
}
void access(int x) {
	for (int y = 0; x; y = x, x = fa[x])
		splay(x), ch[x][1] = y, pushup(x);
}
void makeroot(int x) {
	access(x), splay(x);
	reverse(x);
}
int find(int x) {
	access(x), splay(x);
	while (pushdown(x), ch[x][0]) x = ch[x][0];
	splay(x);
	return x;
}
void split(int x, int y) {
	makeroot(x);
	access(y), splay(y);
}
bool link(int x, int y) {
	makeroot(x);
	if (find(y) == x) return 0;
	fa[x] = y;
	return 1;
}
bool cut(int x, int y) {
	makeroot(x);
	if (find(y) != x || fa[y] != x || ch[y][0]) return 0;
	fa[y] = ch[x][1] = 0;
	pushup(x);
	return 1;
}
void print() {
	printf("%d\n", tot[0]);
	for (int i = 1; i <= n; ++i) {
		printf("%d: rev(%d), ch(%d,%d), fa(%d), val(%d), tot(%d)\n", i, rev[i], ch[i][0], ch[i][1], fa[i], val[i], tot[i]);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i) {
		scanf("%d", val+i);
		pushup(i);
	}
	int cmd, x, y;
	for (i = 1; i <= m; ++i) {
		scanf("%d%d%d", &cmd, &x, &y);
//		printf("%d: %d %d %d\t%f\n", i, cmd, x, y, (double)clock()/CLOCKS_PER_SEC);
		if (cmd == 0) {
//			print();
			split(x, y);
//			pushup(y);
			printf("%d\n", tot[y]);
		} else if (cmd == 1) {
			bool ret = link(x, y);
//			printf("link:%d\n", ret);
		} else if (cmd == 2) {
			bool ret = cut(x, y);
//			printf("cut:%d\n", ret);
		} else if (cmd == 3) {
			splay(x);
			val[x] = y;
			pushup(x);
		}
//		print();
	}
}

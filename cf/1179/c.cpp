#include <bits/stdc++.h>
#define debug //printf
using namespace std;

const int maxn = 3e5+10, maxx = 1e6;

int n, m, q;
int a[maxn], b[maxn];

struct node{
	int tag, mx;
};

struct seg{
	node t[maxx<<2];
	/*void init(int u, int l, int r) {
		int m = (l+r)>>1;
		init(u<<1, l, m);
		init(u<<1|1, m+1, r);
	}*/
	void modify(int u, int x) {
		t[u].tag += x;
		t[u].mx += x;
	}
	void pushdown(int u) {
		modify(u<<1, t[u].tag);
		modify(u<<1|1, t[u].tag);
		t[u].tag = 0;
	}
	void pushup(int u) {
		t[u].mx = max(t[u<<1].mx, t[u<<1|1].mx);
	}
	void modify(int u, int l, int r, int L, int R, int x) {
		if (L <= l && r <= R) {
//			debug(" [%d](%d, %d): (%d, %d)\n", u, l, r, t[u].mx, t[u].tag);
			modify(u, x);
			debug("[%d](%d, %d): (%d, %d)\n", u, l, r, t[u].mx, t[u].tag);
			return;
		}
//		debug(" [%d](%d, %d): (%d, %d)\n", u, l, r, t[u].mx, t[u].tag);
		pushdown(u);
		int m = (l+r)>>1;
		if (L <= m) modify(u<<1, l, m, L, R, x);
		if (R > m) modify(u<<1|1, m+1, r, L, R, x);
//		debug(" [%d](%d, %d): (%d, %d)\n", u, l, r, t[u].mx, t[u].tag);
		pushup(u);
		debug("[%d](%d, %d): (%d, %d)\n", u, l, r, t[u].mx, t[u].tag);
	}
	int query(int u, int l, int r) {
		debug("[%d](%d, %d): (%d, %d)\n", u, l, r, t[u].mx, t[u].tag);
		if (t[u].mx <= 0) return -1;
		if (l == r) return l;
		pushdown(u);
		int m = (l+r)>>1;
		if (t[u<<1|1].mx > 0) return query(u<<1|1, m+1, r);
		return query(u<<1, l, m);
	}
/*	int query(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			if (t[u].mx > 0) return query(u, l, r);
			else return -1;
		}
		push_down(u, l, r);
		int m = (l+r)>>1, res = -1;
		if (r > m) {
			res = max(res, query(u<<1|1, m+1, r, L, R));
			if (res != -1) return res;
		}
		if (l <= m) res = max(res, query(u<<1, l, m, L, R));
		return res;
	}*/
}t;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
		t.modify(1, 1, maxx, 1, a[i], 1);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", b+i);
		t.modify(1, 1, maxx, 1, b[i], -1);
	}
	scanf("%d", &q);
	while (q--) {
		int op, i, x;
		scanf("%d%d%d", &op, &i, &x);
		if (op == 1) {
			t.modify(1, 1, maxx, 1, a[i], -1);
			t.modify(1, 1, maxx, 1, a[i] = x, 1);
			printf("%d\n", t.query(1, 1, maxx));
		}
		else {
			t.modify(1, 1, maxx, 1, b[i], 1);
			t.modify(1, 1, maxx, 1, b[i] = x, -1);
			printf("%d\n", t.query(1, 1, maxx));
		}
	}
}

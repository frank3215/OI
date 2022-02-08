#include <bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << x << ", "

const int maxn = 1e5+10;

int m, n, st[maxn], tot;

namespace Splay{
	int rt, f[maxn], ch[maxn][2], tot, v[maxn], s[maxn];
	bool r[maxn];
	void debug() {
		for (int x = 0; x <= n; ++x) {
			D(x), D(f[x]), D(ch[x][0]), D(ch[x][1]), D(v[x]), D(s[x]), D(r[x]);
			puts("");
		}
		puts("");
	}
	void reverse(int x) { r[x] ^= 1; }

	void pushdown(int x) {
		if (!r[x]) return;
		reverse(ch[x][0]);
		reverse(ch[x][1]);
		swap(ch[x][0], ch[x][1]);
		r[x] = 0;
	}
	void pushup(int x) { s[x] = v[x]^s[ch[x][0]]^s[ch[x][1]]; }

	inline bool get(int x) { return ch[f[x]][1] == x; }
	inline bool has(int x) { return ch[f[x]][0] == x || ch[f[x]][1] == x; }

	void rotate(int x) {
		assert(has(x));
		int y = f[x], z = f[y], gx = get(x), s = ch[x][!gx];
		if (has(y)) ch[z][get(y)] = x;
		f[s] = y, ch[y][gx] = s;
		ch[x][!gx] = y, f[y] = x;
		f[x] = z;
		pushup(y), pushup(x);
	}

	void splay(int x) {
//		printf("SPLAY %d\n", x);
//		Splay::debug();
		int y = x;
		do {
			st[++tot] = y;
		} while (has(y) && (y=f[y]));
		while (tot) {
			pushdown(st[tot--]);
//			printf("PUSHDOWN %d\n", x);
		}
		while (has(x)) {
			y = f[x];
			if (has(y)) rotate((get(y)==get(x))?y:x);
			rotate(x);
		}
//		Splay::debug();
//		printf("END SPLAY %d\n", x);
	}
}

namespace lct {
	using namespace Splay;
	void change(int x, int y) {
		splay(x);
		v[x] = y;
		pushup(x);
	}
	void access(int x) {
//		printf("ACCESS: %d\n", x);
//		Splay::debug();
		for (int y = 0; x; y = x, x = f[x]) {
			splay(x);
			ch[x][1] = y;
			pushup(x);
		}
//		Splay::debug();
//		printf("END ACCESS: %d\n", x);
	}
	int findroot(int x) {
		access(x);
		splay(x);
		while (pushdown(x), ch[x][0]) x = ch[x][0];
		return x;
	}
	void makeroot(int x) {
		access(x);
		splay(x);
//		debug();
		reverse(x);
	}
	void split(int x, int y) {
		makeroot(x);
		access(y);
		splay(y);
	}
	void link(int x, int y) {
		makeroot(x);
		if (findroot(y) != x) f[x] = y;
	}
	void cut(int x, int y) {
		split(x, y);
		if (findroot(y) == x && f[x] == y && !ch[x][1]) {
			f[x] = ch[y][0] = 0;
			pushup(y);
		}
	}
	int query(int x, int y) {
		split(x, y);
		return s[y];
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", Splay::v+i);
	}
	int op, x, y;
	while (m--) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 0) printf("%d\n", lct::query(x, y));
		if (op == 1) lct::link(x, y);
		if (op == 2) lct::cut(x, y);
		if (op == 3) lct::change(x, y);
//		Splay::debug();
	}
}


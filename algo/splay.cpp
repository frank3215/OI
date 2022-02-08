#include <bits/stdc++.h>
#define debug //printf
#define dbg(x) cout << #x << " = " << x << endl;
using namespace std;

const int maxn = 1e5+10;

int rt, f[maxn], ch[maxn][2], tot, v[maxn], s[maxn], cnt[maxn];
bool r[maxn];
int n;

void init(int&, int, int, int fa = 0);

void reverse(int);
void pushdown(int);
void pushup(int);

int kth(int, int);

bool get(int);
void rotate(int);
void splay(int, int fa = 0);

void work(int, int);
void answer(int);

int main() {
	int m;
	scanf("%d%d", &n, &m);
	init(rt, 0, n+1);
	int l, r;
	while (m--) {
		scanf("%d%d", &l, &r);
		work(l, r);
	}
	answer(rt);
	putchar('\n');
}

void reverse(int x) {
	r[x] ^= 1;
}

void pushdown(int x) {
	r[ch[x][0]] ^= r[x];
	r[ch[x][1]] ^= r[x];
	if (r[x]) swap(ch[x][0], ch[x][1]);
	r[x] = 0;
}

void pushup(int x) {
	s[x] = s[ch[x][0]]+s[ch[x][1]]+1;
}

void init(int &x, int l, int r, int fa) {
	if (l > r) return;
	x = ++tot;
	int m = (l+r)>>1;
	v[x] = m;
	f[x] = fa;
	init(ch[x][0], l, m-1, x);
	init(ch[x][1], m+1, r, x);
	pushup(x);
}

int kth(int u, int k) {
	pushdown(u);
	if (k == s[ch[u][0]]+1) return u;
	else if (k <= s[ch[u][0]]) return kth(ch[u][0], k);
	else return kth(ch[u][1], k-s[ch[u][0]]-1);
}

inline bool get(int x) { return ch[f[x]][1] == x; }

void rotate(int x) {
	int fx = f[x], ffx = f[fx], gx = get(x), gfx = get(fx), s = ch[x][!gx];
	f[s] = fx, ch[fx][gx] = s;
	ch[x][!gx] = fx, f[fx] = x;
	f[x] = ffx, ch[ffx][gfx] = x;
	pushup(x), pushup(fx);
}

void splay(int x, int fa) {
	while (f[x] != fa) {
		int fx = f[x];
		if (fx && f[fx] != fa) rotate((get(fx)==get(x))?fx:x);
		rotate(x);
	}
	if (fa == 0) rt = x;
}

void work(int L, int R) {
	int l = kth(rt, L), r = kth(rt, R+2);
	splay(l);
	splay(r, l);
	reverse(ch[r][0]);
}

void answer(int x) {
	if (x == 0) return;
	pushdown(x);
	answer(ch[x][0]);
	if (1 <= v[x] && v[x] <= n) printf("%d ", v[x]);
	answer(ch[x][1]);
}

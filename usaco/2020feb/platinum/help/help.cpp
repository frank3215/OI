#include <bits/stdc++.h>
#define L first
#define R second
using namespace std;

const int N = 1e5+10, K = 11, P = 1e9+7;

int n, k, ans;
int C[K][K], f[N<<1][K];
pair<int,int> p[N];

struct node{
	int dat[K], ch[2], rnd, val, mul;
	int sum[K];
	node() { rnd = rand(), mul = 1; }
}t[N<<1];

void pushup(int u) {
	assert(u);
	for (int i = 0; i <= k; ++i) {
		t[u].sum[i] = ((t[u].dat[i]+t[t[u].ch[0]].sum[i])%P+t[t[u].ch[1]].sum[i])%P;
	}
}
void mult(int u, int x) {
	if (!u) return;
	t[u].mul = 1ll*t[u].mul*x%P;
	for (int i = 0; i <= k; ++i) {
		t[u].dat[i] = 1ll*t[u].dat[i]*x%P;
		t[u].sum[i] = 1ll*t[u].sum[i]*x%P;
	}
}
void pushdown(int u) {
	assert(u);
	if (t[u].mul == 1) return;
	if (t[u].ch[0]) mult(t[u].ch[0], t[u].mul);
	if (t[u].ch[1]) mult(t[u].ch[1], t[u].mul);
	t[u].mul = 1;
}
void split(int u, int &a, int &b, int x) {
	if (!u) { a = b = 0; return; }
	pushdown(u);
	if (t[u].val < x) {
		a = u;
		split(t[u].ch[1], t[a].ch[1], b, x);
	} else {
		b = u;
		split(t[u].ch[0], a, t[b].ch[0], x);
	}
	pushup(u);
}
int merge(int a, int b) {
	if (!a || !b) return a+b;
	int ret = 0;
	if (t[a].rnd > t[b].rnd) {
		ret = a;
		pushdown(a);
		t[ret].ch[1] = merge(t[a].ch[1], b);
	} else {
		ret = b;
		pushdown(b);
		t[ret].ch[0] = merge(a, t[b].ch[0]);
	}
	pushup(ret);
	return ret;
}
void init() {
	for (int i = 0; i <= k; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = C[i-1][j-1]+C[i-1][j];
		}
	}
}

void debug(int j) {
	printf("%d: %d %d %d\n", j, t[j].ch[0], t[j].ch[1], t[j].mul);
	printf(" %d: ", j);
	for (int l = 0; l <= k; ++l) printf("%d%c", t[j].dat[l], " \n"[l==k]);
	printf(" %d: ", j);
	for (int l = 0; l <= k; ++l) printf("%d%c", t[j].sum[l], " \n"[l==k]);
}

int main() {
	freopen("help.in", "r", stdin);
	freopen("help.out", "w", stdout);
	srand(19260817);
	scanf("%d%d", &n, &k);
	init();
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p[i].L, &p[i].R);
	}
	sort(p, p+n);
	int rt = 2*n+1;
	t[rt].dat[0] = 1;
	t[rt].val = 0;
	pushup(rt);
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		split(rt, a, b, p[i].L);
//		printf("%d %d\n", a, b);
//		debug(a);
		for (int l = 0; l <= k; ++l) {
			for (int _ = 0; _ <= l; ++_) {
				(t[p[i].R].dat[l] += 1ll*C[l][_]*t[a].sum[_]%P) %= P;
			}
		}
//		debug(p[i].R);
		split(b, b, c, p[i].R);
//		printf("%d %d\n", b, c);
		for (int l = 0; l <= k; ++l) {
			(t[p[i].R].dat[l] += t[b].sum[l]) %= P;
		}
//		debug(p[i].R);
		mult(c, 2);
		t[p[i].R].val = p[i].R;
		pushup(p[i].R);
		rt = merge(p[i].R, c);
		rt = merge(b, rt);
		rt = merge(a, rt);
//		debug(rt);
//		printf("%d\n", rt);
	}
	printf("%d\n", t[rt].sum[k]);
}

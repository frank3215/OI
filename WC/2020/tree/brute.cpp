#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); ++i)
#define mp make_pair
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

const int N = 5e5+10;

int n;
int head[N], nxt[N<<1], to[N<<1], tot;

int cnt, st[N], val[N];
bool c[N];

void add(int u, int v) { nxt[++tot] = head[u], to[tot] = v, head[u] = tot; }
#define trav(u,e,v) for (int e = head[u], v; e && (v = to[e], 1); e = nxt[e])

int dfs1(int u, int f) {
	int sum = st[u];
	trav(u,e,v) {
		if (v == f) continue;
		sum += dfs1(v, u);
	}
	val[u] = st[u] ? sum : 0;
	return sum;
}

int check(int u, int f, int mid) {
	c[u] = u==1||val[u]>mid;
	int ret = 0;
	trav(u,e,v) {
		if (v == f) continue;
		ret += check(v, u, mid);
		c[u] |= c[v];
	}
	ret += c[u]&&st[u];
	return ret;
}

bool check(int mid) {
	return check(1, 0, mid) <= mid;
}

signed main() {
#ifndef STDIO
	freopen("tree.in", "r", stdin);
	freopen("tree.ans", "w", stdout);
#endif
	scanf("%d", &n);
	FOR(i,0,n-1) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int t, v;
		scanf("%d%d", &t, &v);
		cnt -= st[v]; st[v] ^= 1; cnt += st[v];
		dfs1(1, 0);
		int l = 0, r = n;
		while (l < r) {
			int mid = (l+r)>>1;
			if (check(mid)) r = mid;
			else l = mid+1;
		}
		printf("%d\n", l);
	}
}

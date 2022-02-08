#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5+10;
#define p //printf

int n, q;
int head[maxn], nxt[maxn<<1], to[maxn<<1], tot;
int din[maxn], dout[maxn], cnt;
long long val[maxn<<2], tag[maxn<<2];
set<pair<int,int> > s[maxn];

void add(int u, int v) {
	++tot;
	nxt[tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}

void dfs(int u, int f) {
	din[u] = ++cnt;
	for (int e = head[u]; e; e = nxt[e]) {
		int v = to[e];
		if (v != f) dfs(v, u);
	}
	dout[u] = cnt;
}

void update(int u, int l, int r, int x) {
	tag[u] += x;
	val[u] += 1ll*(r-l+1)*x;
}
void pushdown(int u, int l, int r) {
	assert(l != r);
	int m = l+r>>1;
	update(u<<1, l, m, tag[u]);
	update(u<<1|1, m+1, r, tag[u]);
	tag[u] = 0;
}
void pushup(int u) {
	val[u] = val[u<<1]+val[u<<1|1];
}
long long query(int u, int L, int R, int l, int r, int x=0) {
	assert(u < (maxn<<2));
	if (L <= l && r <= R) {
		update(u, l, r, x);
		return val[u];
	}
	pushdown(u, l, r);
	int m = l+r>>1;
	long long ans = 0;
	if (L <= m) ans += query(u<<1, L, R, l, m, x);
	if (R > m) ans += query(u<<1|1, L, R, m+1, r, x);
	pushup(u);
	return ans;
}

void addcol(int l, int r, int c) {
	int L = l, R = r;
//	cout << ' ' << c << endl;
	for (set<pair<int,int> >::iterator it = s[c].lower_bound(make_pair(l, 0)); it != s[c].end() && r >= it->second; s[c].erase(it++)) {
		query(1, it->second, it->first, 1, n, -1);
		L = min(L, it->second);
		R = max(R, it->first);
	}
	s[c].insert(make_pair(R, L));
//	cout << c << ' ' << L << ' ' << R << endl;
	query(1, L, R, 1, n, 1);
}

signed main() {
	freopen("snowcow.in", "r", stdin);
	freopen("snowcow.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		add(u, v), add(v, u);
	}
	dfs(1, 0);
	int op, x, c;
	while (q--) {
		cin >> op >> x;
		if (op == 2) {
//			p("%d %d\n", din[x], dout[x]);
			cout << query(1, din[x], dout[x], 1, n) << endl;
		} else {
			cin >> c;
			addcol(din[x], dout[x], c);
		}
	}
}

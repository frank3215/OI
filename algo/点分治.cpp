#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int maxn = 2e5+10, inf = 1e9, maxk = 1e6+10;
typedef pair<int, int> pii;

int n, k, ans = maxn;
vector<pii> e[maxn];
bool v[maxn];

int c[maxk], st[maxn], tp;
// void _c(int x, int y) { c[st[++tp]=x] = y; }
void ask(int x, int f, int dis, int cnt) {
//	cerr << x << endl;
	if (dis > k) return;
	ans = min(ans, c[k-dis]+cnt);
	for (int i = 0; i < e[x].size(); ++i) {
		int y = e[x][i].fi, z = e[x][i].se;
		if (v[y] || y == f) continue;
		ask(y, x, dis+z, cnt+1);
	}
}
void upd(int x, int f, int dis, int cnt) {
	if (dis > k) return;
	st[++tp] = dis;
	c[dis] = min(c[dis], cnt);
	for (int i = 0; i < e[x].size(); ++i) {
		int y = e[x][i].fi, z = e[x][i].se;
		if (v[y] || y == f) continue;
		upd(y, x, dis+z, cnt+1);
	}
}

int rt, sz, s[maxn], t[maxn];
void getrt(int x, int f=0) {
//	cout << "GETRT: " << x << " " << f << endl;
	t[x] = 0;
	s[x] = 1;
	for (int i = 0; i < e[x].size(); ++i) {
		int y = e[x][i].fi;
		if (v[y] || y == f) continue;
		getrt(y, x);
		s[x] += s[y];
		t[x] = max(t[x], s[y]);
	}
	t[x] = max(t[x], sz-s[x]);
	if (t[x] < t[rt]) rt = x;
}

void dfs(int x) {
//	cerr << "DFS: " << x << endl;
	v[x] = 1;
	st[++tp] = 0;
	c[0] = 0;
	for (int i = 0; i < e[x].size(); ++i) {
		int y = e[x][i].fi, z = e[x][i].se;
		if (v[y]) continue;
		ask(y, x, z, 1);
		upd(y, x, z, 1);
	}
	while (tp) c[st[tp--]] = inf;
	for (int i = 0; i < e[x].size(); ++i) {
		int y = e[x][i].fi;
		if (v[y]) continue;
		sz = s[y];
		rt = 0;
		getrt(y);
		dfs(rt);
	}
}

int main() {
	scanf("%d%d", &n, &k);
	int x, y, z;
	for (int i = 0; i < n-1; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		++x, ++y;
		e[x].pb(mp(y,z));
		e[y].pb(mp(x,z));
	}
	for (int i = 0; i < maxk; ++i) c[i] = maxn;
	t[rt=0] = maxn;
	sz = n;
	getrt(1);
	dfs(rt);
	printf("%d\n", ans==inf?-1:ans);
}

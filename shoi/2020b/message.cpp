#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,b,a) for (int i = (b-1); i >= a; --i)
using namespace std;

const int N = 1e5+10;

int n, m;
int ans[N];

int head[N], nxt[N<<1], to[N<<1], tot;
void _add(int u, int v) {
	nxt[tot] = head[u];
	to[tot] = v;
	head[u] = tot++;
}
void add(int u, int v) {
	_add(u, v), _add(v, u);
}
#define trav(u,e,v) for (int e = head[u], v; e != -1 && (v = to[e], 1); e = nxt[e])

int vis[N];
int rt, sz;
int dep[N], tr[N], siz[N];
void get_rt(int SZ, int u, int f) {
	//printf("  %d %d %d\n", SZ, u, f);
	siz[u] = 1;
	int ret = 0;
	trav(u,e,v) {
		if (v == f || vis[v]) continue;
		get_rt(SZ, v, u);
		siz[u] += siz[v];
		ret = max(ret, siz[v]);
	}
	ret = max(ret, SZ-siz[u]);
	if (ret < sz) rt = u, sz = ret;
}

vector<int> vec[N];
vector<pair<int,int> > Q[N];
void dfs(int u, int f) {
	siz[u] = 1;
	dep[u] = dep[f]+1;
	if ((int)vec[tr[u]].size() <= dep[u]) vec[tr[u]].resize(dep[u]+1);
	vec[rt][dep[u]]++;
	vec[tr[u]][dep[u]]++;
	trav(u,e,v) {
		if (v == f || vis[v]) continue;
		tr[v] = tr[u];
		dfs(v, u);
		siz[u] += siz[v];
	}
}

void dfs2(int u, int f) {
	FOR(_,0,(int)Q[u].size()) {
		int i = Q[u][_].fi, k = Q[u][_].se;
		//printf("Query %d: %d %d    dep[%d] = %d\n", i, u, k, u, dep[u]);
		if (dep[u] <= k) {
			if ((k-dep[u]) < (int)vec[rt].size()) {
				//printf(" +%d\n", vec[rt][k-dep[u]]);
				ans[i] += vec[rt][k-dep[u]];
			}
			if ((k-dep[u]) < (int)vec[tr[u]].size()) {
				//printf(" -%d\n", vec[tr[u]][k-dep[u]]);
				ans[i] -= vec[tr[u]][k-dep[u]];
			}
		}
	}
	trav(u,e,v) {
		if (v == f || vis[v]) continue;
		dfs2(v, u);
	}
}

void divide(int u, int SZ) {
	rt = 0, sz = SZ;
	get_rt(SZ, u, u);
	u = rt;
	//printf(" %d %d\n", u, SZ);
	// Pre
	dep[u] = 0;
	vec[u] = vector<int>(SZ+1);
	vec[u][0]++;
	trav(u,e,v) {
		if (vis[v]) continue;
		tr[v] = v;
		vec[v].clear();
		dfs(v, u);
	}
	// Count
	//FOR(i,0,SZ+1) printf("  vec[%d][%d] = %d\n", u, i, vec[u][i]);
	trav(u,e,v) {
		if (vis[v]) continue;
		dfs2(v, u);
	}
	FOR(_,0,(int)Q[u].size()) {
		int i = Q[u][_].fi, k = Q[u][_].se;
		if (k < (int)vec[rt].size()) ans[i] += vec[rt][k];
	}
	// Divide
	vis[u] = 1;
	trav(u,e,v) {
		if (vis[v]) continue;
		divide(v, siz[v]);
	}
}

void solve() {
	memset(head, -1, sizeof(head)); tot = 0;
	memset(vis, 0, sizeof(vis));
	memset(ans, 0, sizeof(ans));
	scanf("%d%d", &n, &m);
	FOR(i,0,n-1) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u,v);
	}
	FOR(i,1,n+1) Q[i].clear();
	FOR(i,0,m) {
		int x, k;
		scanf("%d%d", &x, &k);
		Q[x].pb(mp(i,k));
	}
	divide(1, n);
	FOR(i,0,m) printf("%d\n", ans[i]);
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("transfer.in", "r", stdin);
	freopen("transfer.out", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--) solve();
}


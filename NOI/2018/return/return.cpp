#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sd(x) scanf("%d", &x)
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
#define debug(x) cout << #x << " = " << x << endl
#define FIO(x) \
	freopen(x ".in", "r", stdin); \
	freopen(x ".out", "w", stdout);
#define print(a,n) cout << #a << " = ";_print(a,n);
void _print(int *a, int n) { FOR(i,0,n) printf("%d%c", a[i], " \n"[i==n-1]); }
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

const int MAXN = 2e5+10, MAXM = 8e5+10, MAXLOGN = 18, inf = 2e9;

int n, m;
int gh[MAXN], gx[MAXM], gv[MAXM], gl[MAXM], ga[MAXM], tot = 1;

void _gA(int u, int v, int l, int a) {
	++tot;
	gx[tot] = gh[u];
	gv[tot] = v;
	gl[tot] = l;
	ga[tot] = a;
	gh[u] = tot;
}
void gA(int u, int v, int l, int a) {
	_gA(u, v, l, a), _gA(v, u, l, a);
}
bool cmp(int i, int j) {
	return ga[i] > ga[j];
}

int uf[MAXN<<1];
int uF(int u) { return uf[u] == u ? u : uf[u] = uF(uf[u]); }

int dis[MAXN<<1], vis[MAXN];
void dijkstra() {
	priority_queue<pii> q;
	FOR(i,1,n+1) dis[i] = inf;
	memset(vis, 0, sizeof(vis));
	dis[1] = 0; q.push(mp(0, 1));
	while (!q.empty()) {
		int u = q.top().se; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int e = gh[u]; e; e = gx[e]) {
			int v = gv[e];
			if (dis[v] > dis[u]+gl[e]) {
				dis[v] = dis[u]+gl[e];
				q.push(mp(-dis[v], v));
			}
		}
	}
}

int ge[MAXM], fa[MAXLOGN][MAXN<<1], val[MAXN<<1];
void kruskal() {
	int cnt = n;
	FOR(i,0,m) {
		int e = ge[i], u = uF(gv[e]), v = uF(gv[e^1]);
		if (u != v) {
			fa[0][u] = fa[0][v] = uf[u] = uf[v] = ++cnt;
			dis[cnt] = min(dis[u], dis[v]);
			val[cnt] = ga[e];
		}
	}
	FOR(j,1,MAXLOGN) {
		ROF(i,1,cnt+1) {
			fa[j][i] = fa[j-1][fa[j-1][i]];
		}
	}
}

int solve(int v, int p) {
	ROF(k,0,MAXLOGN) if (val[fa[k][v]] > p) v = fa[k][v];
	return dis[v];
}

int ans;
void solve() {
	scanf("%d%d", &n, &m);
	tot = 1;
	memset(gh, 0, sizeof(gh));
	FOR(i,0,m) {
		int u, v, l, a;
		scanf("%d%d%d%d", &u, &v, &l, &a);
		gA(u, v, l, a);
		ge[i] = tot;
	}
	FOR(i,1,2*n) uf[i] = i;
	sort(ge, ge+m, cmp);
	dijkstra();
	kruskal();
	int q, k, s;
	scanf("%d%d%d", &q, &k, &s);
	ans = 0;
	while (q--) {
		int v, p;
		scanf("%d%d", &v, &p);
		v = (v + (ll)k*ans - 1) % n + 1;
		p = (p + (ll)k*ans) % (s + 1);
		ans = solve(v, p);
		printf("%d\n", ans);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	FIO("return");
#endif
	int t;
	scanf("%d", &t);
	while (t--) solve();
}

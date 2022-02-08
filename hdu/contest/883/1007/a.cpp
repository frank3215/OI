/*{{{*/
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) (int)(x).size()
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define mset(x,c) memset(x, c, sizeof(x))
#define clr(x) mset(x,0)
#define FI(x) freopen(x ".in", "r", stdin)
#define FO(x) freopen(x ".out", "w", stdout)
#define FIO(x) FI(x);FO(x)
#define P(a,n) FOR(_,0,n) _W(a),printf("%c", " \n"[_==n-1])
#define print(a,n) cout << #a << " = ";FOR(_,0,n) _W(a),printf("%c", " \n"[_==n-1])
using namespace std;

template<class T> void _R(T &x) { cin >> x; }
void _R(signed &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const signed &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef LOCAL
 #define debug(...) {printf(" [" #__VA_ARGS__ "]: ");W(__VA_ARGS__);}
#else
 #define debug(...)
#endif

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
/*}}}*/

const int N = 2e5+10;

vector<pii> adj[N];

int n, k;
ll ans, f[N], mn[N];

void dfs(int u, int fa) {
	vector<ll> vec;
	for (auto p: adj[u]) {
		int w = p.fi, v = p.se;
		if (v == fa) continue;
		dfs(v, u);
		vec.pb(f[v]+w);
	}
	sort(rall(vec));
	FOR(i,0,min(k-1,SZ(vec))) {
		f[u] += vec[i];
	}
	if (!fa) {
		mn[u] = k-1<SZ(vec) ? vec[k-1] : 0;
	}
}

void dfs2(int u, int fa, ll val) {
	int oldf, oldfu;
	if (fa) {
		oldf = f[fa];
		oldfu = f[u];
		if (mn[fa] < val) {
			f[fa] -= val;
			f[fa] += mn[fa];
		}
	}
	ll cur = 0;
	vector<ll> vec;
	for (auto p: adj[u]) {
		int w = p.fi, v = p.se;
		cur += f[v]+w;
		vec.pb(f[v]+w);
	}
	ans = max(ans, cur);
	sort(rall(vec));
	f[u] = 0;
	FOR(i,0,min(k-1,SZ(vec))) f[u] += vec[i];
	mn[u] = k-1<SZ(vec) ? vec[k-1] : 0;
	for (auto p: adj[u]) {
		int w = p.fi, v = p.se;
		if (v == fa) continue;
		dfs2(v, u, f[v]+w);
	}
	if (fa) {
		f[fa] = oldf;
		f[u] = oldfu;
	}
}

void dfs3(int u, int fa) {
	vector<ll> vec;
	ll cur = 0;
	for (auto p: adj[u]) {
		int w = p.fi, v = p.se;
		if (v == fa) continue;
		dfs3(v, u);
		vec.pb(f[v]+w);
		cur += f[v]+w;
	}
	sort(rall(vec));
	FOR(i,0,min(k-1,SZ(vec))) {
		f[u] += vec[i];
	}
	if (!fa) {
		mn[u] = k-1<SZ(vec) ? vec[k-1] : 0;
		ans = max(ans, cur);
		debug(u, cur);
	}
}

void dfs4(int u, int fa) {
	FOR(i,1,n+1) {
		f[i] = 0;
	}
	dfs3(u,0);
	for (auto p: adj[u]) {
		int w = p.fi, v = p.se;
		if (v == fa) continue;
		dfs4(v, u);
	}
}

void solve() {
	R(n,k);
	FOR(i,1,n+1) {
		adj[i].clear();
		f[i] = 0;
	}
	FOR(i,0,n-1) {
		int u, v, d;
		R(u, v, d);
		adj[u].pb(mp(d,v));
		adj[v].pb(mp(d,u));
	}
	if (k == 0) puts("0");
	else {
		ans = 0;
		if (1) {
			dfs(1,0);
			dfs2(1,0,0);
		} else {
			dfs4(1,0);
		}
		W(ans);
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	FIO("a");
#endif
	int t; R(t); while (t--) solve();
}

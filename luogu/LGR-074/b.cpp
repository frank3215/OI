/*{{{*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define mset(x,c) memset(x, c, sizeof(x))
#define clr(x) mset(x,0)
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
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.fi); putchar(' '); _W(x.se);}
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
//#define int long long

const int N = 5e5+10;

int head[N], nxt[N<<1], to[N<<1], tot;
int deg[N];
void _add(int u, int v) {
	++tot;
	nxt[tot] = head[u];
	to[tot] = v;
	head[u] = tot;
	deg[u]++;
}
void add(int u, int v) { _add(u, v); _add(v, u); }

int n, m;
int a[N];

ll f[N], g[N];

void dfs(int u, int fa) {
	int res = deg[u]-(deg[u]/2+1);
	ll sum = 0;
	vector<ll> vec;
	for (int e = head[u]; e; e = nxt[e]) {
		int v = to[e];
		if (v == fa) continue;
		dfs(v, u);
		ll cur = max(min(a[v], a[u])+f[v], a[u]+g[v]),
			upd = max(a[v]+f[v], m+g[v]);
//		debug(u, cur, upd);
		sum += cur;
		vec.pb(upd-cur);
	}
	sort(rall(vec));
	f[u] = sum;
	FOR(i,0,res) f[u] += max(0ll, vec[i]);
	if (res >= 1) {
		g[u] = sum;
		FOR(i,0,res-1) g[u] += max(0ll, vec[i]);
	}
//	debug(u, f[u], g[u]);
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	R(n,m);
	FOR(i,1,n+1) R(a[i]);
	FOR(i,0,n-1) {
		int u, v;
		R(u, v);
		add(u, v);
	}
	memset(f, 0xc0, sizeof(f));
	memset(g, 0xc0, sizeof(g));
	dfs(1, 0);
	W(max(f[1], g[1]));
}

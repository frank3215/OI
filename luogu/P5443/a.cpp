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
#define mem0(x) mset(x,0)
#define mem1(x) mset(x,-1)
#define memc(x,y) memcpy(x, y, sizeof(x));
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

const int N = 5e4+10, M = 1e5+10;

int head[N], nxt[M<<1], to[M<<1], cost[M<<1];
int u[M], v[M], w[M];
int a[M], b[M], c[M];

void _add(int u, int v, int w) {
	nxt[tot] = head[u], to[tot] = v, cost[tot] = w, head[u] = tot;
	++tot;
}
void add(int u, int v, int w) { _add(u, v, w); _add(v, u, w); }

signed main() {
	memset(head, -1, sizeof(head));
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	FOR(i,0,m) {
		scanf("%d%d%d", u+i, v+i, w+i);
		add(u, v, w);
	}
	scanf("%d", &q);
	bool 
	FOR(i,0,q) {
		scanf("%d%d%d", a+i, b+i, c+i);
	}
	if (n <= 1000 && m <= 1000 && q <= 10000) brute();
}

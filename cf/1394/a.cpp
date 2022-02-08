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

signed main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int n, d, m;
	R(n,d,m);
	vi x, y;
	FOR(i,1,n+1) {
		int a;
		R(a);
		if (a <= m) x.pb(a);
		else y.pb(a);
	}
	sort(rall(x)); sort(rall(y));
	vector<ll> sx(n+1), sy(n+1);
	FOR(i,0,n) {
		sx[i+1] = (i?sx[i]:0) + (i<x.size()?x[i]:0);
		sy[i+1] = (i?sy[i]:0) + (i<y.size()?y[i]:0);
	}
	ll ans;
	FOR(i,0,(n+d)/(d+1)+1) {
		ans = max(ans, sx[n-max(0,(i-1)*(d+1)+1)] + sy[i]);
	}
	W(ans);
}

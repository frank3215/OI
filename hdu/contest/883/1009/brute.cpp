/*{{{*/
#include <bits/stdc++.h>
//#define int long long
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
#define FI(x) freopen(x ".in", "r", stdin)
#define FO(x) freopen(x ".out", "w", stdout)
#define FIO(x) FI(x);FO(x)
#define print(a,n) cout << #a << " = ";FOR(_,0,n) printf("%d%c", a, " \n"[_==n-1])
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
template<class T,class U> void _W(const pair<T,U> &x) {putchar('('); _W(x.F); printf(", "); _W(x.S); putchar(')'); }
template<class T> void _W(const vector<T> &x) { printf("{"); for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) printf(", "); printf("}"); }
void W() { putchar('\n'); }
template<class T, class... U> void W(const T &head, const U &... tail) { printf(" "); _W(head); W(tail...); }
#ifdef LOCAL
 #define DEBUG(...) {printf(" [" #__VA_ARGS__ "]:");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif


typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
/*}}}*/

const int P = 998244353;

int n;

int qpow(int a, int x=P-2) {
	int ret = 1;
	for (; x; a = 1ll*a*a%P, x >>= 1)
		if (x&1) ret = 1ll*ret*a%P;
	return ret;
}

int dfs(int x, int a=1, int b=1) {
	if (x == n) {
		return 1ll*(a+1)*(b+1)%P;
	}
	return 2ll*(dfs(x+1, 2*a%P, b)+dfs(x+1, a, 2*b%P))%P;
}

signed main() {
#ifndef ONLINE_JUDGE
	FIO("a");
#endif
	int t; R(t); while (t--) {
		R(n);
		printf("%lld\n", 1ll*dfs(0)*qpow(4,P-1-n)%P);
	}
}

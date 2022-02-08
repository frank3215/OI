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

const int N = 1e6+10;

int n, d;
int vis[N];

int phi(int n) {
	int ret = 1;
	for (int i = 2; i <= n; ++i) {
		if (n%i == 0) {
			do {
				n /= i;
				ret *= i;
			} while (n%i == 0);
			ret /= i;
			ret *= i-1;
		}
	}
	return ret;
}

int qpow(int a, int x) {
	int ret = 1;
	for (; x; a = 1ll*a*a%n, x >>= 1)
		if (x&1) ret = 1ll*ret*a%n;
	return ret;
}

int gcd(int x, int y) { return y ? gcd(y, x%y) : x; }

void solve() {
	scanf("%d%d", &n, &d);
	int cnt2 = 0, cntp = 0;
	int nn = n;
	for (int i = 2; i <= n; ++i) {
		if (n%i == 0) {
			cntp += i != 2;
			while (n%i == 0) {
				n /= i;
				cnt2 += i == 2;
			}
		}
	}
	n = nn;
	if (cnt2 >= 3 || cntp >= 2 || cnt2 == 2 && cntp) {
		puts("0");
		putchar('\n');
		return;
	}
	int p = phi(n), q = p;
	vector<int> v;
	for (int i = 2; i <= p; ++i) {
		if (p%i == 0) {
			v.pb(i);
			while (p%i == 0) p /= i;
		}
	}
	int g = -1;
	FOR(i,1,n) if (gcd(i, n) == 1) {
		bool flag = true;
		for (auto x: v) if (qpow(i,q/x) == 1) flag = false;
//		debug(i, flag);
		if (flag) {
			g = i;
			break;
		}
	}
//	debug(n, q, v, g);
//	assert(g != -1);
	int cur = 1;
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	FOR(i,0,q) {
		cur = 1ll*cur*g%n;
		if (gcd(++cnt, q) == 1) vis[cur] = 1;
	}
	cur = 0;
	q = phi(q);
	printf("%d\n", q);
	FOR(i,1,n) {
		if (vis[i] && ++cur % d == 0) printf("%d ", i);
	}
	putchar('\n');
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int t; R(t); while (t--) solve();
}

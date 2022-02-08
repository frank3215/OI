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
#define int long long

const int N = 1e5+10;
int n, m;
int a[N], p[N], b[N], atk[N], mx;
int c[N], d[N];

int gcd(int a, int b) { return b?gcd(b,a%b):a; }
int lcm(int a, int b) { return a/gcd(a,b)*b; }

int _gcd;
void exgcd(int a, int b, int &x, int &y) {
	if (!b) { y = 0; x = 1; _gcd = a; return; }
	exgcd(b, a%b, y, x);
	y -= (a/b)*x;
}

void MOD(int &a, int c) {
	a %= c;
	if (a < 0) a += c;
}
int mul(int a, int b, int c) {
	MOD(a,c); MOD(b,c);
	int ret = 0;
	for (; b; a = 2*a%c, b >>= 1)
		if (b&1) ret = (ret+a)%c;
	return ret;
}

void solve() {
	R(n,m);
	FOR(i,0,n) R(a[i]);
	FOR(i,0,n) R(p[i]);
	multiset<int> s;
	FOR(i,0,n) R(atk[i]);
	FOR(i,0,m) {
		int atk; R(atk);
		s.insert(atk);
	}
	int c1 = 0, d1 = 1;
	mx = 0;
	FOR(i,0,n) {
		multiset<int>::iterator it = s.upper_bound(a[i]);
		if (it != s.begin()) --it;
		b[i] = *it; s.erase(it);
		s.insert(atk[i]);
		mx = max(mx, (a[i]+b[i]-1)/b[i]);
		// Calc
		int x, y, g;
		exgcd(b[i], p[i], x, y); g = _gcd;
		if (a[i] % g != 0) {
			puts("-1");
			return;
		}
		d[i] = p[i]/g;
		c[i] = mul(x, a[i]/g, d[i]);
		// Merge
		exgcd(d1, d[i], x, y); g = _gcd;
		if ((c[i]-c1) % g != 0) {
			puts("-1");
			return;
		}
		int l = d1/g*d[i];
		x = mul(x, (c[i]-c1)/g, d[i]/g);
		c1 = (mul(x, d1, l)+c1)%l;
		d1 = l;
	}
	int k = max<int>((mx-c1+d1-1)/d1, 0);
	W(k*d1+c1);
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int t; R(t);
	while (t--) solve();
}

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
#define print(a,n) FOR(_,0,n) _W(a),printf("%c", " \n"[_==n-1])
using namespace std;

template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
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

int n, k, N;

void invadd(vi &b, const vi &a, int l, int r) { ROF(i,l,r) b.pb(a[i]); }
void add(vi &b, const vi &a, int l, int r) { FOR(i,l,r) b.pb(a[i]); }

vi solve() {
	vi a(N);
	FOR(i,0,N) {
		a[i] = i;
	}
	int step = 1, all = N;
	FOR(_,0,k) {
		vi b;
		FOR(i,0,all/2) {
			invadd(b, a, (all/2-i-1)*step, (all/2-i)*step);
			add(b, a, (all/2+i)*step, (all/2+i+1)*step);
		}
		step *= 2;
		all /= 2;
		a = b;
	}
	return a;
}

signed main() {
#ifndef ONLINE_JUDGE
	FIO("a");
#endif
	int t; R(t); while (t--) {
		R(n,k);
		N = 2*n; FOR(i,0,k) N <<= 1;
		vi a(N), p = solve();
		FOR(i,0,N) R(a[i]);
		print(a[p[_]], N);
	}
}

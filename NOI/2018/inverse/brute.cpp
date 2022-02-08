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
#define print(a,n) cout << #a << " = ";FOR(_,0,n) printf("%d%c", a, " \n"[_==n-1])
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

const int N = 20;

int n, q[N];
int dp[2][N][N];

int calc() {
	int ret = 0;
	FOR(i,1,n+1) {
		ret += abs(i-q[i]);
	}
	return ret/2;
}
int inv() {
	int ret = 0;
	FOR(i,1,n+1) {
		FOR(j,i+1,n+1) {
			ret += q[i] > q[j];
		}
	}
	return ret;
}

void solve() {
	R(n);
	FOR(i,1,n+1) R(q[i]);
	int ans = 0;
	while (next_permutation(q+1, q+n+1)) {
		if (inv() == calc()) ans++;
	}
	printf("%d\n", ans);
}

signed main() {
	freopen("inverse.in", "r", stdin);
	freopen("inverse.ans", "w", stdout);
	int t; R(t); while (t--) solve();
}

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

const int L = 2e4+10, N = 1e3+10, P = 1e9+7;

int n;
char s[L];
int dp[N], pos[N], len[N];
int lcp[3][N];
bool valid[N];

bool ok(int i, int j, int k) {
	if (j == k) {
		if (lcp[1][pos[i]] >= j) {
			return s[pos[i-1]+lcp[1][len[i]+j]] <= s[pos[i]+lcp[1][len[i]+j]];
		} else {
			return s[pos[i-1]+lcp[1][len[i]]] < s[pos[i]+lcp[1][len[i]]];
		}
	} else {
		if (j > k) {
			if (lcp[1][pos[i]] >= k) {
				if (lcp[2][pos[i]+k+1] >= j-k) {
					if (lcp[1][pos[i]]
				} else {
				}
			} else {
				return s[len[i-1]+lcp[1][len[i]]] < s[len[i]+lcp[1][len[i]]];
			}
		}
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	R(n);
	pos[0] = 1;
	FOR(i,0,n) {
		scanf("%s", s+pos[i]);
		len[i] = strlen(s+pos[i]);
		pos[i+1] = pos[i]+len[i]+1;
		FOR(j,0,len[i]) {
			valid[pos[i]+j] = s[pos[i]+j] != s[pos[i]+j-1];
		}
		s[pos[i+1]-1] = '$';
	}
	FOR(k,-1,2) {
		FOR(i,1,n) {
			ROF(j,0,min(len[i], len[i-1])) {
				lcp[k+1][pos[i]+j] = s[pos[i]+j+k] == s[pos[i-1]+j] ? lcp[k+1][pos[i]+j]+1 : 0;
			}
		}
	}
	FOR(i,pos[0], pos[0]+len[0]) dp[i] = valid[i];
	FOR(i,1,n) {
		FOR(j,0,len[i]) if (valid[pos[i]+j]) {
			FOR(k,0,len[i-1]) if (ok(i, j, k)) {
				dp[pos[i]+j] = (dp[pos[i]+j]+dp[pos[i-1]+k])%P;
			}
		}
	}
}

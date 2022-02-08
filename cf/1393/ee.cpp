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

char s[N];
int sa[N], rnk[N], sec[N], tmp[N], h[L][N];
int lg[N];

void tsort(int n, int m) {
	FOR(i,0,m+1) tmp[i] = 0;
	FOR(i,1,n+1) tmp[rnk[i]]++;
	FOR(i,1,m+1) tmp[i] += tmp[i-1];
	ROF(i,1,n+1) sa[tmp[rnk[sec[i]]]--] = sec[i];
}
int Sec(int i) { return i < N ? sec[i] : 0; }
bool cmp(int i, int j, int k) {
	return sec[i] == sec[j] && Sec(i+k) == Sec(j+k);
}
void SA(int n) {
	FOR(i,1,n+1) {
		rnk[i] = s[i];
		sec[i] = i;
	}
	tsort(n, 256);
	swap(rnk, sec);
	int p = 1; rnk[sa[1]] = 1;
	FOR(i,2,n+1) {
		rnk[sa[i]] = cmp(sa[i-1], sa[i], 0) ? p : ++p;
	}
	for (int k = 1; p < n; k <<= 1) {
		FOR(i,1,k+1) sec[i] = n+1-i;
		p = k; FOR(i,1,n+1) if (sa[i] > k) sec[++p] = sa[i]-k;
		tsort(n, n);
		swap(rnk, sec);
		p = 1; rnk[sa[1]] = 1;
		FOR(i,2,n+1) {
			rnk[sa[i]] = cmp(sa[i-1], sa[i], k) ? p : ++p;
		}
	}
	// Height
	for (int i = 1, j = 0; i <= n; ++i) {
		if (rnk[i] == 1) {
			h[0][rnk[i]] = 0;
			j = 0;
			continue;
		}
		if (j) --j;
		while (s[i+j] == s[sa[rnk[i]-1]+j]) {
			++j;
		}
		h[0][i] = j;
	}
}

void ST(int n) {
	lg[0] = -1;
	FOR(i,1,L) {
		lg[i] = lg[i>>1]+1;
	}
	FOR(i,1,L) {
		FOR(j,1,n+2-(1<<i)) {
			h[i][j] = min(h[i-1][j], h[i-1][j+(1<<(i-1))]);
		}
	}
}
int query(int l, int r) {
	int k = lg[r-l+1];
	return h[k][l]+h[k][r-(1<<k)+1];
}

vector<int> 

void solve(int n) {
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
}

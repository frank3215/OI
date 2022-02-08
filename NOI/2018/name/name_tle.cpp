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
//#define int long long

const int N = 2e6, Q = 1e5+10, L = 22, inf = 1e9;

int T;
char s[N];
int b[N], sa[N], rnk[N], sec[N], tmp[N], h[L][N];
int pos[Q], l[Q], r[Q];
ll ans[Q];
int lg[N], pre[Q], previ[N];

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
		h[0][rnk[i]] = j;
	}
}

void ST(int n) {
	lg[0] = -1;
	FOR(i,1,N) {
		lg[i] = lg[i>>1]+1;
	}
	FOR(i,1,L) {
		FOR(j,1,n+2-(1<<i)) {
			h[i][j] = min(h[i-1][j], h[i-1][j+(1<<(i-1))]);
		}
	}
}
int query(int l, int r) {
	if (l < 1 || l >= pos[T+1] || r < 1 || r >= pos[T+1]) return 0;
	int k = lg[r-l+1];
	return min(h[k][l], h[k][r-(1<<k)+1]);
}

const int TR = N*L;
int rt[N], cnt[TR], ch[TR][2], tot;
int copy_node(int u) {
	++tot;
	cnt[tot] = cnt[u];
	memcpy(ch[tot], ch[u], sizeof(ch[tot]));
	return tot;
}
void insert(int &u, int l, int r, int v) {
	u = copy_node(u);
	++cnt[u];
	if (l == r) return;
	int mid = (l+r)>>1;
	if (v <= mid) insert(ch[u][0], l, mid, v);
	else insert(ch[u][1], mid+1, r, v);
}
int query(int u, int v, int l, int r, int ql, int qr) { // min{i>=w}
	if (ql <= l && r <= qr) {
		return abs(cnt[u]-cnt[v]);
	}
	int mid = (l+r)>>1, ret = 0;
	if (ql <= mid) ret += query(ch[u][0], ch[v][0], l, mid, ql, qr);
	if (mid < qr) ret += query(ch[u][1], ch[v][1], mid+1, r, ql, qr);
	return ret;
}
void init() {
	FOR(i,1,pos[T+1]) {
		insert(rt[i] = rt[i-1], 1, pos[T+1], sa[i]);
//		debug(i, sa[i], rt[i], cnt[rt[i]]);
	}
}

bool check(int rk, int lcp, int ql, int qr) {
	if (ql > qr) return false;
	int l = rk, r = rk;
	ROF(i,0,L)
		if (query(l-(1<<i)+1, l) >= lcp)
			l -= (1<<i);
	ROF(i,0,L)
		if (query(r+1, r+(1<<i)) >= lcp)
			r += (1<<i);
//	debug(rk, lcp, l, r, ql, qr);
	return query(rt[r], rt[l-1], 1, pos[T+1], ql, qr);
}

void solve(int n) {
	memset(pre, -1, sizeof(pre));
	FOR(i,1,n+1) {
		if (b[sa[i]] != -1) {
			previ[i] = pre[b[sa[i]]];
			pre[b[sa[i]]] = i;
		}
	}
	FOR(i,1,T+1) {
		int lcp = 0;
		FOR(j,pos[i], pos[i+1]-1) {
			if (lcp) --lcp;
			int len = pos[i+1]-1-j;
			while (check(rnk[j], lcp+1, l[i], r[i]-lcp)) ++lcp;
//			debug(i, j, lcp);
			ans[i] += max(0,len-max(lcp,query(previ[rnk[j]]+1, rnk[j])));
		}
	}
}

#define printt(a,n) printf("% 10s", #a);FOR(_,0,n) printf("% 3d", a); putchar('\n')
#define printtc(a,n) printf("% 10s", #a);FOR(_,0,n) printf("  %c", a); putchar('\n')

signed main() {
//#ifndef ONLINE_JUDGE
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
//#endif
	memset(b, -1, sizeof(b));
	pos[0] = 1;
	scanf("%s", s+pos[0]);
	pos[1] = strlen(s+pos[0])+pos[0]+1;
	R(T);
	FOR(i,1,T+1) {
		scanf("%s", s+pos[i]);
		R(l[i], r[i]);
		pos[i+1] = strlen(s+pos[i])+pos[i]+1;
	}
	FOR(i,0,T+1) {
		s[pos[i+1]-1] = '$';
		FOR(j,pos[i],pos[i+1]-1) {
			b[j] = i;
		}
	}
	SA(pos[T+1]-1);
	ST(pos[T+1]-1);
//	printtc(s[_], pos[T+1]);
//	printt(_, pos[T+1]);
//	printt(sa[_], pos[T+1]);
//	printt(h[0][_], pos[T+1]);
	init();
	solve(pos[T+1]-1);
	FOR(i,1,T+1) {
		W(ans[i]);
	}
}

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

const int N = 1e6+100;

int ch[N<<1][26], len[N<<1], link[N<<1], pos[N<<1], tot, last;
char s[N];
int cnt[N<<1];
vector<int> son[N<<1];
ll ans;

void init() {
	mset(ch,-1); mset(len,-1); mset(link,-1); mset(pos, -1);
	clr(cnt);
	tot = last = 0;
	len[0] = 0;
}

void extend(int c) {
	int cur = ++tot; cnt[cur]++;
	int u = last; len[cur] = len[last]+1; pos[cur] = pos[last]+1;
	while (u != -1 && ch[u][c] == -1) {
		ch[u][c] = cur;
		u = link[u];
	}
	if (u == -1) {
		link[cur] = 0;
	} else {
		int v = ch[u][c]; pos[v] = pos[cur];
		if (len[v] == len[u]+1) {
			link[cur] = v;
		} else {
			int w = ++tot; len[w] = len[u]+1;
			memcpy(ch[w],ch[v],sizeof(ch[v]));
			while (u != -1 && ch[u][c] == v) {
				ch[u][c] = w;
				u = link[u];
			}
			link[w] = link[v];
			link[v] = link[cur] = w;
		}
	}
	last = cur;
}

void dfs(int u) {
	for (auto v: son[u]) {
		dfs(v);
		cnt[u] += cnt[v];
	}
//		debug(u, pos[u], len[u], cnt[u]);
	if (u && cnt[u] > 1) {
		ans = max(ans, (ll)cnt[u]*len[u]);
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	scanf("%s", s);
	int n = strlen(s);
	init();
	FOR(i,0,n) extend(s[i]-'a');
//	debug(ch[ch[ch[0][0]][1]][1])
//	FOR(i,0,tot+1) {
//		debug(i, len[i], link[i], cnt[i]);
//		FOR(j,0,26) if (ch[i][j] != -1) debug(i, j, ch[i][j]);
//	}
	FOR(i,1,tot+1) {
		son[link[i]].pb(i);
	}
	dfs(0);
	W(ans);
}

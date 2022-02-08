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

const int N = 2e5+10, D = 9;

int n, m, k;
vector<pii> adj[N];
int cnt[N][D][D];
bool no[D][D][D][D], noo[D][D];
int p[D];
int ans;

void dfs(int dep) {
	if (dep == k) {
//		FOR(i,0,k+1) {
//			printf("%d%c", p[i], " \n"[i==k]);
//		}
//		FOR(i,1,n+1) {
//			printf("%d->%d\n", i, adj[i][p[(int)adj[i].size()-1]].se);
//		}
//		putchar('\n');
		ans++;
		return;
	}
	FOR(i,0,dep+1) if (!noo[dep][i]) {
		p[dep] = i;
		bool flag = false;
		FOR(j,0,dep) {
//			debug(dep, p[i], j, p[j]);
			flag |= no[dep][p[dep]][j][p[j]];
		}
		if (!flag) dfs(dep+1);
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	R(n, m, k);
	FOR(i,0,m) {
		int u, v, w;
		R(u,v,w);
		adj[u].pb(mp(w,v));
	}
	FOR(i,1,n+1) {
		sort(all(adj[i]));
		FOR(k,0,adj[i].size()) {
			int j = adj[i][k].se;
//			debug(j, (int)adj[i].size()-1);
			cnt[j][(int)adj[i].size()-1][k]++;
		}
	}
	FOR(i,1,n+1) {
		FOR(j,0,D) {
			FOR(b1,0,j+1) if (cnt[i][j][b1]) {
				if (cnt[i][j][b1] > 1) {
					noo[j][b1] = 1;
					continue;
				}
				FOR(k,0,j) {
					FOR(b2,0,k+1) if (cnt[i][k][b2] == 1) {
//						debug(j, b1, k, b2);
						no[j][b1][k][b2] = 1;
					}
				}
			}
		}
	}
	dfs(0);
	W(ans);
}

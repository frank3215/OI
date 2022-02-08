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

const int N = 210, M = 5010;

struct Graph{ 
	int n, m, s, t;
	struct Node{
		int dis, head, cur;
	}ver[N];
	struct Edge{
		int v, w, nxt;
	}edge[M<<1];
	int tot;
	Graph(): tot(1) {}
	void _add(int u, int v, int w) {
		edge[++tot] = (Edge){v,w,ver[u].head};
		ver[u].head = tot;
	}
	void add(int u, int v, int w) { _add(u, v, w); _add(v, u, 0); }
	bool bfs() {
		FOR(i,1,n+1) {
			ver[i].dis = -1;
			ver[i].cur = ver[i].head;
		}
		ver[s].dis = 0;
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int e = ver[u].head; e; e = edge[e].nxt) {
				int v = edge[e].v, w = edge[e].w;
				if (w && ver[v].dis == -1) {
					ver[v].dis = ver[u].dis+1;
					q.push(v);
				}
			}
		}
//		debug(ver[t].dis);
		return ver[t].dis != -1;
	}
	int dfs(int u, int fl) {
//		debug(u, fl);
		if (u == t) return fl;
		int ret = 0;
		for (int &e = ver[u].cur; e; e = edge[e].nxt) {
			int v = edge[e].v, w = edge[e].w;
			if (w && ver[v].dis == ver[u].dis+1) {
				int tmp = dfs(v, min(w, fl));
				edge[e].w -= tmp;
				edge[e^1].w += tmp;
				fl -= tmp;
				ret += tmp;
			}
			if (!fl) break;
		}
		return ret;
	}
	ll flow() {
		ll ret = 0;
		while (bfs()) ret += dfs(s, INT_MAX);
		return ret;
	}
	void solve() {
		R(n, m, s, t);
		FOR(i,0,m) {
			int u, v, w;
			R(u, v, w);
			add(u, v, w);
		}
		printf("%lld\n", flow());
	}
}g;

signed main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	g.solve();
}

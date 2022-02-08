#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sd(x) scanf("%d", &x)
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
#define debug(x) cout << #x << " = " << x << endl
#define FIO(x) \
	freopen(x ".in", "r", stdin); \
	freopen(x ".out", "w", stdout);
#define print(a,n) cout << #a << " = ";_print(a,n);
void _print(int *a, int n) { FOR(i,0,n) printf("%d%c", a[i], " \n"[i==n-1]); }
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

const int MAXN = 7e4+10, MAXM = 1.5e5+10;

int n, m, X[MAXN], Y[MAXN], P[MAXM], T[MAXM], L[MAXM], R[MAXM], D[MAXM], U[MAXM];
int dis[MAXN];
vector<int> E[MAXN];
priority_queue<pii> pq;

set<pii> t[MAXN*4];
void insert(int o, int l, int r, int p) {
	t[o].insert(mp(X[p],p));
	if (l == r) return;
	int mid = (l+r)>>1;
	if (Y[p] <= mid) insert(o<<1, l, mid, p);
	else insert(o<<1|1, mid+1, r, p);
}
void erase(int o, int l, int r, int p) {
	t[o].erase(mp(X[p],p));
	if (l == r) return;
	int mid = (l+r)>>1;
	if (Y[p] <= mid) erase(o<<1, l, mid, p);
	else erase(o<<1|1, mid+1, r, p);
}
void expend(int u) {
	for (auto e: E[u]) {
		pq.push(mp(-(dis[u]+T[e]),e));
	}
}
void expend(int o, int l, int r, int e, int d) {
	if (D[e] <= l && r <= U[e]) {
		vector<int> v;
		for (auto it = t[o].lower_bound(mp(L[e],0)); it != t[o].end() && it->fi <= R[e]; ++it) {
			dis[it->se] = d;
			expend(it->se);
			v.pb(it->se);
		}
		FOR(i,0,(int)v.size()) erase(1,1,n,v[i]);
		return;
	}
	int mid = (l+r)>>1;
	if (D[e] <= mid) expend(o<<1, l, mid, e, d);
	if (U[e] > mid) expend(o<<1|1, mid+1, r, e, d);
}

signed main() {
#ifndef ONLINE_JUDGE
	FIO("jump");
#endif
	scanf("%d%d%*d%*d", &n, &m);
	FOR(i,1,n+1) {
		scanf("%d%d", X+i, Y+i);
	}
	FOR(i,1,m+1) {
		scanf("%d%d%d%d%d%d", P+i, T+i, L+i, R+i, D+i, U+i);
		E[P[i]].pb(i);
	}
	FOR(i,2,n+1) insert(1, 1, n, i);
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	expend(1);
	while (!pq.empty()) {
		int e = pq.top().se, d = -pq.top().fi; pq.pop();
		expend(1, 1, n, e, d);
	}
	FOR(i,2,n+1) printf("%d\n", dis[i]);
}

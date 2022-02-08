#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define E emplace
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
#define debug(x) cout << #x << " = " << x << endl
#define FIO(x) \
	freopen(x ".in", "r", stdin); \
	freopen(x ".out", "w", stdout);
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
typedef priority_queue<pii> pq;

const int MAXN = 2e5+10;

int n, k, l, a[MAXN], b[MAXN];

bool va[MAXN], vb[MAXN];
ll ans;
int np;

pq A, Al, B, Bl, AB, E;

void upd(int ia, int ib) {
	ans += a[ia] + b[ib];
	if (ia != ib) np--;
	if (va[ib]) np++;
	else Al.E(a[ib],ib);
	if (vb[ia]) np++;
	else Bl.E(b[ia],ia);
	va[ia] = vb[ib] = 1;
}

void upd(pq &q, bool *U, bool *V, int &x) {
	while (!q.empty() && (U[q.top().se] || V[q.top().se])) q.pop();
	x = q.empty()?0:q.top().se;
}

void solve() {
	scanf("%d%d%d", &n, &k, &l);
	FOR(i,1,n+1) scanf("%d", a+i);
	FOR(i,1,n+1) scanf("%d", b+i);
	A = B = Al = Bl = AB = E;
	FOR(i,1,n+1) {
		A.E(a[i],i), B.E(b[i],i), AB.E(a[i]+b[i],i);
		va[i] = vb[i] = 0;
	}
	ans = 0;
	np = k-l;
	FOR(i,0,k) {
		int u, v, x, y, z;
		upd(A,va,va,u), upd(B,vb,vb,v), upd(Al,va,va,x), upd(Bl,vb,vb,y), upd(AB,va,vb,z);
		if (np) {
			upd(u, v);
		} else {
			int la = a[x]+b[v], lb = a[u]+b[y], ab = a[z]+b[z];
			la>=max(lb,ab) ? upd(x,v) : lb >= ab ? upd(u,y) : upd(z,z);
		}
	}
	printf("%lld\n", ans);
}

signed main() {
#ifndef ONLINE_JUDGE
	FIO("sequence");
#endif
	int t;
	scanf("%d", &t);
	while (t--) solve();
}

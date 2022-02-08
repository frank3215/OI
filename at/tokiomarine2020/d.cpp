#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b-1); i >= a; --i)
#define REP(i,a,b) for (int i = a; i <= b; ++i)
#define PER(i,a,b) for (int i = b; i >= a; --i)
#define F0R(i,b) FOR(i,0,b)
#define R0F(i,b) ROF(i,0,b)
#define R1P(i,b) REP(i,1,b)
#define P1R(i,b) PER(i,1,b)
using namespace std;

const int N = 1<<20;

int n, Q, V[N], w[N], ans[N];
vector<pair<int,int> > q[N], v[2];

void dfs(int u, int dep = 0) {
	sort(q[u].begin(), q[u].end());
	vector<pair<int,int> > old = v[dep>=9];
	FOR(i,0,(int)old.size()) {
		v[dep>=9].pb(mp(old[i].fi+w[u], old[i].se+V[u]));
	}
	sort(v[dep>=9].begin(), v[dep>=9].end());
//	printf("%d\n", u);
//	FOR(k,0,2) {
//		printf(" %d:\n", k);
//		FOR(i,0,(int)v[k].size()) cout << '\t' << v[k][i].fi << ' ' << v[k][i].se << endl;
//		cout << endl;
//	}
	FOR(k,0,(int)q[u].size()) {
		int pt = 0, mx = 0;
		ROF(i,0,(int)v[0].size()) {
			if (v[0][i].fi > q[u][k].fi) continue;
			while (pt+1 < (int)v[1].size() && v[1][pt+1].fi+v[0][i].fi <= q[u][k].fi) ++pt, mx = max(mx, v[1][pt].se);
			ans[q[u][k].se] = max(ans[q[u][k].se], mx+v[0][i].se);
		}
	}
	FOR(i,0,2) if (2*u+i <= n) dfs(2*u+i, dep+1);
	v[dep>=9] = old;
}

signed main() {
	cin >> n;
	FOR(i,1,n+1) cin >> V[i] >> w[i];
	int Q;
	cin >> Q;
	FOR(i,0,Q) {
		int u, l;
		cin >> u >> l;
		q[u].pb(mp(l, i));
	}
	FOR(i,0,2) v[i].pb(mp(0,0));
	dfs(1);
	FOR(i,0,Q) cout << ans[i] << endl;
}

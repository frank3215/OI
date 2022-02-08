#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

typedef long long ll;

namespace {
	const int N = 5e5+10, M = 200+10, P = 12;
	const ll inf = 1e18;

	int m, t, n[M], s[M], sn[M];
	vector<int> w[M], c[M];
	pair<int,int> id[N];
	int p, op[P], x1[P], x2[P], y1[P], y2[P], cc[P];

	void brute() {
		ll ans = inf;
		FOR(i,0,1<<sn[m]) {
			ll cost = 0, sum = 0;
			bool ok = true;
			FOR(j,0,sn[m]) if (i>>j&1) {
				cost += c[id[j].fi][id[j].se];
				sum += w[id[j].fi][id[j].se];
			}
			FOR(j,1,m+1) {
				int sum = 0;
				FOR(k,sn[j-1],sn[j]) {
					if (i>>k&1) sum += w[j][k-sn[j-1]];
				}
				if (sum < s[j]) ok = false;
			}
			FOR(j,0,p) {
				if ((i>>(sn[x1[j]-1]+y1[j]-1)&1) && (i>>(sn[x2[j]-1]+y2[j]-1)&1)) {
					if (op[j] == 1) {
						cost -= cc[j];
					} else if (op[j] == 2) {
						cost += cc[j];
					} else {
						ok = false;
					}
				}
			}
			if (ok && sum >= t) {
				ans = min(ans, cost);
			}
		}
		if (ans == inf) puts("-1");
		else printf("%lld\n", ans);
	}

	void brute2() {
		vector<ll> f(41, inf);
		f[0] = 0;
		int sum = 0;
		FOR(i,1,m+1) {
			vector<ll> dp(n[i]*3+1, inf);
			dp[0] = 0;
			FOR(j,0,n[i]) {
				ROF(k,w[i][j],n[i]*3+1) {
					dp[k] = min(dp[k], dp[k-w[i][j]]+c[i][j]);
				}
			}
			vector<ll> g(41, inf);
			ROF(k,0,41) {
				FOR(j,s[i],n[i]*3+1) if (k+j-s[i] <= 40) {
					g[k+j-s[i]] = min(g[k+j-s[i]], f[k]+dp[j]);
				}
			}
			f = g;
			sum += s[i];
		}
		ll ans = inf;
		FOR(i,t-sum,41) {
			ans = min(ans, f[i]);
		}
		if (ans == inf) puts("-1");
		else printf("%lld\n", ans);
	}

	void solve() {
		scanf("%d%d", &m, &t);
		FOR(i,1,m+1) {
			scanf("%d%d", &n[i], &s[i]);
			sn[i] = sn[i-1]+n[i];
			w[i] = c[i] = vector<int>(n[i]);
			FOR(j,0,n[i]) {
				id[sn[i-1]+j] = mp(i,j);
				scanf("%d%d", &w[i][j], &c[i][j]);
			}
		}
		scanf("%d", &p);
		FOR(i,0,p) {
			scanf("%d%d%d%d%d", op+i, x1+i, y1+i, x2+i, y2+i);
			if (op[i] != 3) scanf("%d", cc+i);
		}
		if (sn[m] <= 15) brute();
		else brute2();
	}
}

signed main() {
#ifndef STDIO
	freopen("courses.in", "r", stdin);
	freopen("courses.out", "w", stdout);
#endif
	solve();
}

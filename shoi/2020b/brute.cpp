#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,b,a) for (int i = (b-1); i >= a; --i)
using namespace std;

typedef long long ll;

const int N = 2510;

int n, m, s;
ll sum;

int fa[N], f[N];
int find(int u) { return fa[u]==u?u:fa[u]=find(fa[u]); }

int deg[N], pre[N];
vector<pair<int,int> > E[N], F[N];

signed main() {
#ifndef ONLINE_JUDGE
	freopen("lilac.in", "r", stdin);
	freopen("lilac.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &s);
	FOR(i,1,n+1) fa[i] = i;
	FOR(i,0,m) {
		int u, v;
		scanf("%d%d", &u, &v);
		deg[u]++, deg[v]++;
		if (find(u) != find(v)) fa[find(u)] = find(v);
		sum += abs(u-v);
	}
	FOR(i,1,n+1) if (deg[i]) {
		FOR(j,1,n+1) if (j != i && pre[j]) {
			E[i-pre[j]].pb(mp(i,j));
		}
		pre[find(i)] = i;
	}
	memcpy(f, fa, sizeof(f));
	//printf("sum=%lld\n", sum);
	FOR(i,1,n+1) {
		memcpy(fa, f, sizeof(fa));
		int ans = sum, prev = 0;
		FOR(j,1,n+1) {
			//printf(" j=%d, tot=%d\n", j, (deg[j] + (j==s) + (j==i) + prev));
			if ((deg[j] + (j==s) + (j==i) + prev) % 2 == 1) {
				if (find(j) != find(j+1)) fa[find(j)] = find(j+1);
				ans++;
				prev = 1;
			} else prev = 0;
		}
		//printf("ans=%lld\n", ans);
		FOR(i,1,n) {
			FOR(j,0,(int)F[i].size()) {
				if (find(F[i][j].fi) != find(F[i][j].se)) {
					ans += 2*abs(F[i][j].fi-F[i][j].se);
					fa[find(F[i][j].fi)] = find(F[i][j].se);
				}
			}
		}
		printf("%d ", ans+2);
	}
}


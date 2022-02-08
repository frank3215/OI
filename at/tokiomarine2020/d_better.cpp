#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,b,a) for (int i = (b)-1; i >= a; --i)
using namespace std;

const int N = 1<<19, M = 1<<9;
int n, q;
int v[N], w[N];
pair<int,int> v1[M], v2[M]; int s1, s2;

signed main() {
	scanf("%d", &n);
	FOR(i,1,n+1) {
		scanf("%d%d", v+i, w+i);
	}
	scanf("%d", &q);
	while (q--) {
		int u, l;
		scanf("%d%d", &u, &l);
		v1[0] = mp(0,0); s1 = 1;
		v2[0] = mp(0,0); s2 = 1;
		FOR(i,0,9) {
			if (!u) break;
			FOR(j,0,1<<i) {
				v1[s1++] = mp(v1[j].fi+w[u], v1[j].se+v[u]);
			}
			u >>= 1;
		}
		FOR(i,0,9) {
			if (!u) break;
			FOR(j,0,1<<i) {
				v2[s2++] = mp(v2[j].fi+w[u], v2[j].se+v[u]);
			}
			u >>= 1;
		}
		sort(v1, v1+s1);
		sort(v2, v2+s2);
		int p = -1, mx = 0, ans = 0;
		ROF(i,s2,0) {
			while (p+1 < s1 && v1[p+1].fi + v2[i].fi <= l) mx = max(mx, v1[++p].se);
			if (~p) ans = max(ans, mx+v2[i].se);
		}
		printf("%d\n", ans);
	}
}


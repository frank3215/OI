#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long
using namespace std;

const int maxn = 1e5+10, maxt = 2e3+10, maxm = 2e5+10, inf = 1e18;
typedef pair<int, int> val;
typedef pair<int, val> op;

int n, m, A, B, C;
vector<val> f[maxn];
vector<op> o[maxt];

struct lc{
	int x, y, p, q;
	void scan() {
		scanf("%lld%lld%lld%lld", &x, &y, &p, &q);
	}
	bool operator <(const lc &l) const {
		return p < l.p;
	}
}t[maxm];
int ans = inf;

signed main() {
	scanf("%lld%lld%lld%lld%lld", &n, &m, &A, &B, &C);
	for (int i = 0; i < m; ++i) {
		t[i].scan();
	}
	sort(t, t+m);
	o[0].pb(mp(1, mp(0, 0)));
	for (int i = 0, s = 0; i < maxt; ++i) {
		for (int j = 0; j < (int)o[i].size(); ++j) {
			op &_ = o[i][j];
			val &v = _.se;
#define F f[_.fi]
			while (F.size() >= 2) {
				val l1 = F[F.size()-1], l2 = F[F.size()-2];
				if ((v.se-l1.se)*(l1.fi-l2.fi) <= (v.fi-l1.fi)*(l1.se-l2.se))
					F.pop_back();
				else break;
			}
			F.pb(v);
#undef F
		}
		for (; s < m && t[s].p == i; s++) {
			lc &_ = t[s];
			if (f[_.x].empty()) continue;
			int k = 2*A*_.p, b = A*_.p*_.p + B*_.p + C + _.q;
#define F f[_.x]
			int l = 0, r = (int)F.size()-1;
			while (l < r) {
				int m = (l+r)>>1;
				if ((F[m+1].se-F[m].se) < k*(F[m+1].fi-F[m].fi))
					l = m+1;
				else r = m;
			}
			int tmp = b - k*F[l].fi + F[l].se;
//			if (l+1 < F.size()) tmp = b-k*F[l+1].fi+F[l+1].se;
//			int tmp = inf; for (int l = 0; l < F.size(); ++l) tmp = min(tmp, b - k*F[l].fi + F[l].se);
			if (_.y == n) ans = min(ans, tmp);
			o[_.q].pb(mp(_.y, mp(_.q, tmp+A*_.q*_.q-(B+1)*_.q)));
#undef F
		}
	}
//	for (int i = 1; i <= n; ++i) if (f[i].size()) printf("%d ", i);
	printf("%lld\n", ans);
}

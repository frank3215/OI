#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
using namespace std;

const int MAXN = 310, MAXH = 1e4+10, P = 1e9+7;

int n, a[MAXN], b[MAXN];
set<pair<int,int> > dp;
int tmp = 0;

void solve(int l, int r) {
	if (l > r) return;
	if (dp.count(mp(l,r))) return;
	dp.insert(mp(l,r));
	tmp += (r-l+1)*(r-l+1);
	if (l == r) return;
	if ((r-l+1)%2 == 1) {
		int mmid = (l+r)>>1;
		FOR(mid,mmid-1,mmid+2) {
			solve(l, mid-1);
			solve(mid+1, r);
		}
	} else {
		int mmid = (l+r)>>1;
		FOR(mid,mmid,mmid+2) {
			solve(l, mid-1);
			solve(mid+1, r);
		}
	}
}

signed main() {
	int ans = 0;
	for (n = 1; n <= 300; ++n) {
		tmp = 0;
		dp.clear();
		solve(1, n);
		ans = max(ans, tmp);
	}
	printf("%lld\n", ans);
}

#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
using namespace std;

const int K = 11, P = 1e9+7;

int n, ans;
vector<int> x, y;

int qpow(int a, int x) {
	int ret = 1;
	for (; x; a = 1ll*a*a%P, x >>= 1)
		if (x&1) ret = 1ll*ret*a%P;
	return ret;
}

void dfs(int d, int cur, int phi) {
	//printf("dfs(%d/%d %d %d)\n", d, (int)x.size(), cur, phi);
	if (d == (int)x.size()) {
		ans = (ans+1ll*qpow(n,n/cur)*phi)%P;
		return;
	}
	FOR(i,0,y[d]+1) {
		dfs(d+1, cur, phi);
		cur *= x[d];
		if (!i) phi *= x[d]-1;
		else phi *= x[d];
	}
}

void solve() {
	scanf("%d", &n);
	int m = n;
	x.clear(), y.clear();
	for (int i = 2; i*i <= m; ++i) {
		if (m%i == 0) {
			x.pb(i);
			y.pb(0);
			while (m%i == 0) {
				y.back()++;
				m /= i;
			}
		}
	}
	if (m > 1) {
		x.pb(m);
		y.pb(1);
	}
	ans = 0;
	dfs(0, 1, 1);
	printf("%lld\n", 1ll*ans*qpow(n,P-2)%P);
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--) solve();
}


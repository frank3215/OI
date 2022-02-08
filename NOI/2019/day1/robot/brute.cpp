#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
using namespace std;

const int MAXN = 310, MAXH = 1e4+10, P = 1e9+7, MAXS = 2300;

int n, a[MAXN], b[MAXN];
int id[MAXN][MAXN], dp[MAXS][MAXH], tot;

void solve(int l, int r) {
	if (l > r) return;
	if (id[l][r]) return;
	int cur = id[l][r] = ++tot;
	if (l == r) {
		FOR(i,a[l],b[l]+1) dp[cur][i] = 1;
	} else {
		int mmid = (l+r)>>1;
		FOR(mid,mmid-(r-l+1)%2,mmid+2) {
			solve(l,mid-1);
			solve(mid+1, r);
			FOR(i, a[mid], b[mid]+1) {
				dp[cur][i] = (dp[cur][i] + dp[id[l][mid-1]][i]*dp[id[mid+1][r]][i-1]) %P;
			}
		}
	}
	FOR(i,1,MAXH) {
		dp[cur][i] = (dp[cur][i]+dp[cur][i-1])%P;
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("robot.in", "r", stdin);
	freopen("robot.out", "w", stdout);
#endif
	scanf("%lld", &n);
	FOR(i,1,n+1) scanf("%lld%lld", a+i, b+i);
	FOR(i,0,MAXH) dp[0][i] = 1;
	solve(1, n);
	printf("%lld\n", dp[id[1][n]][MAXH-1]);
}

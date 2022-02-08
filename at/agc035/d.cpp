#include <bits/stdc++.h>
using namespace std;

const int N = 18, M = 1<<N;
typedef long long ll;
const ll inf = 1e18;

int n, a[20];
ll dp[N+1][N+1][M];

ll solve(int l, int r, ll xl, ll xr, int mask) {
	if (l > r) return 0;
	if (dp[l][r][mask] != -1) return dp[l][r][mask];
	ll mn = inf, tmp;
	for (int i = l; i <= r; ++i) {
		mn = min(mn, solve(l, i-1, xl, xr+xl, mask<<1)+solve(i+1, r, xl+xr, xr, mask<<1|1)+(xl+xr)*a[i]);
	}
	return dp[l][r][mask] = mn;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(2, n-1, 1, 1, 1)+a[1]+a[n] << endl;
}

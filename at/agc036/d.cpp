#include <bits/stdc++.h>
using namespace std;

const int maxn = 500;

int n, a[maxn][maxn];
long long from[maxn][maxn], to[maxn][maxn], dp[2][maxn][maxn], ans;

void cmin(long long &x, long long y) { x = min(x, y); }

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) if (j != i) {
			scanf("%d", &a[i][j]);
			from[i][j] = (j?from[i][j-1]:0) + a[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			to[i][j] = (j?to[i][j-1]:0) + a[j][i];
		}
	}
	memset(dp[0], 0x3f, sizeof(dp[0]));
	ans = dp[0][0][0];
	dp[0][0][0] = 0;
	for (int i = 0; i < n-1; ++i) {
		memset(dp[i&1^1], 0x3f, sizeof(dp[0]));
		for (int j = 0; j <= i; ++j) {
			for (int k = 0; k <= j; ++k) {
				cmin(dp[i&1^1][j][k], dp[i&1][j][k]+(to[i+1][i]-(j?to[i+1][j-1]:0))+(k?from[i+1][k-1]:0));
				cmin(dp[i&1^1][i+1][j], dp[i&1][j][k]+(j?from[i+1][j-1]:0));
			}
		}
	}
	for (int j = 0; j < n; ++j)
		for (int k = 0; k <= j; ++k)
			cmin(ans, dp[n&1^1][j][k]);
	cout << ans << endl;
}

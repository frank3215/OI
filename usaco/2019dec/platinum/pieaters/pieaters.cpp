#include <bits/stdc++.h>
using namespace std;

const int maxn = 310;

int n, m;
int c[maxn][maxn], f[maxn][maxn][2], g[maxn][maxn][maxn];

int dp(int l, int r, int k) {
	if (l > r) return 0;
	if (~f[l][r][k]) return f[l][r][k];
	if (k == 0) {
		for (int i = l; i <= r; ++i) {
			f[l][r][k] = max(f[l][r][k], dp(l,i-1,0)+dp(i+1,r,0)+g[l][r][i]);
//			printf("%d %d %d: %d  %d\n", l, r, i, g[l][r][i], f[l][r][k]);
		}
	}
	else {
		for (int i = l; i <= r; ++i)
			f[l][r][k] = max(f[l][r][k], dp(l,i-1,0)+dp(i+1,r,0));
	}
//	printf(" %d %d %d\n", l, r, f[l][r][k]);
	return f[l][r][k];
}

int main() {
	freopen("pieaters.in", "r", stdin);
	freopen("pieaters.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int l, r, w;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &w, &l, &r);
		c[l][r] = max(c[l][r], w);
		for (int j = l; j <= r; ++j)
			g[l][r][j] = max(g[l][r][j], w);
	}
	for (int i = n; i; --i)
		for (int j = i; j <= n; ++j)
			for (int k = i; k <= j; ++k)
				g[i][j][k] = max(g[i][j][k], max(g[i+1][j][k], g[i][j-1][k]));
	memset(f, -1, sizeof(f));
	printf("%d\n", dp(1, n, 0));
}

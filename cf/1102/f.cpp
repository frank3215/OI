#include <bits/stdc++.h>
using namespace std;

const int N = 16, M = 1e4+10, inf = 1e9+10;

int n, m, a[N][M];
int d[N][N], d2[N][N];
int f[1<<N][N][N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	if (n == 1) {
		int ans = inf;
		for (int i = 1; i < m; ++i) {
			ans = min(ans, abs(a[0][i]-a[0][i-1]));
		}
		printf("%d\n", ans);
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) if (j != i) {
			d[i][j] = inf;
			for (int k = 0; k < m; ++k) {
				d[i][j] = min(d[i][j], abs(a[i][k]-a[j][k]));
			}
			d2[i][j] = inf;
			for (int k = 1; k < m; ++k) {
				d2[i][j] = min(d2[i][j], abs(a[i][k-1]-a[j][k]));
			}
			//printf("d[%d][%d] = %d\n", i, j, d2[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		f[1<<i][i][i] = inf;
	}
	for (int i = 0; i < (1<<n); ++i) {
		for (int j = 0; j < n; ++j) if ((i>>j)&1) {
			for (int k = 0; k < n; ++k) if ((i>>k)&1) {
				//if (f[i][j][k]) printf("%d %d %d = %d\n", i, j, k, f[i][j][k]);
				for (int l = 0; l < n; ++l) if (!((i>>l)&1)){
					f[i|(1<<l)][j][l] = max(f[i|(1<<l)][j][l], min(f[i][j][k], d[k][l]));
					//if (f[i|(1<<l)][j][l]) printf(" %d %d %d = %d\n", i|(1<<l), j, l, f[i|(1<<l)][j][l]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			//printf("f[%d][%d][%d] = %d, %d\n", (1<<n)-1, i, j, f[(1<<n)-1][i][j], d2[j][i]);
			ans = max(ans, min(f[(1<<n)-1][i][j], d2[j][i]));
		}
	printf("%d\n", ans);
}

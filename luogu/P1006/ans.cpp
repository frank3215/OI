#include <cstdio>
#include <cassert>
#include <algorithm>
#include <cstring>
const int maxn = 500+10, inf = 1e9, dx[] = {-1, 0};
static int m, n, f[2][maxn][maxn], a[maxn][maxn], y1, y2;
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]);
	memset(f, 0xa0, sizeof(f));
	f[0][1][1] = 0;
	for (register int i = 2; i <= n+m; ++i)
		for (register int x1 = 1; x1 <= m && x1 < i; ++x1) {
			if((y1 = i-x1)>n) continue;
			for (register int x2 = 1; x2 <= m && x2 < i; ++x2) if (x1!=x2) {
				if((y2 = i-x2)>n) continue;
				f[i&1][x1][x2] = -inf;
				for (register int k = 0; k < 4; ++k)
					f[i&1][x1][x2] = std::max(f[i&1][x1][x2], a[x1][y1] + a[x2][y2] + f[(i-1)&1][x1+dx[k/2]][x2+dx[k%2]]);
			}
		}
	printf("%d\n", f[(m+n-1)&1][m][m-1]);
}


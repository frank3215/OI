#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

const int maxp = 500+10, maxq = 1e5+10;

int x[maxp], y[maxp];
char d[maxp];
int a[2][maxq];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		memset(a, 0, sizeof(a));
		int p, q;
		scanf("%d%d", &p, &q);
		for (int j = 0; j < p; ++j) scanf("%d %d %c", x+j, y+j, d+j);

		for (int j = 0; j < p; ++j) {
			if (d[j] == 'N') a[1][y[j]+1]++, a[1][q+1]--;
			if (d[j] == 'E') a[0][x[j]+1]++, a[0][q+1]--;
			if (d[j] == 'W') a[0][0]++, a[0][x[j]]--;
			if (d[j] == 'S') a[1][0]++, a[1][y[j]]--;
		}
		int ans[2][2] = {{0, 0}, {0, 0}};
		for (int k = 0; k < 2; ++k) {
			int cur = 0;
			for (int j = 0; j <= q; ++j) {
				cur += a[k][j];
				if (cur > ans[k][1]) {
					ans[k][1] = cur;
					ans[k][0] = j;
				}
			}
		}
		printf("Case #%d: %d %d\n", i, ans[0][0], ans[1][0]);
	}
}

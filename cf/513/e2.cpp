#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 30000+10, maxk = 200+10;

inline int& cmax(int &x, int y) { return x = max(x, y); }

int n, k;
int a[maxn];
int f[maxn][maxk][2][2][2];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
	}
	memset(f, 0xc0, sizeof(f));
	for (int i = 0; i <= n; ++i)
		f[i][0][0][0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			for (int b1 = (j == 1); b1 < 3; b1 += 2)
				for (int b2 = (j == k); b2 < 3; b2 += 2) {
					f[i][j][1][b1/2][b2/2] = (b2-b1)*a[i] + f[i-1][j][1][b1/2][b2/2];
					for (int b0 = (j <= 2); b0 < 3; b0 += 2) {
//						printf(" %d %d %d %d %d: %d %d\n", i-1, j-1, 0, b0-1, b1-1, f[i-1][j-1][0][b0][b1], (b2-b1)*a[i]);
						cmax(f[i][j][1][b1/2][b2/2], (b2-b1)*a[i]+f[i-1][j-1][0][b0/2][b1/2]);
					}
					f[i][j][0][b1/2][b2/2] = max(f[i][j][1][b1/2][b2/2], f[i-1][j][0][b1/2][b2/2]);
//					printf("%d %d %d %d:", i, j, b1-1, b2-1);
//					printf("%d %d\n", f[i][j][0][b1][b2], f[i][j][1][b1][b2]);
				}
		}
	}
	printf("%d", max(f[n][k][0][0][0], f[n][k][0][1][0]));
}

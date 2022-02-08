#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;

int n, k, ans;
char cf[maxn][maxn];
int g[maxn][maxn], f[maxn], c[maxn], res[maxn][maxn];

inline int rect(int x1, int y1, int x2, int y2) {
	return g[x2][y2]-g[x2][y1-1]-g[x1-1][y2]+g[x1-1][y1-1];
}

void calc_c() {
	for (int j = 1; j <= n; ++j)
		c[j] = c[j-1] + (rect(1, j, n, j) == n);
	for (int i = 1; i <= n-k+1; ++i) {
		for (int j = 1; j <= n; ++j) {
			f[j] = f[j-1] + (rect(1, j, i-1, j)+rect(i+k, j, n, j) == n-k);
		}
		for (int j = 1; j <= n-k+1; ++j) {
			res[i][j] += c[j-1]+(c[n]-c[j+k-1]);
			res[i][j] += f[j+k-1]-f[j-1];
		}
	}
}

void flip(int b[maxn][maxn]) {
	int t;
	for (int i = 1; i <= n; ++i)
		for (int j = i+1; j <= n; ++j) {
			t = b[i][j];
			b[i][j] = b[j][i];
			b[j][i] = t;
		}
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			scanf(" %c", &cf[i][j]);
			g[i][j] = (cf[i][j]=='W')+g[i][j-1]+g[i-1][j]-g[i-1][j-1];
		}
	calc_c();

	flip(g), flip(res);
	calc_c();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (res[i][j] > ans)
				ans = res[i][j];
	cout << ans << endl;
}

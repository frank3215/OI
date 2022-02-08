#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

template<typename T>
void MAX(T &x, T y) { if (y > x) x = y; }
int n, K, L;
int a[maxn], b[maxn];

namespace On4{
	const int MX = 30+10;
	long long f[MX][MX][MX][MX];
	long long ans;
	void solve() {
		scanf("%d%d%d", &n, &K, &L);
		for (int i = 1; i <= n; ++i) scanf("%d", a+i);
		for (int i = 1; i <= n; ++i) scanf("%d", b+i);
		memset(f, 0, sizeof(f));
		ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= i; ++j) {
				for (int k = 0; k <= i; ++k) if (j || k) {
					for (int l = 0; l <= min(j, k); l++) {
						f[i][j][k][l] = f[i-1][j][k][l];
						if (j) MAX(f[i][j][k][l], f[i-1][j-1][k][l]+a[i]);
						if (k) MAX(f[i][j][k][l], f[i-1][j][k-1][l]+b[i]);
						if (j && k) MAX(f[i][j][k][l], f[i-1][j-1][k-1][l]+a[i]+b[i]);
						if (j && k && l) MAX(f[i][j][k][l], f[i-1][j-1][k-1][l-1]+a[i]+b[i]);
//						printf("f[%d][%d][%d][%d] = %lld\n", i, j, k, l, f[i][j][k][l]);
					}
				}
			}
//			printf("f[%d][%d][%d][%d] = %lld\n", i, K, K, L, f[i][K][K][L]);
			MAX(ans, f[i][K][K][L]);
		}
		printf("%lld\n", ans);
	}
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		On4::solve();
	}
}

#include <bits/stdc++.h>
using namespace std;

const int N = 2e3+10, P = 1e9+7, inv2 = (P+1)/2;

int n, empty;
char a[N][N];
int g[N][N], f[N][N];

int qpow(int a, int x) {
	int ret = 1;
	for (; x; a = 1ll*a*a%P, x >>= 1)
		if (x & 1) ret = 1ll*ret*a%P;
	return ret;
}

int main() {
	freopen("sprinklers2.in", "r", stdin);
	freopen("sprinklers2.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", a[i]);
		for (int j = 0; j < n; ++j)
			if (a[i][j] == '.') ++empty;
	}
	f[0][0] = g[0][0] = qpow(2, empty);
//	printf("%d\n", f[0][0]);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j) {	
			if (i+1 < n) (f[i+1][j] += f[i][j]) %= P;
			if (i < n && j < n && a[i][j] == '.')
				(g[i+1][j] += 1ll*f[i][j]*inv2%P) %= P;
			if (j+1 < n) (g[i][j+1] += g[i][j]) %= P;
			if (j < n && i < n && a[i][j] == '.')
				(f[i][j+1] += 1ll*g[i][j]*inv2%P) %= P;
		}
	printf("%d\n", (f[n-1][n]+g[n][n-1])%P);
}

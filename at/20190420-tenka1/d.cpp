//TLE
#include <cstdio>
#include <algorithm>
#include <cassert>
const int maxn = 300+10, P = 998244353;
int n, a[maxn+10], sum, ans, pref[maxn+10];
int f[maxn*maxn/3][maxn*maxn/2];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
		sum += a[i];
		pref[i] = pref[i-1] + a[i];
	}
	f[0][0] = 1;
	for (int k = 1; k <= n; ++k) {
//		printf("%d %d\n", k, a[k]);
		for (int i = sum/3; ~i; --i) {
			for (int j = (sum-i)/2; ~j; --j) {
//				if (f[i][j]) printf("0 %d (%d %d %d):%d\n", k, i, j, pref[k]-i-j, f[i][j]);
				if (i >= a[k]) f[i][j] = (f[i][j] + f[i-a[k]][j])%P;
//				if (f[i][j]) printf("i %d (%d %d %d):%d\n", k, i, j, pref[k]-i-j, f[i][j]);
				if (j >= a[k]) f[i][j] = (f[i][j] + f[i][j-a[k]])%P;
//				if (f[i][j]) printf("%d (%d %d %d):%d\n", k, i, j, pref[k]-i-j, f[i][j]);
			}
		}
	}
	for (int i = 0; i <= sum/3; ++i)
		for (int j = i; j <= (sum-i)/2; ++j) {
			if (i+j>sum-(i+j) && sum-i>i && sum-j>j) {
				if (i == j && j == (sum-i-j)) ans = (ans + f[i][j])%P;
				else if (i == j || j == (sum-i-j)) ans = (ans + 3ll*f[i][j])%P;
				else ans = (ans + 6ll*f[i][j])%P;
			}
		}
	printf("%d\n", ans);
}

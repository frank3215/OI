#include <cstdio>
using namespace std;

const int maxn = 2019, P = 998244353;

int n, k;
int a[maxn];
long long f[maxn][maxn*2], ans;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", a+i);
	f[0][maxn+0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = -(i-1); j <= (i-1); ++j) {
			bool same = a[i]==a[i%n+1];
			f[i][maxn+j] += (same?k:k-2)*f[i-1][maxn+j]%P;
			f[i][maxn+j+1] += (same?0:1)*f[i-1][maxn+j]%P;
			f[i][maxn+j-1] += (same?0:1)*f[i-1][maxn+j]%P;
		}
//		for (int j = -i; j <= i; ++j)
//			printf("f[%d][%d] = %lld\n", i, j, f[i][maxn+j]);
	}
	for (int j = -n; j < 0; ++j)
		ans = (ans+f[n][maxn+j])%P;
	printf("%lld\n", ans);
}

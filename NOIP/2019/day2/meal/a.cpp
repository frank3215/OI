#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 110, maxm = 2010, P = 998244353;

int n, m;
int a[maxn][maxm], b[maxn], f[maxn][maxn<<1];
int ans;

signed main() {
	cin >> n >> m;
	ans = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			b[i] += a[i][j];
		}
		b[i] %= P;
		ans = (ans*(b[i]+1))%P;
	}
	f[0][maxn] = 1;
	for (int k = 1; k <= m; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = maxn-n; j <= maxn+n; ++j) {
				f[i][j] = ((b[i]-a[i][k])*f[i-1][j+1] + a[i][k]*f[i-1][j-1] + f[i-1][j])%P;
			}
		}
		for (int j = maxn+1; j <= maxn+n; ++j)
			ans -= f[n][j];
		ans %= P;
	}
	cout << ((ans-1)%P+P)%P << endl;
}

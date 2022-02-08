#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510;

int n, a[MAXN];
int f[MAXN][MAXN];

int dp(int l, int r) {
	if ((r-l+1) < 3) return 0;
	if (f[l][r] != -1) return f[l][r];
	f[l][r] = 0;
	for (int i = l; i < r; ++i) {
		f[l][r] = max(f[l][r], dp(l,i)+dp(i+1,r));
	}
	if ((r-l+1) % 3 == 0) {
		f[l][r] = max(f[l][r], max(a[l]+a[r-1]+a[r]+dp(l+1, r-2), a[l]+a[l+1]+a[r]+dp(l+2, r-1)));
	}
//	printf("%d %d: %d\n", l, r, f[l][r]);
	return f[l][r];
}

signed main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}
	memset(f, -1, sizeof(f));
	printf("%d\n", dp(1, n));
}

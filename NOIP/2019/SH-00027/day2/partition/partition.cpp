#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000+10;

int n, type, a[maxn];
long long s[maxn], f[maxn][maxn], mn[maxn][maxn];

void brute() {
	memset(f, 0x3f, sizeof(f));
	long long ans = f[0][0];
	f[0][0] = 0;
	for (int l = 0; l < n; ++l) {
		for (int r = l+1; r <= n; ++r) {
			for (int k = 0; k <= l; ++k)
				if (s[k] >= 2*s[l]-s[r])
					f[l][r] = min(f[l][r], (s[l]-s[r])*(s[l]-s[r])+f[k][l]);
			if (r == n) ans = min(ans, f[l][r]);
		}
	}
	printf("%lld\n", ans);
}

void solve() {
	memset(f, 0x3f, sizeof(f));
	memset(mn, 0x3f, sizeof(mn));
	long long ans = f[0][0];
	f[0][0] = 0;
	mn[0][0] = 0;
	for (int r = 1; r <= n; ++r) {
		for (int l = r-1; ~l; --l) {
			int k = lower_bound(s, s+n+1, 2*s[l]-s[r])-s;
			f[l][r] = min(f[l][r], (s[l]-s[r])*(s[l]-s[r])+mn[k][l]);
			if (r == n) ans = min(ans, f[l][r]);
			mn[l][r] = min(mn[l+1][r], f[l][r]);
		}
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);
	scanf("%d%d", &n, &type);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
		s[i] = s[i-1]+a[i];
	}
	if (n <= 400) brute();
	else if (n <= 5000) solve();
}

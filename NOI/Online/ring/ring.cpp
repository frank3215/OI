#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;
typedef long long ll;

int n, m, a[maxn];
ll ans[maxn];

int gcd(int a, int b) { return b?gcd(b,a%b):a; }

ll calc(int *a, int n) {
	ll ret = 0;
	if (n == 1) {
		ret += 1ll*a[1]*a[1];
	} else if (n == 2) {
		ret += 1ll*a[1]*a[2];
	} else {
		for (int i = 1; i <= n-2; ++i) {
			ret += 1ll*a[i]*a[i+2];
		}
		ret += 1ll*a[1]*a[2] + 1ll*a[n]*a[n-1];
	}
	return ret;
}

ll calc(int n, int k) {
	ll ret = 0;
	for (int i = 0; i < n; i += k)
		ret += calc(a+i, k);
	return ret;
}

int main() {
	freopen("ring.in", "r", stdin);
	freopen("ring.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; ++i) {
		if (n%i == 0) ans[i] = calc(n,n/i);
	}
	for (int i = 1; i <= m; ++i) {
		int k;
		scanf("%d", &k);
		int d = gcd(k, n);
		printf("%lld\n", ans[d]);
	}
}

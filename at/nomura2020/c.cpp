#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10, A = 1e18;

int n, a[N], b[N];

signed main() {
	scanf("%lld", &n);
	b[0] = 1;
	for (int i = 0; i <= n; ++i) {
		scanf("%lld", a+i);
		b[i] -= a[i];
		if (b[i] < 0) {
			puts("-1");
			return 0;
		}
		if (i < n) b[i+1] = min(b[i]*2, A);
	}
	int cur = 0, ans = 0;
	for (int i = n; ~i; --i) {
		cur += a[i];
		ans += cur;
		if (i > 0) cur = min(cur, b[i-1]);
	}
	printf("%lld\n", ans);
}

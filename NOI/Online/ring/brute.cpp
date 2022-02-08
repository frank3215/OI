#include <bits/stdc++.h>
using namespace std;

int n, m, k, a[11];
typedef long long ll;

ll calc() {
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			if (min(j-i, n+i-j) == k) {
				ans += 1ll*a[i]*a[j];
			}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &k);
		ll mx = 0;
		sort(a+1, a+n+1);
		do {
			mx = max(mx, calc());
		} while (next_permutation(a+2, a+n+1));
/*
		sort(a+2, a+n+1);
		do {
			if (calc() == mx) {
				for (int i = 1; i <= n; ++i)
					printf("%d%c", a[i], " \n"[i==n]);
			}
		} while (next_permutation(a+2, a+n+1));
*/
		printf("%lld\n", mx);
	}
}

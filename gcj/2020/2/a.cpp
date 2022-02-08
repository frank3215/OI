#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(int n, int l, int r) {
	//printf("solve(%lld, %lld, %lld)\n", n, l, r);
	assert(l >= 0 && r >= 0);
	if (l <= (n+1)*10 && r <= (n+1)*10) {
		while (++n) {
			if (n > l && n > r) break;
			if (l >= r) l -= n;
			else r -= n;
		}
		--n;
		printf("%lld %lld %lld\n", n, l, r);
		return;
	}
	while (l >= r) {
		l -= ++n;
	}
	int lm = 0, rm = 2e9;
	while (lm < rm) {
		int mm = (lm+rm+1)>>1;
		if ((n+mm+1)*mm > l || (n+mm)*mm > r) rm = mm - 1;
		else lm = mm;
	}
	solve(n+lm*2, l-(n+lm+1)*lm, r-(n+lm)*lm);
}

void solve() {
	int L, R, n = 0;
	cin >> L >> R;
	if (L >= R) {
		int l = 0, r = 2e9;
		while (l < r) {
			int m = (l+r+1)>>1;
			if (m*(m+1)/2 <= (L-R)) l = m;
			else r = m-1;
		}
		L -= (l*(l+1)/2);
		n = l;
	} else {
		int l = 0, r = 2e9;
		while (l < r) {
			int m = (l+r+1)>>1;
			if (m*(m+1)/2 <= (R-L)) l = m;
			else r = m-1;
		}
		R -= (l*(l+1)/2);
		n = l;
	}
	solve(n, L, R);
}
signed main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		printf("Case #%lld: ", i);
		solve();
	}
}

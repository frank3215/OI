#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)

signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		long long prev = 0, mx = -1e18, sum = 0;
		F0R(i,n) {
			cin >> a[i];
			sum += a[i];
		}
		F0R(i,n-1) {
			prev += a[i];
			mx = max(mx, prev);
			if (prev < 0) prev = 0;
		}
		prev = 0;
		FOR(i,1,n) {
			prev += a[i];
			mx = max(mx, prev);
			if (prev < 0) prev = 0;
		}
		if (mx < sum) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}

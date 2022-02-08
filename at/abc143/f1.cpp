#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n+1), c(n+1), corr(n+1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[a[i]]++
	}
	for (int i = 1; i <= n; ++i) {
		c[b[i]]++;
	}
	int L = 0, R = 0, m = 0;
	for (int i = 1; i <= n; ++i) R++;
	for (int m = 1; m <= n; ++m) {
		L += c[m]*m;
		R -= c[m];
		corr[m] = L/m+R;
	}
	for (int i = 1, ans = n; i <= n; ++i) {
		while (ans && corr[ans] < i) ans--;
		cout << ans;
	}
}

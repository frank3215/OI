#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	vector<int> a(n+1), b(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[a[i]] = i;
	}
	int l = n, r = 1;
	for (int i = 1; i <= n; ++i) {
		l = min(l, b[i]);
		r = max(r, b[i]);
		printf("%d", ((r-l+1) == i));
	}
	putchar('\n');
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}

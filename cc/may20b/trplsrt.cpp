#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, K = N/2;
int p[N];
int a[K], b[K], c[K];
int x, y;
int ans;

void shift(int a, int b, int c) {
	//printf(" %d %d %d\n", a, b, c);
	::a[++ans] = a, ::b[ans] = b, ::c[ans] = c;
	int x = p[a], y = p[b], z = p[c];
	p[a] = z, p[b] = x, p[c] = y;
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	ans = 0;
	x = y = 0;
	for (int i = 1; ; ) {
		//printf("%d\n", i <= n && p[i] <= i);
		while (i <= n && p[i] <= i) ++i;
		//printf("%d\n", i);
		if (i > n) break;
		if (p[p[i]] == i) {
			if (i > p[i]) continue;
			if (x && y) {
				int z = p[i];
				shift(x, i, y);
				shift(i, y, z);
				x = y = 0;
			} else {
				x = i;
				y = p[i];
				++i;
			}
		} else shift(i, p[i], p[p[i]]);
	}
	if (x && y) {
		cout << -1 << endl;
		return;
	}
	cout << ans << endl;
	for (int i = 1; i <= ans; ++i) {
		printf("%d %d %d\n", a[i], b[i], c[i]);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10, K = N;
int p[N], pre[N];
int a[K], b[K], c[K];
int n, k;
int ans;

void shift(int a, int b, int c) {
	//printf(" %d %d %d\n", a, b, c);
	::a[++ans] = a, ::b[ans] = b, ::c[ans] = c;
	int x = p[a], y = p[b], z = p[c];
	pre[z] = a, pre[x] = b, pre[y] = c;
	p[a] = z, p[b] = x, p[c] = y;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		pre[p[i]] = i;
	}
	ans = 0;
	for (int i = 1; i < n; ) {
		if (i != p[i]) {
			if (i == n-1) {
				cout << -1 << endl;
				return;
			}
			int x = (pre[i]==i+1)?i+2:i+1;
			shift(i, x, pre[i]);
		} else ++i;
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

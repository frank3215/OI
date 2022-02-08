#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	assert(m == 0);
	int p[n+1];
	for (int i = 1; i <= n; ++i) cin >> p[i];
	int vis[n+1] = {};
	int ans = 0;
	for (int i = 1, j, k; i <= n; ++i) {
		if (vis[i]) continue;
		for (k = i, j = 0; !vis[k]; vis[k] = 1, k = p[k]) ++j;
		ans += j-1;
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int l, r, x, y;
	cin >> l >> r >> x >> y;
	int ans = 0;
	for (int i = l; i <= r; ++i) {
		if ((i&x)*(i&y) > (ans&x)*(ans&y)) ans = i;
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}

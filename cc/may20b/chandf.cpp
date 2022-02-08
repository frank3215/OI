#include <bits/stdc++.h>
using namespace std;

#define int long long

int x, y, l, r;
int mx, ans;

void solve(int cur, int L, int R, int dep) {
	if (R < l || r < L) return;
	if (dep == -1) return;
	if (l <= L && R <= r) {
		int Cur = cur | ((1ll<<dep)-1);
		if ((Cur&x)*(Cur&y) > (ans&x)*(ans&y)) {
			for (int i = dep-1; ~i; --i) {
				if (((x|y)>>i)&1) cur |= 1ll<<i;
			}
			ans = cur;
		}
		return;
	}
	solve(cur, L, L+(1ll<<(dep-1))-1, dep-1);
	solve(cur+(1ll<<(dep-1)), L+(1ll<<(dep-1)), R, dep-1);
}
void solve() {
	cin >> x >> y >> l >> r;
	ans = l;
	solve(0, 0, (1ll<<40)-1, 40);
	cout << ans << endl;
}

signed main() {
	int t;
	cin >> t;
	while (t--) solve();
}

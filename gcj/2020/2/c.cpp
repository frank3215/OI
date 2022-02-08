#include <bits/stdc++.h>
#define print //printf
using namespace std;

typedef long long ll;

const int maxn = 110;

int n;
int x[maxn], y[maxn], ans;
int b[maxn];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", x+i, y+i);
	}
	if (n == 1) {
		cout << 1 << endl;
		return;
	}
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) if (j != i) {
			int kx = x[i]-x[j], ky = y[i]-y[j];
			print("k=%d/%d\n", ky, kx);
			map<ll, int> s;
			for (int k = 1; k <= n; ++k) {
				b[k] = (kx*y[k]-ky*x[k]);
				print(" %d(%d,%d) %d\n", k, x[k], y[k], b[k]);
				s[b[k]]++;
			}
			int c1 = 0, c2 = 0, c3 = 0;
			for (auto x: s) {
				print("  %d %d\n", x.first, x.second);
				if (x.second == 1) c1++;
				else if (x.second%2) c3 += x.second;
				else c2 += x.second;
			}
			print("k=%d/%d, %d %d %d\n", ky, kx, c1, c2, c3);
			if (c3%2) ans = max(ans, c3+c2+min(1,c1));
			else ans = max(ans, c3+c2+min(2,c1));
		}
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
}

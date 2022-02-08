#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005, maxk = 21, P = 1e9+7;

int n, k;
int a[maxn], ans[maxn][maxn], f[maxk];
int q, l, r;

int main() {
	freopen("nondec.in", "r", stdin);
	freopen("nondec.ans", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		memset(f, 0, sizeof(f));
		f[0] = 1;
		for (int j = i; j <= n; ++j) {
			for (int l = a[j]; ~l; --l) (f[a[j]] += f[l]) %= P;
			for (int l = 0; l <= k; ++l) (ans[i][j] += f[l]) %= P;
		}
	}
	cin >> q;
	while (q--) {
		cin >> l >> r;
		cout << ans[l][r] << endl;
	}
}

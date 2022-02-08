#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 4e4+10;

int n, m;
int ans[4][M], T[M], x[M];

void brute() {
	for (int a = 1; a <= n; ++a)
		for (int b = a+1; b <= n; ++b)
			for (int c = b+1; c <= n; ++c) if ((b-a)*3 < (c-b))
				for (int d = c+1; d <= n; ++d) if ((b-a) == 2*(d-c)) {
					ans[0][a] += T[b]*T[c]*T[d];
					ans[1][b] += T[a]*T[c]*T[d];
					ans[2][c] += T[a]*T[b]*T[d];
					ans[3][d] += T[a]*T[b]*T[c];
				}
}

namespace solve{
	int pre[M], suf[M];
	void solve() {
		for (int t = 1; t*9 < n; ++t) {
			memset(pre, 0, sizeof(pre));
			memset(suf, 0, sizeof(suf));
			for (int i = 2*t+1; i <= n; ++i)
				pre[i] = pre[i-1]+T[i]*T[i-2*t];
			for (int i = n-t; i; --i)
				suf[i] = suf[i+1]+T[i]*T[i+t];
			for (int x = 1; x < n-8*t; ++x) if (T[x] && T[x+2*t]) {
				ans[0][x] += T[x+2*t]*suf[x+8*t+1];
				ans[1][x+2*t] += T[x]*suf[x+8*t+1];
			}
			for (int x = 8*t; x <= n-t; ++x) if (T[x] && T[x+t]) {
				ans[2][x] += T[x+t]*pre[x-6*t-1];
				ans[3][x+t] += T[x]*pre[x-6*t-1];
//				printf("ans[%d][%d] += T[%d](%d)*pre[%d](%d)\n", 3, x+t, x, T[x], x-6*t-1, pre[x-6*t-1]);
			}
		}
	}
}

signed main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x[i];
		T[x[i]]++;
	}
	solve::solve();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 4; ++j)
			cout << ans[j][x[i]] << ' ';
		cout << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4+10, maxq = 2e5+10, maxk = 21, P = 1e9+7;

int n, k;
int a[maxn], ans[maxq], f[maxn][maxk][maxk], g[maxn][maxk];
int q, ql[maxq], qr[maxq], id[maxq], tmp[maxq];

void solve(int l, int r, int L, int R) {
	if (L > R) return;
	if (l == r) {
		for (int i = L; i <= R; ++i)
			ans[id[i]] = 2;
		return;
	}
	int m = l+r>>1;
	memset(f+l, 0, (r-l+1)*sizeof(f[0]));
	memset(g+l, 0, (r-l+1)*sizeof(g[0]));
	f[m][a[m]][a[m]] = f[m+1][a[m+1]][a[m+1]] = 1;
	for (int i = m+2; i <= r; ++i) {
		for (int j = 1; j <= k; ++j) {
			for (int l = j; l <= k; ++l) {
				f[i][j][l] = f[i-1][j][l];
			}
		}
		for (int j = a[i]; j; --j) {
			for (int l = 1; l <= a[i]; ++l) {
				(f[i][l][a[i]] += f[i-1][l][j]) %= P;
			}
		}
		(f[i][a[i]][a[i]]+=1) %= P;
	}
	for (int i = m-1; i >= l; --i) {
		for (int j = 1; j <= k; ++j) {
			for (int l = j; l <= k; ++l) {
				f[i][j][l] = f[i+1][j][l];
			}
		}
		for (int j = a[i]; j <= k; ++j) {
			for (int l = a[i]; l <= k; ++l) {
				(f[i][a[i]][l] += f[i+1][j][l]) %= P;
			}
		}
		(f[i][a[i]][a[i]]+=1) %= P;
	}
	for (int i = l; i <= m; ++i)
		for (int l = 1; l <= k; ++l) {
			g[i][l] = g[i][l-1];
			for (int j = 1; j <= l; ++j) {
				(g[i][l] += f[i][j][l]) %= P;
			}
		}
	for (int i = m+1; i <= r; ++i)
		for (int j = 1; j <= k; ++j) {
			for (int l = j; l <= k; ++l) {
				(g[i][j] += f[i][j][l]) %= P;
			}
		}
	int QL = L, QR = R;
	for (int i = L; i <= R; ++i) {
		if (ql[id[i]] <= m && qr[id[i]] >= m+1) {
			ans[id[i]] = (1+g[ql[id[i]]][k])%P;
			for (int j = 1; j <= k; ++j) {
				ans[id[i]] = (ans[id[i]]+1ll*(g[ql[id[i]]][j]+1)*g[qr[id[i]]][j])%P;
			}
		} else if (qr[id[i]] <= m) {
			tmp[QL++] = id[i];
		} else if (ql[id[i]] >= m+1) {
			tmp[QR--] = id[i];
		}
	}
	for (int i = L; i <= R; ++i) {
		id[i] = tmp[i];
	}
	solve(l, m, L, QL-1);
	solve(m+1, r, QR+1, R);
}

int main() {
	freopen("nondec.in", "r", stdin);
	freopen("nondec.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> ql[i] >> qr[i];
		id[i] = i;
	}
	solve(1, n, 1, q);
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << endl;
	}
}

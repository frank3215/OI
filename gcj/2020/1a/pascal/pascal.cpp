#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxs = 310;

int n;
int vis[maxs];
int v[maxs][maxs], pas[maxs][maxs];

int N, R, K, cnt;
void walk(int r, int k) {
	cout << r << ' ' << k << endl;
//	assert(++cnt <= 500);
//	assert(r >= 1 && r < maxs && k >= 1 && k <= r);
//	assert(!v[r][k]);
//	if (r == R) assert(k == K-1 || k == K+1);
//	else if (r == R-1) assert(k == K || k == K-1);
//	else if (r == R+1) assert(k == K || k == K+1);
//	else assert(0);
//	v[r][k] = 1;
//	R = r, K = k;
//	printf("%lld-%lld", N, pas[r][k]);
//	N -= pas[r][k];
//	printf("=%lld\n", N);
//	assert(N >= 0);
}

void solve() {
//clear
	memset(v, 0, sizeof(v));
	K = R = 0;
//clear done
	cin >> n; N = n;
	int i;
	for (i = 1; i+(1ll<<i) <= n; ++i);
	n -= i;
	memset(vis, 0, sizeof(vis));
	for (int j = i; j > 1; --j)
		if ((1ll<<(j-1))-1 <= n) {
			vis[j] = 1;
			n -= (1ll<<(j-1))-1;
		}
	int r = 1, k = 1;
	walk(r, k);
	for (int j = 2; j <= i; ++j) {
		if (k == r) ++k; ++r;
		walk(r, k);
		if (vis[j]) {
			if (k == 1) {
				for (int l = 2; l <= r; ++l) walk(r, l);
				k = r;
			} else if (k == r) {
				for (int l = r-1; l; --l) walk(r, l);
				k = 1;
			} else assert(0);
		}
	}
//	assert(n == N);
	while (n) {
		if (k == r) ++k; ++r;
		walk(r, k);
		n--;
	}
}
signed main() {
	int t;
	cin >> t;
//	for (int i = 1; i < maxs; ++i) {
//		pas[i][1] = pas[i][i] = 1;
//		for (int j = 2; j < i; ++j) {
//			pas[i][j] = pas[i-1][j]+pas[i-1][j];
//		}
//	}
	for (signed i = 1; i <= t; ++i) {
		printf("Case #%d:\n", i);
		solve();
	}
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 310;

int n, b[N][N], sum[2][N<<1][N];
char s[N][N];
ll ans1, ans2;

ll pref(bool b, int k, int i) {
	if (k < 0 || k > 2*n || i < 0) return 0;
	if (i > n) return sum[b][k][n];
	return sum[b][k][i];
}
ll range(bool b, int k, int i, int j) {
	if (b) k += n;
	return -pref(b, k, i-1) + pref(b, k, j);
}
int check(int x, int y) {
//	printf("CHECK: %d %d\n", x, y);
	if (x < 1 || x > n || y < 1 || y > n) return 0;
	return b[x][y];
}
int check1(int k, int i) { return check(i, k-i); }
int check1(int k, int i, int j) { return check1(k, i) + check1(k, j); }
int check2(int k, int i) { return check(i, i-k); }
int check2(int k, int i, int j) { return check2(k, i) + check2(k, j); }

int main() {
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i]+1);
		for (int j = 1; j <= n; ++j) {
			b[i][j] = s[i][j]=='*';
			sum[0][i+j][i] = sum[1][i-j+n][i] = b[i][j];
		}
	}
	for (int k = 0; k <= 2*n; ++k) {
		for (int i = 1; i <= n; ++i) {
			sum[0][k][i] += sum[0][k][i-1];
			sum[1][k][i] += sum[1][k][i-1];
		}
	}
	for (int k = 2; k <= 2*n; ++k) {
		for (int i = max(1, k-n); i <= min(n, k-1); ++i) if (check1(k, i)) {
			for (int j = max(1, k-n); j < i; ++j) if (check1(k, j)) {
//				printf("(%d,%d) (%d,%d) %lld %lld\n", i, k-i, j, k-j, ans1, ans2);
				ans1 += range(0, k-2*(i-j), i-2*(i-j), j);
				ans2 += check1(k-2*(i-j), i-2*(i-j), j);
				ans1 += range(0, k+2*(i-j), i, j+2*(i-j));
				ans2 += check1(k+2*(i-j), i, j+2*(i-j));
//				printf("(%d,%d) (%d,%d) %lld %lld\n", i, k-i, j, k-j, ans1, ans2);
			}
		}
	}
	for (int k = -n+1; k <= n-1; ++k) {
		for (int i = max(1, k+1); i <= min(n, k+n); ++i) if (check2(k, i)) {
			for (int j = max(1, k+1); j < i; ++j) if (check2(k, j)) {
//				printf("(%d,%d) (%d,%d) %lld %lld\n", i, i-k, j, j-k, ans1, ans2);
				ans1 += range(1, k-2*(i-j), i-2*(i-j), j);
				ans2 += check2(k-2*(i-j), i-2*(i-j), j);
				ans1 += range(1, k+2*(i-j), i, j+2*(i-j));
				ans2 += check2(k+2*(i-j), i, j+2*(i-j));
//				printf("(%d,%d) (%d,%d) %lld %lld\n", i, i-k, j, j-k, ans1, ans2);
			}
		}
	}
//	printf("%lld %lld\n", ans1, ans2);
	printf("%lld\n", ans1-ans2/2);
}

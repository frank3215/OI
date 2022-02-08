#include <bits/stdc++.h>
using namespace std;

const int maxn = 10, MX = 10;

int n, k;
int a[maxn];
int f[maxn][1<<MX], ans;

inline int count(int x) {
	int ret = 0;
	for (int i = 0; i < MX; ++i) 
		ret += (x>>i)&1;
	return ret;
}

int main() {
	cin >> n;
	memset(f, 0xc0, sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		for (int j = 0; j < (1<<a[i]); ++j) {
			int S = ((1<<a[i])-1)^j;
			for (int k = S; ; k = (k-1)&S) {
				f[i][k] = max(f[i][k], f[i-1][j]+count(j));
//				printf("j = %d, f[%d][%d] = %d\n", j, i, k, f[i][k]);
//				printf("f[%d-1][%d]=%d + count(%d)=%d\n", i, j, f[i-1][j], j, count(j));
				ans = max(ans, f[i][k]);
				if (k == 0) break;
			}
		}
	}
	cout << ans << endl;
}

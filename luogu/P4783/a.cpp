#include <bits/stdc++.h>
using namespace std;

const int maxn = 410, P = 1e9+7;
typedef long long ll;

int n, a[maxn][maxn], b[maxn][maxn];

int qpow(int a, int x) {
	int ret = 1;
	for (; x; a = (ll)a*a%P, x >>= 1)
		if (x&1) ret = (ll)ret*a%P;
	return ret;
}
inline int inv(int x) { return qpow(x, P-2); }

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	}
	for (int i = 0; i < n; ++i)
		b[i][i] = 1;
	for (int i = 0; i < n; ++i) {
		bool flag = 1;
		for (int j = i; j < n; ++j) {
			if (a[j][i] != 0) {
				swap(a[j], a[i]);
				swap(b[j], b[i]);
				flag = 0;
				break;
			}
		}
		if (flag) return puts("No Solution"), 0;
		int t = inv(a[i][i]);
		for (int k = 0; k < n; ++k) {
			a[i][k] = (ll)a[i][k]*t%P;
			b[i][k] = (ll)b[i][k]*t%P;
		}
		for (int j = 0; j < n; ++j) if (j != i) {
			int t = a[j][i];
			for (int k = 0; k < n; ++k) {
				(b[j][k] += P-(ll)t*b[i][k]%P) %= P;
				(a[j][k] += P-(ll)t*a[i][k]%P) %= P;
			}
		}
	}
	for (int i = 0; i < n; ++i, putchar('\n'))
		for (int j = 0; j < n; ++j) {
			printf("%d ", b[i][j]);
		}
}

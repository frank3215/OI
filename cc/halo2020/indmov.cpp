#include <bits/stdc++.h>
using namespace std;

const int N = 40;

int t, n, m;
int a[N];

struct matrix{
	int dat[N][N];
	matrix(int x = 0) {
		memset(dat, 0, sizeof(dat));
		for (int i = 0; i < N; ++i) dat[i][i] = x;
	}
}g;

matrix operator *(matrix x, matrix y) {
	matrix ret;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				ret.dat[i][k] |= x.dat[i][j]&y.dat[j][k];
			}
		}
	}
	return ret;
}

matrix qpow(matrix a, int x) {
	matrix ret(1);
	for (; x; x >>= 1, a = a*a) if (x&1) ret = ret*a;
	return ret;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		g = matrix();
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a+i);
			for (int j = 2; j <= n; ++j) {
				if (a[i]%j == 0) {
					if (i+j < n) g.dat[i][i+j] = 1;
					if (i-j >= 0) g.dat[i][i-j] = 1;
					while (a[i]%j == 0) a[i]/=j;
				}
			}
		}
		scanf("%d", &m);
		matrix t = qpow(g, m);
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < n; ++j) {
//				cout << t.dat[i][j] << ' ';
//			}
//			cout << endl;
//		}
		cout << (t.dat[0][n-1]?"YES":"NO") << endl;
	}
}

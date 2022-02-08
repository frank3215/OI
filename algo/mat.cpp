#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;

const int maxn = 101, P = 1e9+7;

struct mat{
	int n, m, a[maxn][maxn];
	void E(int _n) {
		n = m = _n;
		for (int i = 0; i < n; ++i)
			a[i][i] = 1;
	}
	void in(int _n, int _m) {
		n = _n, m = _m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				scanf("%d", &a[i][j]);
				a[i][j] = (a[i][j]%P+P)%P;
			}
	}
	mat operator *(const mat &M) const {
		assert(m == M.n);
		mat ret = {n, M.m};
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				for (int k = 0; k < M.m; ++k)
					ret.a[i][k] = (ret.a[i][k]+1ll*a[i][j]*M.a[j][k])%P;
		return ret;
	}
	void out() {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				printf("%d%c", a[i][j], " \n"[j+1==m]);
	}
}e, m;

mat qpow(mat a, long long x) {
	if (x == 0) return e;
	else if (x%2 == 0) return qpow(a*a, x/2);
	else return qpow(a*a, x/2)*a;
}

int main() {
	long long n, k;
	cin >> n >> k;
	e.E(n);
	m.in(n, n);
//	m.out();
//	(m*m).out();
	qpow(m, k).out();
}

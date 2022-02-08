#include <bits/stdc++.h>
using namespace std;

const int P = 998244353, MX = 1<<21;
typedef long long ll;
int n, m, rev[MX], a[MX], b[MX];
int W, Wn[MX];

int qpow(int a, int x) {
	int ret = 1;
	for (; x; a = (ll)a*a%P, x >>= 1)
		if (x&1) ret = (ll)ret*a%P;
	return ret;
}

void FFT(int *a, int m, bool inv = 0) {
	int n = (1<<m);
	for (int i = 0; i < n; ++i)
		if (rev[i] > i) swap(a[i], a[rev[i]]);
	for (int _ = 1; _ <= m; ++_) {
		int i = 1<<_;
		for (int j = 0; j < n; j += i) {
			for (int k = j, wn = 1; k < j+i/2; ++k, wn = Wn[(k-j)<<(m-_)]) {
				int x = a[k], y = (ll)wn*a[k+i/2]%P;
				a[k] = (x + y)%P;
				a[k+i/2] = (x + P - y)%P;
			}
		}
	}
	if (inv) {
		reverse(a+1, a+n);
		int invn = qpow(n, P-2);
		for (int i = 0; i < n; ++i)
			a[i] = (ll)a[i]*invn%P;
	}
}

void print(int *a, int t) {
	for (int i = 0; i < t; ++i) printf("%d%c", a[i], " \n"[i+1==t]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; ++i) {
		scanf("%d", a+i);
	}
	for (int j = 0; j <= m; ++j) {
		scanf("%d", b+j);
	}
	int N = n+m, t, T;
	for (t = 0; (T=1<<t) <= N; ++t);
	for (int i = 1; i < T; ++i) rev[i] = (rev[i>>1]>>1)|(i&1?T>>1:0);
	W = qpow(3, (P-1)/T);
	Wn[0] = 1;
	for (int i = 1; i < T/2; ++i) Wn[i] = (ll)Wn[i-1]*W%P;
	FFT(a, t);
	FFT(b, t);
	for (int i = 0; i < T; ++i) a[i] = (ll)a[i]*b[i]%P;
	FFT(a, t, 1);
	print(a, N+1);
}

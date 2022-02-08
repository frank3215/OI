#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
using namespace std;

const int P = 998244353, N = (1<<21);

typedef long long ll;

int n, m;
int a[N], b[N];

namespace FFT {
	int t, k;
	int r[N];

	int qpow(int a, int x) {
		int ret = 1;
		for (; x; x >>= 1, a = (ll)a*a%P) if (x&1) ret = (ll)ret*a%P;
		return ret;
	}

	void DFT(int *a, bool type) {
		FOR(i,0,t) if (r[i] > i) swap(a[i], a[r[i]]);
		for (int step = 1; step < t; step <<= 1) {
			int wn = qpow(3, (P-1)/(2*step));
			for (int j = 0; j < t; j += 2*step) {
				int w = 1;
				for (int i = j; i < j+step; ++i) {
					int tmp = (ll)w*a[i+step]%P;
					a[i+step] = (a[i]-tmp)%P;
					a[i] = (a[i]+tmp)%P;
					w = (ll)w*wn%P;
				}
			}
		}
		if (type) {
			FOR(i,1,t/2) swap(a[i], a[t-i]);
		}
	}

	void FFT(int *a, int *b, int n) {
		for (t = 1, k = 0; t < n; t <<= 1, ++k);
		FOR(i,1,t) {
			r[i] = (r[i>>1]>>1)|((i&1)<<(k-1));
		}
		DFT(a, 0);
		DFT(b, 0);
		FOR(i,0,t) a[i] = (ll)a[i]*b[i]%P;
		DFT(a, 1);
		int invt = qpow(t, P-2);
		FOR(i,0,t) a[i] = (P+((ll)a[i]*invt%P))%P;
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	FOR(i,0,n+1) scanf("%d", a+i);
	FOR(i,0,m+1) scanf("%d", b+i);
	FFT::FFT(a, b, n+m+1);
	FOR(i,0,n+m+1) printf("%d%c", a[i], " \n"[i==n+m]);
}


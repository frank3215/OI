#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
#define debug(x) cout << #x << " = " << x << endl
#define FIO(x) \
	freopen(x ".in", "r", stdin); \
	freopen(x ".out", "w", stdout);
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

const int MAXN = 1<<20, P = 998244353;

int numN;
int lo[MAXN], r[MAXN];
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int qpow(int a, int x = P-2) {
	int ret = 1;
	for (; x; a = a*a%P, x >>= 1)
		if (x&1) ret = ret*a%P;
	return ret;
}

void DFT(int *a, int l, bool type) {
	FOR(i,0,l) if (i < r[i]) swap(a[i], a[r[i]]);
	for (int step = 2; step <= l; step <<= 1) {
		for (int i = 0, wn = qpow(3, (P-1)/step); i < l; i += step) {
			for (int j = i, w = 1; j < i+step/2; ++j, w = w*wn%P) {
				int tmp = a[j+step/2]*w%P;
				a[j+step/2] = (a[j]-tmp)%P;
				a[j] = (a[j]+tmp)%P;
			}
		}
	}
	if (type) {
		reverse(a+1, a+l);
		int invl = qpow(l);
		FOR(i,0,l) a[i] = a[i]*invl%P;
	}
}

void Mul(int *a, int *b, int l) {
	FOR(i,1,l) {
		r[i] = r[i>>1]>>1|(i&1?l>>1:0);
	}
	DFT(a, l, 0);
	DFT(b, l, 0);
	FOR(i,0,l) a[i] = a[i]*b[i]%P;
	DFT(a, l, 1);
}

void solve(int n) {
	if (n == 1) {
		b[0] = qpow(a[0]);
		return;
	}
	int m = (n+1)/2;
	solve(m);
	int l = 1<<(lo[n]+2);
	FOR(i,0,l) c[i] = 0;
	FOR(i,0,n) c[i] = a[i];
	FOR(i,0,l) d[i] = b[i];
	Mul(c, d, l);
	FOR(i,0,n) c[i] = -c[i];
	c[0] = (2+c[0])%P;
	FOR(i,n,l) c[i] = 0;
	FOR(i,0,l) d[i] = b[i];
	Mul(c, d, l);
	FOR(i,0,n) b[i] = c[i];
}

signed main() {
	FOR(i,2,MAXN) lo[i] = lo[i-1]+((1<<lo[i-1])<i);
#ifndef ONLINE_JUDGE
	FIO("a");
#endif
	scanf("%lld", &numN);
	FOR(i,0,numN) {
		scanf("%lld", a+i);
	}
	solve(numN);
	FOR(i,0,numN) printf("%lld ", (b[i]%P+P)%P);
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int M = 1010;

int n, x, p, m;
int a[M], b[M][M], aa[M], f[M];
int ans;

int pow(int a, int x) {
	int ret = 1;
	for (; x; a = a*a%p, x >>= 1)
		if (x&1) ret = ret*a%p;
	return ret;
}

signed main() {
	freopen("problem.in", "r", stdin);
	freopen("problem.out", "w", stdout);
	scanf("%lld%lld%lld%lld", &n, &x, &p, &m);
	FOR(i,0,m+1) scanf("%lld", a+i);
	b[0][0] = 1;
	FOR(i,0,m) {
		FOR(j,0,i+1) {
			//printf("b[%lld][%lld] = %lld\n", i, j, b[i][j]);
			b[i+1][j+1] = (b[i+1][j+1]+b[i][j])%p;
			b[i+1][j] = (b[i+1][j]-i*b[i][j])%p;
		}
	}
	ROF(i,0,m+1) {
		aa[i] = a[i];
		//printf("a'[%lld] = %lld\n", i, aa[i]);
		FOR(j,0,i+1) {
			a[j] = (a[j]-aa[i]*b[i][j])%p;
		}
	}
	f[0] = 1;
	FOR(i,0,m) {
		f[i+1] = f[i]*(n-i)%p;
	}
	ROF(i,0,m+1) {
		ans = (ans + aa[i]*f[i]%p*pow(x,i)%p*pow(1+x, n-i))%p;
	}
	printf("%lld\n", (ans+p)%p);
}

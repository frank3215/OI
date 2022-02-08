#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,b,a) for (int i = (b)-1; i >= a; --i)
using namespace std;

const int N = 5010, P = 1e9+7;
typedef long long ll;

int qpow(int a, int x) {
	int ret = 1;
	for (; x; a = 1ll*a*a%P, x >>= 1) if (x&1) ret = 1ll*ret*a%P;
	return ret;
}

int n, m;
int f[N][N], s[N][N], pow2[N], inv2[N];

signed main() {
	scanf("%d%d", &m, &n);
	FOR(i,0,n+1) {
		pow2[i] = qpow(2, i);
		inv2[i] = qpow(2, P-1-i);
	}
	FOR(i,1,n+1) {
		f[0][i] = 1;
		s[0][i] = (s[0][i-1] + 1ll*inv2[i]*i%P*f[0][i])%P;
		//printf("s[%d][%d] = %d\n", 0, i, s[0][i]);
	}
	FOR(i,1,m+1) {
		FOR(j,1,n+1) {
			f[i][j] = ((j+1ll)*f[i-1][j] + 1ll*pow2[j-1]*s[i-1][j-1])%P;
			s[i][j] = (s[i][j-1] + 1ll*inv2[j]*j%P*f[i][j])%P;
			//printf("s[%d][%d] = %d\n", i, j, s[i][j]);
		}
	}
	printf("%d\n", f[m][n]);
}


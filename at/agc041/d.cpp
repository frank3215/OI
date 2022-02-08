#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define MOD(x,m) ((x)%(m)+(m))%(m)

const int maxn = 5e3+10;
int n, m;
int b[maxn], f[maxn][maxn];

int main() {
	cin >> n >> m;
	int mid = n/2;
	F0R(i, mid+1) F0R(j, i+1) b[j]--;
	F0R(i, mid) F0R(j, n-i) b[j]++;
	F0R(i, n) {
		b[i]++;
//		printf("%d ", b[i]); fflush(stdout);
	}
	f[0][0] = 1;
	F0R(i, n-1)
		F0R(j, n)
			for (int k = 0; k*b[i+1]+j <= n; ++k)
				(f[i+1][k*b[i+1]+j] += f[i][j]) %= m;
	long long ans = 0;
	F0R(i, n) {
		(ans += 1ll*f[n-1][i]*(n-i)) %= m;
//		printf("%d\n", f[n-1][i]);
	}
	cout << ans << endl;
}

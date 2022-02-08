#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)

typedef vector<int> vi;
typedef vector<vi> vvi;

const vvi nul = {{1},{1}}, e = {{1,0},{0,1}};
const int P = 998244353, maxn = 410;

int n, a[maxn], pow2[maxn], C[maxn][maxn];

vvi dfs(int l, int r, int b) {
	int len = r-l+1;
	if (l == r) return nul;
	if (r-l == 1 && a[l] == b) return e;
	vvi dp = vvi(2, vi(len));
	FOR(i,l,r) if (a[i] == b) {
		auto dp1 = dfs(l, i, b), dp2 = dfs(i+1, r, b);
		F0R(j,i-l+1) F0R(k,r-i) {
			dp[0][j+k] = (dp[0][j+k]+1ll*dp1[0][j]*dp2[0][k])%P;
			dp[1][j+k+1] = (dp[1][j+k+1]+1ll*dp1[1][j]*dp2[1][k])%P;
		}
		return dp;
	}
	auto dp1 = dfs(l, r, b+1);
	F0R(i,len) dp[0][i] = dp1[1][i];
	F0R(i,len) FOR(j,i,len) {
		dp[1][i] = (dp[1][i]+1ll*dp1[1][j]*C[j][i]%P*pow2[len-1-j])%P;
	}
	F0R(i,len) FOR(j,i,len) {
		dp[0][i] = (dp[0][i]+1ll*dp1[0][j]*C[j][i]%P*(pow2[len-1-j]-(i==j)))%P;
	}
	return dp;
}

int main() {
	C[0][0] = 1;
	FOR(i,1,maxn)
		F0R(j,i+1) {
			C[i][j] = j?(C[i-1][j-1]+C[i-1][j])%P:1;
		}
	pow2[0] = 1;
	FOR(i,1,maxn) pow2[i] = 2*pow2[i-1]%P;

	cin >> n;
	F0R(i,n) cin >> a[i];
	auto dp = dfs(0, n, 0);
	cout << dp[0][0] << endl;
}

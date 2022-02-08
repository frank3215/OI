#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define ROF(i,a,b) for (int i = b; i >= a; --i)
using namespace std;

const int N = 5010, P = 1e9+7;

int n, p[N], f[N], siz[N], k;
int dp[N][N], poww[N], fact[N];
int ans, cnt;
vector<int> v;

int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
int ksm(int a, int x) {
	int ret = 1;
	for (; x; x >>= 1, a = (a*a)%P) if (x&1) (ret *= a) %= P;
	return ret;
}

signed main() {
	cin >> n;
	poww[0] = fact[0] = 1;
	FOR(i,1,n) {
		poww[i] = poww[i-1]*(n-1)%P;
		fact[i] = fact[i-1]*i%P;
	}
	FOR(i,1,n) f[i] = i;

	FOR(i,1,n) {
		cin >> p[i];
		if (p[i] != -1) f[find(p[i])] = find(i);
	}
	FOR(i,1,n) siz[find(i)]++;
	FOR(i,1,n) {
		if (p[i] == -1) {
			v.push_back(siz[find(i)]);
			siz[find(i)] = 0;
		}
	}
	FOR(i,1,n) if (f[i] == i && siz[i]) cnt++;
	k = v.size();
	ans = (poww[k]*(n-cnt))%P;
	dp[0][0] = 1;

	FOR(i,1,k) {
		FOR(j,0,k) {
			dp[i][j] = dp[i-1][j];
			if (j) (dp[i][j] += dp[i-1][j-1]*v[i-1]) %= P;
		}
	}
	FOR(i,2,k) (ans -= dp[k][i]*fact[i-1]%P*poww[k-i]%P) %= P;
	FOR(i,0,k-1) (ans -= (v[i]-1)*poww[k-1]%P) %= P;
	cout << (ans+P)%P << endl;
}

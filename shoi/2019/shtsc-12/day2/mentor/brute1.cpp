#include <bits/stdc++.h>
const int maxn = 1010, maxc = maxn, maxk = 40, maxm = 2510, MOD = 998244353;
const int team[] = {0, 0, 1, 1}, pai[] = {0, 1, 0, 1};
int ans;
int t, n, c, k, c0, c1, d0, d1, m;
int b[maxn], s[maxn], d[maxn];
int dp[maxn][maxm];
std::vector<int> v[maxc];
void clear() {
	for (int i = 1; i <= c; ++i) v[c].clear();
}
void brute() {
	ans = 0;
	for (int i = 0; i < (1<<(n<<1)); ++i) {
		bool ok = 1;
		int num[4]={}, a[n+1];
		for (int j = 0; j < (n<<1); j+=2) {
			int k = j/2+1;
			a[k] = (i>>j)&3;
			if (a[k] == d[k]) ok = 0;
			num[a[k]] += s[k];
		}
		if (!ok) continue;
		if (num[0]+num[1] > c0) continue;
		if (num[2]+num[3] > c1) continue;
		if (num[0]+num[2] > d0) continue;
		if (num[1]+num[3] > d1) continue;
		for (int j = 1; j <= c; ++j) {
			for (int k = 1; k < v[j].size(); ++k) {
				int x = v[j][k], y = v[j][k-1];
				if (team[a[x]] != team[a[y]]) ok = 0;
			}
		}
		if (ok) {
			ans++;
		}
	}
	printf("%d\n", ans);
}
void k0() {
	memset(dp, 0, sizeof(dp)); dp[0][0] = 1;
	int tot = 0, ans1 = 0, ans2 = 0;
	for (int i = 1; i <= c; ++i) if (v[i].size()) {
		int sum = 0;
		for (int j = 0; j < v[i].size(); ++j) {
			sum += s[v[i][j]];
		}
		tot += sum;
		for (int j = 0; j <= c0; ++j) {
			dp[i][j] = dp[i-1][j];
			if (j >= sum) dp[i][j] += dp[i-1][j-sum];
			dp[i][j] %= MOD;
		}
	}
	for (int i = tot-c1; i <= c0; ++i)
		ans1 = (ans1 + dp[c][i])%MOD;

	memset(dp, 0, sizeof(dp)); dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= d1; ++j) {
			dp[i][j] = dp[i-1][j];
			if (j >= s[i]) dp[i][j] += dp[i-1][j-s[i]];
			dp[i][j] %= MOD;
		}
	}
	for (int i = tot-d1; i <= d0; ++i)
		ans2 = (ans2 + dp[n][i])%MOD;
	printf("%lld\n", (long long)ans1*ans2%MOD);
}
int main() {
	freopen("mentor.in", "r", stdin);
	freopen("mentor.out", "w", stdout);
	for (scanf("%d", &t); t--; clear()) {
		scanf("%d%d", &n, &c);
		scanf("%d%d%d%d", &c0, &c1, &d0, &d1);
		m = std::max(std::max(c0, c1), std::max(d0, d1));
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", b+i, s+i);
			v[b[i]].push_back(i);
		}
		memset(d, -1, sizeof(d));
		scanf("%d", &k);
		int id, p;
		for (int i = 1; i <= k; ++i) {
			scanf("%d%d", &id, &p);
			d[id] = p;
		}
		if (n <= 10) brute();
		else if (k == 0) k0();
	}
}

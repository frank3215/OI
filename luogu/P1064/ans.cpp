#include <bits/stdc++.h>
using namespace std;

const int maxn = 32010, maxm = 70;

int n, m, v[maxm], p[maxm], q[maxm];
int dp[maxn], tmp[maxn];
vector<int> has[maxm];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> v[i] >> p[i] >> q[i];
		p[i] *= v[i];
		has[q[i]].push_back(i);
	}
	for (int i = 1; i <= m; ++i) if (q[i] == 0) {
		for (int k = 0; k <= n; ++k)
			tmp[k] = k<v[i]?-1e9:dp[k-v[i]]+p[i];
		for (int j = 0; j < (int)has[i].size(); ++j) {
			int I = has[i][j];
			for (int k = n; k >= v[I]; --k)
				tmp[k] = max(tmp[k], tmp[k-v[I]]+p[I]);
		}
		for (int k = 0; k <= n; ++k)
			dp[k] = max(dp[k], tmp[k]);
	}
	cout << dp[n] << endl;
}

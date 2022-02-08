#include <bits/stdc++.h>
using namespace std;

const int maxn = 32010, maxm = 70;

int n, m, v[maxm], p[maxm], q[maxm];
int dp[maxn];
vector<int> has[maxm];
vector<pair<int, int> > tmp;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> v[i] >> p[i] >> q[i];
		p[i] *= v[i];
		has[q[i]].push_back(i);
	}
	for (int i = 1; i <= m; ++i) {
		if (q[i] == 0) {
			tmp.clear();
			for (int j = 0; j < (1<<(int)has[i].size()); ++j) {
				int V = v[i], P = p[i];
				for (int k = 0; k < (int)has[i].size(); ++k)
					if ((j>>k)&1) {
						V += v[has[i][k]];
						P += p[has[i][k]];
					}
				tmp.push_back(make_pair(V, P));
			}
			for (int k = n; ~k; --k) {
				for (int j = 0; j < (int)tmp.size(); ++j) {
					int V = tmp[j].first, P = tmp[j].second;
					if (V > k) continue;
					dp[k] = max(dp[k], dp[k-V]+P);
				}
			}
		}
	}
	cout << dp[n] << endl;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 18;

int n, m;
int p[N+1];
int vis1[N+1], vis2[N+1];
vector<int> to[N+1];

void dfs(int x) {
	for (auto y: to[x]) {
		if (!vis1[y]) {
			vis1[y] = vis2[p[y]] = vis1[x];
			dfs(y);
		}
	}
}

int solve0(int *p, int n) {
	int vis[n+1] = {};
	int ans = 0;
	for (int i = 1, j, k; i <= n; ++i) {
		if (vis[i]) continue;
		for (k = i, j = 0; !vis[k]; vis[k] = 1, k = p[k]) ++j;
		ans += j-1;
	}
	return ans;
}

int q[N+1];
int x[N+1], y[N+1];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		to[i].clear();
	}
	if (m == 0) {
		cout << solve0(p, n) << endl;
		return;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> x[i] >> y[i];
		to[x[i]].push_back(y[i]);
		to[y[i]].push_back(x[i]);
	}
	memset(vis1, 0, sizeof(vis1));
	for (int i = 1; i <= n; ++i) if (!vis1[i]) {
		vis1[i] = vis2[p[i]] = i;
		dfs(i);
	}
	//for (int i = 1; i <= n; ++i) cout << i << " : " << vis1[i] << "," << vis2[i] << endl;
	for (int i = 1; i <= n; ++i) {
		q[i] = i;
	}
	int ans = n;
	do {
		bool flag = false;
		for (int i = 1; i <= n; ++i) {
			if (vis2[q[i]] != vis1[i]) {
				flag = true;
				break;
			}
		}
		if (flag) continue;
		//for (int i = 1; i <= n; ++i) cout << q[i] << ' '; cout << endl;
		ans = min(ans, solve0(q, n));
	} while (next_permutation(q+1, q+n+1));
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}

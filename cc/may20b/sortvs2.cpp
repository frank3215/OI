#include <bits/stdc++.h>
using namespace std;

const int N = 18, inf = 1e9;

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

int q[N+1];
int x[N+1], y[N+1], f[1<<N];

bool check(int x) {
	int in[n+1] = {}, out[n+1] = {};
	//cout << x << endl;
	for (int i = 0; i < n; ++i) {
		if ((x>>i)&1) {
			//cout << ' ' << i+1 << ' ' << p[i+1] << endl;
			//cout << "=" << vis2[i+1] << ' ' << vis2[p[i+1]] << endl;
			out[vis2[i+1]]++;
			in[vis2[p[i+1]]]++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (in[i] != out[i] || in[i] >= 2 || out[i] >= 2) return false;
	}
	return true;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		to[i].clear();
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
	f[0] = -inf;
	for (int i = 1; i < (1<<n); ++i) {
		if (check(i)) {
			//cout << '(' << i << ')' << endl;
			f[i] = 1;
		}
		else f[i] = -inf;
	}
	for (int i = 1; i < (1<<n); ++i) {
		for (int j = i; ; j = (j-1)&i) {
			f[i] = max(f[i], f[i^j]+f[j]);
			if (!j) break;
		}
	}
	cout << n-f[(1<<n)-1] << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}

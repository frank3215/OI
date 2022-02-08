#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 8;

int n;
int x[maxn], y[maxn], hole[maxn], ans, vis[maxn], nxt[maxn];
int b[maxn];

map<ll, vector<int> > s;

void dfs(int num, int k, bool b = false) {
	if (!k) {
		for (int i = 1; i <= n; ++i) {
			printf(" %d %d\n", i, hole[i]);
		}
		ans = max(ans, num);
		return;
	}
	if (!vis[k]) {
		++num;
	}
	if (++vis[k] >= 5) return;
	if (b) {
		dfs(num, nxt[k]);
		return;
	}
	if (!hole[k]) {
		ans = max(ans, num);
		for (int i = 1; i <= n; ++i) if (i != k && (!hole[i])) {
			hole[k] = i, hole[i] = k;
			dfs(num, i, true);
			hole[k] = hole[i] = 0;
		}
	} else {
		dfs(num, hole[k], true);
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", x+i, y+i);
	}
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) if (j != i) {
			int kx = x[i]-x[j], ky = y[i]-y[j];
			s.clear();
			memset(nxt, 0, sizeof(nxt));
			for (int k = 1; k <= n; ++k) {
				b[k] = (kx*y[k]-ky*x[k]);
				//printf("%d %d %d: %lld\n", i, j, k, b[k]);
				if (!s[b[k]].empty()) nxt[s[b[k]].back()] = k;
				s[b[k]].push_back(k);
			}
			//for (int k = 1; k <= n; ++k) printf("nxt[%d] = %d\n", k, nxt[k]);
			for (int k = 1; k <= n; ++k) {
				//puts("!");
				memset(vis, 0, sizeof(vis));
				dfs(0, k);
			}
		}
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
}

#include <bits/stdc++.h>
const int maxn = 2e5+10;
int n, val[maxn], fa[maxn];
/*
namespace brute{
	const int maxn = 20;
	int mx[maxn][maxn], tot, vis[maxn], anc[maxn], dep;
	long long ans = 0;
	int dfs(int u, int fa) {
		long long tmp = 0;
		for (int i = 1; i <= tot; ++i) {
			tmp += mx[i];
		}
		for (int i = 1; i <= tot+1; ++i) {
			if (!anc[i]) {
				anc[i] = 1;
				mx[u][i] = mx[fa][i];
			}
		}
	}
}
*/
namespace chain{
	std::vector<int> g[maxn];
	std::vector<int> vt;
	long long ans;
	void dfs(std::multiset<int> &s, int u) {
		std::multiset<int> t;
		for (int i = 0; i < g[u].size(); ++i) {
			int v = g[u][i];
			dfs(t, v);
			if (t.size() > s.size()) std::swap(t, s);
			while (!t.empty()) {
				int x = *--t.end(), y = *--s.end();
				vt.push_back(std::max(x, y));
				t.erase(--t.end());
				s.erase(--s.end());
			}
			while (!vt.empty()) {
				s.insert(vt.back());
				vt.pop_back();
			}
		}
		s.insert(val[u]);
	}
	void solve() {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", val+i);
		}
		for (int i = 2; i <= n; ++i) {
			scanf("%d", fa+i);
			g[fa[i]].push_back(i);
		}
		std::multiset<int> s;
		dfs(s, 1);
		for (std::multiset<int>::iterator it = s.begin(); it != s.end(); ++it) {
			ans += *it;
		}
		printf("%lld\n", ans);
	}
}
int main() {
	freopen("spring.in", "r", stdin);
	freopen("spring.out", "w", stdout);
	chain::solve();
}

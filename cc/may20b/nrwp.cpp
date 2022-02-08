#include <bits/stdc++.h>
#define int long long
using namespace std;

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, W = 1010, N = 210;
int n, h, w, par[W][W], H[W][W];
int x[N], y[N], p[N];

namespace flow{
	const int N = 1e5+10, M = 5*N, inf = 0x3f3f3f3f3f3f3f3f;
	int s, t;
	int nxt[M<<1], head[N], to[M<<1], f[M<<1], tot;
	int cur[N], dep[N];
	void _add(int u, int v, int w) {
		assert(++tot < (M<<1));
		nxt[tot] = head[u], to[tot] = v, f[tot] = w, head[u] = tot;
	}
	void add(int u, int v, int w) {
		//printf("%d--(%d)-->%d\n", u, w, v);
		_add(u, v, w);
		_add(v, u, 0);
	}
	bool bfs() {
		memcpy(cur, head, sizeof(cur));
		queue<int> q;
		q.push(s);
		memset(dep, 0, sizeof(dep));
		dep[s] = 1;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int e = head[u]; e; e = nxt[e]) {
				if (!f[e]) continue;
				int v = to[e];
				if (!dep[v]) {
					dep[v] = dep[u]+1;
					q.push(v);
				}
			}
		}
		//for (int i = 1; i <= t; ++i) { printf("%d:%d\n", i, dep[i]); }
		return dep[t];
	}
	int dfs(int u, int fl) {
		if (u == t) return fl;
		int ans = 0;
		for (int &e = cur[u]; e; e = nxt[e]) {
			int v = to[e], w = f[e];
			if (!w || dep[v] != dep[u]+1) continue;
			int ret = dfs(v, min(fl, w));
			fl -= ret;
			f[e] -= ret;
			//printf("%d->%d:%d(%d)\n", u, v, ret, f[e]);
			f[e^1] += ret;
			ans += ret;
			if (!fl) break;
		}
		return ans;
	}
	int solve(int S, int T) {
		int ans = 0;
		s = S, t = T;
		while (bfs()) {
			//printf("%d\n", ans);
			ans += dfs(s, inf);
		}
		return ans;
	}
	void clear() {
		tot = 1;
		memset(head, 0, sizeof(head));
	}
}
using namespace flow;

void solve() {
	int ans = 0;
	cin >> h >> w >> n;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			cin >> H[i][j];
		}
	}
	memset(par, 0, sizeof(par));
	clear();
	int s = n+1, t = n+2;
	for (int i = 1; i <= n; ++i) {
		cin >> y[i] >> x[i] >> p[i];
		par[y[i]][x[i]] = i;
		if (H[y[i]][x[i]]) {
			if (H[y[i]][x[i]] > 0) {
				ans += H[y[i]][x[i]]*p[i];
				add(s, i, 2*H[y[i]][x[i]]*p[i]);
			} else {
				ans -= H[y[i]][x[i]]*p[i];
				add(i, t, -2*H[y[i]][x[i]]*p[i]);
			}
		}
		for (int j = 0; j < 4; ++j) {
			int k = par[y[i]+dy[j]][x[i]+dx[j]];
			if (k) {
				//printf("%d %d\n", i, k);
				ans += p[i]*p[k];
				add(i, k, 2*p[i]*p[k]);
				add(k, i, 2*p[i]*p[k]);
			}
		}
	}
	ans -= solve(s, t);
	cout << ans << endl;
	for (int i = 1; i <= n; ++i)
		cout << (dep[i]?1:-1) << ' ';
	cout << endl;
}

signed main() {
	int t;
	cin >> t;
	while (t--) solve();
}

#include <bits/stdc++.h>
const int P = 998244353, maxn = 1e5, maxl = 110;
int n, l, k;
int head[maxn], nxt[maxn<<1], to[maxn<<1], tot;
void connect(int u, int v) {
	++tot;
	to[tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
}
void gugugu() {}
/*
namespace nl{
	int f[maxn], ans;
	void dfs(int u, int fa) {
		f[u] = 1;
		for (int e = head[u]; e; e = nxt[e]) {
			int v = to[e];
			if (v == fa) continue;
			dfs(v, u);
			f[u] = (long long)f[u]*(1+f[v])%P;
		}
		ans = (ans+f[u])%P;
	}
	void solve() {
		dfs(1, 0);
		if (k == 1) printf("%d\n", f[1]);
	}
}
*/
namespace nsmall{
	int ok[1<<10], has[1<<10];
	std::vector<int> valid[11][11];
	void dfs(int u, int f) {
		valid[u][0].push_back(1<<u);
		ok[1<<(u-1)] = 1;
		for (int e = head[u]; e; e = nxt[e]) {
			int v = to[e];
			if (v == f) continue;
			dfs(v, u);
			for (int k = 1; k <= l; ++k) {
				for (int i = 0; i < valid[v][k-1].size(); ++i) {
					valid[u][k].push_back((1<<u)|valid[v][k-1][i]);
					ok[valid[u][k].back()>>1] = 1;
				}
			}
		}
	}
	int pow(long long a, int x) {}
	int popcnt(int x) {}
	void solve() {
		for (int i = 1; i <= n; ++i) dfs(i, 0);
		for (int i = 1; i < (1<<n); ++i) if (ok[i])
			for (int j = i; j; j = (j-1)&i) if (ok[j])
				has[j]++;
/*		for (int i = 1; i < (1<<n); ++i) {
			int a[n+1]={0};
			for (int j = 0; j < n; ++j) {
				if ((i>>j)&1)
					a[++a[0]] = j+1;
			}
			for (int j = 1; j <= a[0]; ++j)
				for (int k = 1; k <= a[0]; ++k) {
					if (d[i][i] > l) a[0] = 0;
				}
			if (not a[0]) continue;
			ok[i] = 1;
			for (int j = i; j; j = (j-1)&i) {
				has[j]++;
			}
		}*/
		int ans = 0;
		for (int i = 1; i < (1<<n); ++i) {
			int x = popcnt(i)%2;
			if (x == 1) {
				ans = (ans+pow(has[i], k))%P;
			}
			else {
				ans = (ans+P-pow(has[i], k))%P;
			}
		}
	}
}
namespace k1{
	int f[maxn][maxl], sum[maxn][maxl], sum2[maxn][maxl], g[maxn][maxl], ans;
	void dfs(int u, int fa) {
		f[u][0] = 1;
		sum[u][0] = 1;
		for (int e = head[u]; e; e = nxt[e]) {
			int v = to[e];
			if (v != fa) {
				dfs(v, u);
				for (int i = 1; i <= l; ++i) {
					sum[u][i] = (sum[u][i-1] + f[u][i])%P;
					f[u][i] = (long long)sum[u][i]*(f[v][i-1])%P;
				}
			}
		}
	}
	void dfs2(int u, int fa) {
		g[u][0] = sum2[u][0] = 1;
		for (int e = head[u]; e; e = nxt[e]) {
			int v = to[e];
			if (v != fa) {
				for (int i = 0; i < l; ++i) {
					g[v][i+1] += g[u][i];
				}
				dfs2(v, u);
			}
		}
		for (int i = 0; i <= l; ++i) {
			if (i) sum2[u][i] = sum2[u][i-1] + g[u][i];
//			printf("%d %d %d %d\n", ans, sum2[u][i], f[u][i], g[u][i]);
			ans = (ans+(sum2[u][i]+1ll)*f[u][i] + g[u][i])%P;
		}
	}
	void solve() {
		dfs(1, 0);
		dfs2(1, 0);
		printf("%d", ans);
	}
}
int main() {
	freopen("hope.in", "r", stdin);
	freopen("hope.out", "w", stdout);
	scanf("%d%d%d", &n, &l, &k);
	int u, v;
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &u, &v);
		connect(u, v);
		connect(v, u);
	}
	if (k == 1) k1::solve();
	else if (n <= 16) nsmall::solve();
	else gugugu();
}

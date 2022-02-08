#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10, MOD = 1e9+7;

int N, K;

long long P(int n, int k) {
	if (n < k) return 0;
	long long ans = 1;
	for (int i = 0; i < k; ++i) {
		ans = ans*(n-i)%MOD;
	}
	return ans;
}

struct graph{
	vector<int> e[maxn];
	long long f[maxn];
	void add(int u, int v) {
		e[u].push_back(v);
	}
	void add2(int u, int v) {
		add(u, v), add(v, u);
	}
	int dfs(int u, int fa) {
		f[u] = 1;
		for (int i = 0; i < e[u].size(); ++i) {
			int v = e[u][i];
			if (v == fa) continue;
			dfs(v, u);
			f[u] = f[u]*f[v]%MOD*P(K-2, e[v].size()-1)%MOD;
		}
		return P(K-1, e[u].size())*f[u]%MOD*K%MOD;
	}
}g;

int main() {
	scanf("%d%d", &N, &K);
	int u, v;
	for (int i = 1; i < N; ++i) {
		scanf("%d%d", &u, &v);
		g.add2(u, v);
	}
	printf("%d", g.dfs(1, 0));
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+10;

vector<int> g[maxn], a;
int n, ans[maxn], sum;

void add2(int u, int v) {
	g[u].push_back(v);
	g[v].push_back(u);
}

void dfs(int u, int fa) {
	ans[u] = a.back(); a.pop_back();
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (v != fa) dfs(v, u);
	}
}

int main() {
	scanf("%d", &n);
	int u, v;
	for (int i = 0; i < n-1; ++i) {
		scanf("%d%d", &u, &v);
		add2(u, v);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &u);
		a.push_back(u);
		sum += u;
	}
	sort(a.begin(), a.end());
	sum -= a.back();
	dfs(1,0);
	printf("%d\n", sum);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
}

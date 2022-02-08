#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n, a[N];
vector<int> to[N];

int b[N], ans[N];

void dfs(int u, int f) {
	int pos = -1, val = 0;
	pos = lower_bound(b, b+n+1, a[u])-b;
	val = b[pos];
	b[pos] = min(b[pos], a[u]);
	for (int v: to[u]) {
		if (v == f) continue;
		dfs(v, u);
	}
	ans[u] = lower_bound(b, b+n+1, 0x3f3f3f3f)-b-1;
	b[pos] = val;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	memset(b, 0x3f, sizeof(b));
	b[0] = 0;
	dfs(1, 1);
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", ans[i]);
	}
}

#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y) {
	if (y == k) {
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n-1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		to[u].pb(v);
		to[v].pb(u);
	}
	for (k = 1; k <= n; ++k) {
		dfs(1, 0);
	}
}

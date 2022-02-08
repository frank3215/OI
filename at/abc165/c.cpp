#include <bits/stdc++.h>
using namespace std;

const int N = 11, Q = 51;

int n, m, q, A[N];
int a[Q], b[Q], c[Q], d[Q];
int ans;

void dfs(int dep, int pre) {
	if (dep == n+1) {
		int ret = 0;
		for (int i = 0; i < q; ++i) {
			if (A[b[i]] - A[a[i]] == c[i]) ret += d[i];
		}
		ans = max(ret, ans);
		return;
	}
	for (int i = pre; i <= m; ++i) {
		A[dep] = i;
		dfs(dep+1, i);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d%d%d%d", a+i, b+i, c+i, d+i);
	}
	dfs(1, 1);
	printf("%d\n", ans);
}

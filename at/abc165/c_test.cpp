#include <bits/stdc++.h>
using namespace std;

const int N = 11, Q = 51;

int n, m, q, A[N];
int a[Q], b[Q], c[Q], d[Q];
int ans;

void dfs(int dep, int pre) {
	if (dep == n+1) {
		ans++;
		return;
	}
	for (int i = pre; i <= m; ++i) {
		A[dep] = i;
		dfs(dep+1, i);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	dfs(1, 1);
	printf("%d\n", ans);
}

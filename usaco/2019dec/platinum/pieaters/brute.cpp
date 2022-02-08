#include <bits/stdc++.h>
using namespace std;

const int maxn = 55, maxm = 25;

int n, m;
int w[maxm], l[maxm], r[maxm], pie[maxn], p[maxn];
int ans;

bool cmp(int i, int j) { return r[i]-l[i] < r[j]-l[j]; }

void dfs(int u, int W=0) {
	if (u == m) {
		ans = max(ans, W);
		return;
	}
	bool ok = false;
	for (int i = l[p[u]]; i <= r[p[u]]; ++i) if (!pie[i]) ok = true;
	for (int i = 0; i <= ok; ++i) {
		if (i) {
			for (int i = l[p[u]]; i <= r[p[u]]; ++i) pie[i]++;
			dfs(u+1, W+w[p[u]]);
			for (int i = l[p[u]]; i <= r[p[u]]; ++i) pie[i]--;
		}
		else dfs(u+1, W);
	}
}

int main() {
	freopen("pieaters.in", "r", stdin);
	freopen("pieaters.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", w+i, l+i, r+i);
		p[i] = i;
	}
	sort(p, p+m, cmp);
	dfs(0);
	printf("%d\n", ans);
}

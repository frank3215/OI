#include <bits/stdc++.h>
using namespace std;

int n, k, m;
int p[10], ans[10];

void build(int l, int r, int dep) {
	if (l == r) return;
	int mn = n, j = -1;
	for (int i = l; i < r; ++i)
		if (p[i] < mn) j = i, mn = p[i];
	ans[j] += dep;
	build(l, j, dep+1);
	build(j+1, r, dep+1);
}

int main() {
	freopen("treedepth.in", "r", stdin);
	freopen("treedepth.out", "w", stdout);
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < n; ++i) p[i] = i;
	do {
		int inv = 0;
		for (int i = 0; i < n; ++i)
			for (int j = i+1; j < n; ++j)
				inv += p[i]>p[j];
		if (inv != k) continue;
		build(0, n, 1);
	} while (next_permutation(p, p+n));
	for (int i = 0; i < n; ++i) printf("%d%c", ans[i], " \n"[i==n-1]);
}

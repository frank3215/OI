#include <bits/stdc++.h>
using namespace std;

const int P = 998244353, maxn = 50;

int n, m, a[maxn][maxn], sel[maxn], ans=-1;

void dfs(int i, int k, int num) {
//	printf("%d %d %d\n", i, k, num);
	if (i == n) {
		for (int i = 0; i < m; ++i)
			if (sel[i] > k/2) return;
		ans = (ans+num)%P;
//		printf("%d\n", ans);
		return;
	}
	dfs(i+1, k, num);
	for (int j = 0; j < m; ++j) if (a[i][j]) {
		sel[j]++;
		dfs(i+1, k+1, 1ll*num*a[i][j]%P);
		sel[j]--;
	}
}

int main() {
	freopen("meal.in", "r", stdin);
	freopen("meal.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	dfs(0, 0, 1);
	printf("%d\n", ans);
}

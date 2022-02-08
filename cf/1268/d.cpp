#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;

int n, deg[maxn], tmp[maxn], ans, mn;
char s[maxn][maxn];
int g[maxn][maxn];
int C[maxn];

void inv(int u) {
	for (int i = 0; i < n; ++i) if (i != u) {
		if (g[u][i]) {
			deg[u]--, deg[i]++;
		} else {
			deg[u]++, deg[i]--;
		}
		g[u][i] = !g[u][i];
		g[i][u] = !g[i][u];
	}
}

bool check() {
	memcpy(tmp, deg, sizeof(tmp));
	sort(tmp, tmp+n);
	for (int i = 0, j = 0; i < n-1; ++i) {
		j += tmp[i] - i;
		if (j == 0) return false;
	}
	return true;
}

void brute(int cnt) {
	if (cnt > mn) return;
	if (check()) {
		if (cnt == mn) ans++;
		else mn = cnt, ans = 1;
		return;
	}
	for (int i = 0; i < n; ++i) {
		inv(i);
		brute(cnt+1);
		inv(i);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
		for (int j = 0; j < n; ++j) {
			g[i][j] = s[i][j]=='1';
			deg[i] += g[i][j];
		}
	}
	if (check()) {
		printf("0 1\n");
	} else if (n <= 6) {
		mn = n;
		brute(0);
		if (ans) printf("%d %d\n", mn, ans);
		else puts("-1");
	} else {
		for (int i = 0; i < n; ++i) {
			inv(i);
			ans += check();
			inv(i);
		}
		printf("1 %d\n", ans);
	}
}

#include <cstdio>
#include <algorithm>
#include <cstring>

const int maxn = 10;

int t, r, c;
int vis[maxn][maxn];
std::pair<int, int> st[maxn*maxn];

bool ok(int x1, int y1, int x2, int y2) {
	return !vis[x2][y2] && x1 != x2 && y1 != y2 && x1-y1 != x2-y2 && x1+y1 != x2+y2;
}

bool dfs(int x, int y, int cur = 0) {
	st[++cur] = std::make_pair(x, y);
	vis[x][y] = 1;
	if (cur == r*c) return 1;
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			if (ok(x, y, i, j)) {
				if (dfs(i, j, cur))
					return 1;
				vis[i][j] = 0;
			}
	return 0;
}
void solve(int i) {
	scanf("%d%d", &r, &c);
	printf("Case #%d: ", i);
	for (int j = 1; j <= r; ++j)
		for (int k = 1; k <= c; ++k) {
			memset(vis, 0, sizeof(vis));
			if (dfs(j, k)) {
				puts("POSSIBLE");
				for (int l = 1; l <= r*c; ++l)
					printf("%d %d\n", st[l].first, st[l].second);
				return;
			}
		}
	puts("IMPOSSIBLE");
}

int main() {
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
		solve(i);
	return 0;
}

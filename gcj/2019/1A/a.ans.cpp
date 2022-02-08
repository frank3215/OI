#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

const int maxn = 30;

int t, r, c, flag;
int vis[maxn][maxn];
std::pair<int, int> st[maxn*maxn];

bool ok(int x1, int y1, int x2, int y2) {
	return !vis[x2][y2] && x1 != x2 && y1 != y2 && x1-y1 != x2-y2 && x1+y1 != x2+y2;
}

bool dfs(int x, int y, int cur = 0) {
	printf("%d\n", cur);
	st[++cur] = std::make_pair(x, y);
	vis[x][y] = 1;
	if (cur == r*c) return 1;

	vector<int> vi;
	if (r <= 5 && c <= 5) {
		puts("!");
		for (int i = 1; i <= r; ++i)
			for (int j = 1; j <= c; ++j) if (ok(x, y, i, j)){
				if (dfs(i, j, cur)) return 1;
				vis[i][j] = 0;
			}
	}
	else for (int k = 0; k < 50; ++k) {
		int i = rand()%r+1, j = rand()%c+1;
		if (ok(x, y, i, j)) {
			if (dfs(i, j, cur)) return 1;
			vis[i][j] = 0;
		}
	}
	return 0;
}
void solve(int i) {
	printf("Case #%d: ", i);

	scanf("%d%d", &r, &c);
	printf("%d %d\n", r,c);
	flag = 0;
	if (r < c) std::swap(r, c), flag = 1;
	if (c == 1 || (c == 2 && r <= 4) || (c == 3 && r == 3)) {
		puts("IMPOSSIBLE");
		return;
	}
	if (flag) std::swap(r, c);

	puts("POSSIBLE");
	for (int cnt = 0; ; cnt++) {
		memset(vis, 0, sizeof(vis));
		int j = rand()%r+1, k = rand()%c+1;
		if (dfs(j, k)) {
			for (int l = 1; l <= r*c; ++l)
				printf("%d %d\n", st[l].first, st[l].second);
			break;
		}
//		printf("%d\n", cnt);
	}
}

int main() {
	srand(22333333);
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
		solve(i);
	return 0;
}

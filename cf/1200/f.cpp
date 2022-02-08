#include <bits/stdc++.h>
using namespace std;

const int GCD = 2520, maxn = 1010;

int n, k[maxn], m[maxn];
vector<int> e[maxn];
int vis[maxn][GCD], cnt[maxn], ans;

int MOD(int x, int y) { return ((x%y)+y)%y; }

int dfs(int x, int y) {
	if (vis[x][y] == -2) {
		vis[x][y] = ans;
	} else if (vis[x][y] <= 0) {
		if (vis[x][y] == -1) {
			ans += (cnt[x]==0);
			cnt[x] = 1;
		}
		vis[x][y]--;
		vis[x][y] = dfs(e[x][MOD(y+k[x], m[x])], MOD(y+k[x], GCD));
		cnt[x] = 0;
	}
//	printf("vis[%d][%d] = %d\n", x, y, vis[x][y]);
	return vis[x][y];
}

int main() {
	int q, x, y;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", k+i);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", m+i);
		for (int j = 0; j < m[i]; ++j) {
			scanf("%d", &y);
			e[i].push_back(y);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < GCD; ++j) {
			if (vis[i][j] == 0) {
				ans = 0;
				dfs(i, j);
			}
		}
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &x, &y);
//		printf("%d %d\n", x, MOD(y, GCD));
		printf("%d\n", vis[x][MOD(y, GCD)]);
	}
}

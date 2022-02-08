#include <cstdio>
#include <cstring>
const int maxn = 1010;
const int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
char g[maxn][11];
int n,k,cur,vis[maxn][11];
int dfs(int x, int y) {
	if (vis[x][y] == cur || g[x][y] == '0') return 0;
	vis[x][y] = cur;
	int ans = 1;
	for (int i = 0; i < 4; ++i) 
		if (g[x][y] == g[x + dx[i]][y + dy[i]]) {
			ans += dfs(x + dx[i], y + dy[i]);
		}
	return ans;
}
void del(int x, int y) {
	if (!vis[x][y]) return;
	vis[x][y] = 0;
	for (int i = 0; i < 4; ++i) 
		if (g[x][y] == g[x + dx[i]][y + dy[i]]) {
			del(x + dx[i], y + dy[i]);
		}
	g[x][y] = '0';
}
void gravity() {
	for (int j = 1, cur, i; j <= 10; ++j) {
		for (i = n, cur = n; i; --i) {
			if (g[i][j] != '0') g[cur--][j] = g[i][j];
		}
		for (; cur; --cur) g[cur][j] = '0';
	}
}
void print() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 10; ++j) {
			putchar(g[i][j]);
		}
		putchar('\n');
	}
}
int main() {
	freopen("mooyomooyo.in","r",stdin);
	freopen("mooyomooyo.out","w",stdout);
	scanf("%d%d", &n, &k);
	memset(g,'0',sizeof(g));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 10; ++j) {
			scanf(" %c", &g[i][j]);
		}
	}
	bool ok = true;
	while ((++cur,ok)) {
		ok = false;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 10; ++j) if (g[i][j] != '0'){
				if (dfs(i,j) >= k) {
					del(i,j);
					ok = true;
//					print();
//					puts("");
				}
			}
		}
		gravity();
//		print();
//		puts("\n");
	}
	print();
}


#include <bits/stdc++.h>
using namespace std;

const int GCD = 2520, maxn = 1010;

int n, k[maxn], m[maxn];
vector<int> e[maxn];
int vis[maxn][GCD], cnt[maxn], ans;

int MOD(int x, int y) { return ((x%y)+y)%y; }

void dfs(int x, int y) {
	typedef pair<pair<int, int>, int> stnode;
#define mp make_pair
#define fi first
#define se second
	stack<stnode> st;
	st.push(mp(mp(x, y), 0));
	while (!st.empty()) {
		stnode s = st.top()
		st.pop();
		if (vis[x][y] > 0) {
			ans = vis[x][y];
			continue;
		} else if (vis[x][y] == -2) {
			vis[x][y] = ans;
			continue;
		}
		st.push(mp(mp(x, y), 1);
		if (vis[x][y] == 0 || vis[x][y] == -1) {
			if (vis[x][y] == -1) {
				ans += (cnt[x]==0);
				cnt[x] = 1;
			}
			vis[x][y]--;
			st.push(make_pair(e[x][MOD(y+k[x], m[x])], MOD(y+k[x], GCD)));
			cnt[x] = 0;
		}
		vis[x][y] = ans;
	}
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

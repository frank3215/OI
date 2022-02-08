#include <bits/stdc++.h>
using namespace std;

const int maxn = 2510, maxm = 5010, inf = 1e9;

#define fi first
#define se second
#define f(i, a, b) for (int i = a; i < b; ++i)
vector<pair<int, int> > g[maxn], gg[maxn];

int n, m, p;
int dis[maxn], inq[maxn], cnt[maxn];
int vis[maxn];

void dfs(int x) {
	if (vis[x]) return;
	vis[x] = 1;
	for (int i = 0; i < (int)gg[x].size(); ++i) {
		int y = gg[x][i].fi, z = gg[x][i].se;
		dfs(y);
		g[y].push_back(make_pair(x, z));
	}
}

int main() {
	cin >> n >> m >> p;
	int a, b, c;
	f(i, 0, m) {
		cin >> a >> b >> c;
		gg[b].push_back(make_pair(a, c-p));
	}
	dfs(n);
	//SPFA
	f(i, 2, n+1)
		dis[i] = -inf;
	queue<int> q;
	q.push(1);
	int x;
	while (!q.empty()) {
		x = q.front(); q.pop(); inq[x] = 0;
		if (++cnt[x] > m) break;
		f(i, 0, (int)g[x].size()) {
			int y = g[x][i].fi, z = g[x][i].se;
			if (dis[y] < dis[x]+z) {
				dis[y] = dis[x]+z;
				if (!inq[y]) {
					q.push(y);
					inq[y] = 1;
				}
			}
		}
	}
	if (cnt[x] > m) {
		cout << -1 << endl;
	}
	else {
		cout << max(0, dis[n]) << endl;
	}
}

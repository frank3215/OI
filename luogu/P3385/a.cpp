#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 2e3+10;
int n, m, cnt[maxn], inq[maxn], dis[maxn];
vector<int> to[maxn], c[maxn];

void add(int u, int v, int w) {
	to[u].push_back(v);
	c[u].push_back(w);
}

bool solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		to[i].clear();
		c[i].clear();
		cnt[i] = inq[i] = 0;
		dis[i] = 1e9;
	}
	int u, v, w;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		if (w >= 0) add(v, u, w);
	}
	queue<int> q;
	q.push(1);
	dis[1] = 0;
	inq[1] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = 0;
		if (++cnt[u] > n) return true;
		for (int i = 0; i < (int)c[u].size(); ++i) {
			int v = to[u][i], w = c[u][i];
			if (dis[u]+w < dis[v]) {
				dis[v] = dis[u]+w;
				if (!inq[v]) {
					q.push(v);
					inq[v] = 1;
				}
			}
		}
	}
//	for (int i = 1; i <= n; ++i) printf("%d(%d)%c", i, dis[i], " \n"[i==n]);
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		puts(solve()?"YE5":"N0");
	}
}

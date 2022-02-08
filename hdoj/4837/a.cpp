#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+10;

vector<int> g[maxn];
int n, m;
int ans[maxn], deg[maxn];


void solve() {
	scanf("%d%d", &n, &m);
	int a, b;
	memset(ans, 0, sizeof(ans));
	memset(deg, 0, sizeof(deg));
	for (int i = 1; i <= n; ++i) 
		g[i].clear();
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		g[b].push_back(a);
		deg[a]++;
	}
	priority_queue<int> q;
	for (int i = 1; i <= n; ++i)
		if (!deg[i])
			q.push(i);
	int cur = n;
	while (!q.empty()) {
		int x = q.top(); q.pop();
		ans[--cur] = x;
//		if (vis[x]) continue;
		for (int i: g[x])
			if (!--deg[i]) q.push(i);
	}
	for (int i = 0; i < n; ++i)
		printf("%d%c", ans[i], " \n"[i+1==n]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}

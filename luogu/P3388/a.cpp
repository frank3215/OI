#include <bits/stdc++.h>
using namespace std;

const int N = 2e4+10, M = 1e5+10;

int n, m;
int u[M], v[M], w[M];
int low[N], dfn[N], ins[N], tot;
vector<int> ans, E[N];
stack<int> s;

void tarjan(int u, int f) {
	low[u] = dfn[u] = ++tot;
//	printf("%d: %d\n", u, dfn[u]);
	s.push(u), ins[u] = 1;
	int cnt = 0;
	for (auto e: E[u]) {
		if (e == f) continue;
		int v = w[e]^u;
		if (!dfn[v]) {
			tarjan(v, e);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) ++cnt;
		} else if (ins[v]) {
			low[u] = min(dfn[v], low[u]);
		}
	}
//	printf(" %d: %d %d\n", u, low[u], cnt);
	if ((f && cnt) || (!f && cnt >= 2)) ans.push_back(u);
	if (low[u] == dfn[u]) {
		do {
			int v = s.top(); s.pop();
			ins[v] = 0;
		} while (ins[u]);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", u+i, v+i);
		w[i] = u[i]^v[i];
		E[u[i]].push_back(i);
		E[v[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i, 0);
	printf("%d\n", (int)ans.size());
	sort(ans.begin(), ans.end());
	for (auto u: ans)
		printf("%d ", u);
}

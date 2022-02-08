#include <bits/stdc++.h>
#define print //printf
using namespace std;

const int maxn = 5e3+10, maxm = 5e5+10;
typedef pair<int, int> pii;
typedef map<pii, int> mpiii;
int n, m;
int ans[maxm], fa[maxn];
pii Q[maxm], q[maxm], his[maxm<<1]; int HIS, tot;
mpiii edges;
vector<int> tr[maxm<<2];

int find(int u) {
	while (fa[u]>0) u = fa[u];
	return u;
}
void merge(int u, int v) {
	int fx = find(u), fy = find(v);
	if (fx == fy) return;
	if (fa[fx] > fa[fy]) swap(fx, fy);
	if (fa[fx] == fa[fy]) {
		his[++HIS] = make_pair(fx, fa[fx]);
		fa[fx]--;
	}
	his[++HIS] = make_pair(fy, fa[fy]);
	fa[fy] = fx;
}

void add(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		tr[u].push_back(tot);
		return;
	}
	int m = (l+r)>>1;
	if (m < R) add(u<<1|1, m, r, L, R);
	if (m > L) add(u<<1, l, m, L, R);
}

void dfs(int u, int l, int r) {
	int cur = HIS;
	for (int i = 0; i < (int)tr[u].size(); ++i) {
		merge(q[tr[u][i]].first, q[tr[u][i]].second);
	}
	if (r-l == 1) {
		if (Q[l].first)
			ans[l] = find(Q[l].first) == find(Q[l].second);
	} else {
		int m = (l+r)>>1;
		dfs(u<<1, l, m);
		dfs(u<<1|1, m, r);
	}
	for (; cur < HIS; --HIS) {
		fa[his[HIS].first] = his[HIS].second;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	int op, x, y; pii e;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &op, &x, &y);
		if (x > y) swap(x, y);
		e = make_pair(x, y);
		if (op == 0) edges[e] = i;
		if (op == 1) {
			q[++tot] = e;
			add(1, 0, m, edges[e], i);
			edges.erase(e);
		}
		if (op == 2) Q[i] = e;
	}
	for (mpiii::iterator it = edges.begin(); it != edges.end(); ++it) {
		q[++tot] = it->first;
		add(1, 0, m, it->second, m);
	}
	dfs(1, 0, m);
	for (int i = 0; i < m; ++i) {
		if (Q[i].first) puts(ans[i]?"Y":"N");
	}
}

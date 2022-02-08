#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+10, maxw = 1e9;
typedef long long ll;
const ll inf = 1e18;

int n, m, a[maxn], b[maxn], c[maxn], anc[maxn];
vector<pair<int,int> > to[maxn];
ll dep[maxn];
int mid;

void add(int u, int v, int w) {
	to[u].push_back(make_pair(w,v));
}

void init(int u, int f) {
	anc[u] = f==1?u:anc[f];
	for (int i = 0; i < (int)to[u].size(); ++i) {
		int v = to[u][i].second, w = to[u][i].first;
		if (v == f) continue;
		dep[v] = dep[u]+w;
		init(v, u);
	}
}

bool ok[maxn], 
ll dfs1(int u, int f) {
	ll ans = inf;
	ok[u] = true;
	if (b[u] && dep[u] > mid) ret = 0;
	for (int i = 0; i < (int)to[u].size(); ++i) {
		int v = to[u][i].second, w = to[u][i].first;
		if (v == f) continue;
		ret = min(ret, ok(v, u)+w);
		ok[u] &= ok[v];
	}
	if (ret <= mid) ok[u] = true;
	return ret;
}

bool check() {
	memset(far, 0, sizeof(far));
	for (int i = 0; i < n; ++i)
		if (dep[a[i]] <= mid && ) {
			far[anc[a[i]]] = i;
		}
	for (int i = 0; i < n; ++i) {
		if (dep[a[i]] > mid) continue;
		if (vis[i]) continue;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u,v,w), add(v,u,w);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", a+i);
		b[a[i]] = 1;
	}
	if (m < (int)to[1].size()) return puts("-1"),0;

	init(1,0);
	v = to[1];
	sort(a, a+m, cmp);
	sort(to[1].begin(), to[1].end());

	ll r = 0, l = (ll)maxw*maxn;
	while (r < l) {
		mid = (r+l)>>1;
		if (check()) l = mid;
		else r = mid+1;
	}
	printf("%lld\n", l);
}

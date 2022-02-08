#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e5+10, maxlogn = 20;
const ll inf = 1e18;

int n, m, a[maxn];
int head[maxn], nxt[maxn<<1], to[maxn<<1], w[maxn<<1], tot=1;
int fa[maxn][maxlogn];
ll g[maxn][maxlogn];
vector<ll> vis[maxn], tim, unc;
bool cover[maxn];

void add(int x, int y, int z) {
	++tot;
	nxt[tot] = head[x];
	to[tot] = y;
	w[tot] = z;
	head[x] = tot;
}

void init(int x, int f) {
	fa[x][0] = to[f^1];
	g[x][0] = w[f];
	for (int k = 1; k < maxlogn; ++k) {
		fa[x][k] = fa[fa[x][k-1]][k-1];
		g[x][k] = g[x][k-1]+g[fa[x][k-1]][k-1];
	}
	for (int e = head[x]; e; e = nxt[e]) {
		if ((e^f) == 1) continue;
		init(to[e], e);
	}
}

bool dfs(int x) {
	cover[x] = 1;
	int cnt = 0;
	for (int e = head[x]; e; e = nxt[e]) {
		if (to[e] == fa[x][0]) continue;
		cover[x] &= dfs(to[e]);
		cnt++;
	}
	if (!cnt) cover[x] = 0;
	return vis[x].size() || cover[x];
}

bool get() {
	dfs(1);
	tim.clear();
	unc.clear();
	for (int e = head[1]; e; e = nxt[e]) {
		int x = to[e], c = w[e];
		if (vis[x].size() || cover[x]) {
			sort(vis[x].begin(), vis[x].end());
			for (int i = !cover[x]; i < (int)vis[x].size(); ++i)
				if (vis[x][i] > c)
					tim.push_back(vis[x][i]-c);
		}
		else unc.push_back(c);
	}
/*
	puts("tim:");
	for (int i = 0; i < (int)tim.size(); ++i) printf("%lld ", tim[i]);
	puts("");
*/
	for (int e = head[1]; e; e = nxt[e]) {
		int x = to[e], c = w[e];
		if (vis[x].size() && cover[x] == 0) {
//			printf(" !%d\n", x);
			int u = vis[x][0], i = lower_bound(tim.begin(), tim.end(), u-c)-tim.begin();
			if (i && tim[i-1] >= c) tim[i-1] = u-c;
		}
	}
/*
	puts("tim:");
	for (int i = 0; i < (int)tim.size(); ++i) printf("%lld ", tim[i]);
	puts("");
	puts("unc:");
	for (int i = 0; i < (int)unc.size(); ++i) printf("%lld ", unc[i]);
	puts("");
*/
	sort(tim.begin(), tim.end());
	sort(unc.begin(), unc.end());
	for (int i = 0, j = 0; i < (int)unc.size(); ++i, ++j) {
		while (j < (int)tim.size() && tim[j] < unc[i]) ++j;
		if (j == (int)tim.size()) return false;
	}
	return true;
}

bool check(ll len) {
	for (int i = 1; i <= n; ++i) vis[i].clear();
	for (int i = 0; i < m; ++i) {
		int x = a[i]; ll s = 0;
//		printf("%d:", x);
		for (int j = maxlogn-1; ~j; --j) {
			if (s+g[x][j] <= len && fa[x][j] > 1) {
				s += g[x][j];
				x = fa[x][j];
			}
		}
		vis[x].push_back(len-s);
//		printf("(%d, %lld)\n", x, len-s);
	}
	return get();
}

int main() {
	scanf("%d", &n);
	int u, v, w;
	for (int i = 0; i < n-1; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	init(1, 0);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", a+i);
	}
	ll l = 0, r = inf, mid;
	while (l < r) {
		mid = (l+r)>>1;
//		printf("\n\n%lld\n", mid);
		if (check(mid)) r = mid;
		else l = mid+1;
	}
	if (r == inf) cout << -1 << endl;
	else cout << r << endl;
}

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)

#define pb push_back

const int maxn = 3e5, LOG = 20;

vector<int> ga[maxn], gb[maxn];
map<int,bool> m[maxn];
int n;
int fa[maxn][LOG], f[maxn], dep[maxn];

int find(int x) {
	return f[x]?f[x]=find(f[x]):x;
}
void dfs1(int x, int f=0) {
	fa[x][0] = f;
	dep[x] = dep[f]+1;
	FOR(k,1,LOG)
		fa[x][k] = fa[fa[x][k-1]][k-1];
	for (auto y : ga[x]) {
		if (y == f) continue;
		dfs1(y, x);
	}
}
int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	R0F(k,LOG) if (dep[fa[x][k]] >= dep[y]) x = fa[x][k];
	if (x == y) return x;
	R0F(k,LOG) if (fa[x][k] != fa[y][k]) x = fa[x][k], y = fa[y][k];
	return fa[x][0];
}
void get(int x, int y) {
	int l = lca(x, y), z;
	if (find(x) != find(l)) {
		z = find(x);
	} else {
		z = y;
		R0F(k, LOG) if (dep[fa[z][k]] > dep[l] && find(fa[z][k]) != find(l)) {
			z = fa[z][k];
		}
	}
	printf("%d %d %d %d\n", z, fa[z][0], x, y);
	f[z] = fa[z][0];
}
void dfs2(int x, int f=0) {
	for(auto y : gb[x]) {
		if (y == f) continue;
		dfs2(y, x);
		get(y, x);
	}
}

signed main() {
	cin >> n;
	int u, v;
	F0R(i,n-1) {
		cin >> u >> v;
		m[u][v] = m[v][u] = 1;
		ga[u].pb(v);
		ga[v].pb(u);
	}
	dfs1(1);
	printf("%d\n", n-1);
	F0R(i,n-1) {
		cin >> u >> v;
		gb[u].pb(v);
		gb[v].pb(u);
	}
	dfs2(1);
}

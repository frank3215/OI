#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10, maxlogn = 18;

int n, m, q;
int a[maxn], b[maxn], c[maxn];
vector<pair<int, int> > g[maxn];
int dep[maxn], fa[maxn][maxlogn]; bool fw[maxn][maxlogn];

int f[maxn];
int find(int x) {
	return f[x]?f[x]=find(f[x]):x;
}

void add(int a, int b, int c) {
	g[a].push_back(make_pair(b, c));
}
void init(int x) {
	for (int i = 1; i < maxlogn; ++i) {
		int tmp = fa[x][i-1];
		fa[x][i] = fa[tmp][i-1];
		fw[x][i] = fw[x][i-1] || fw[tmp][i-1];
	}
	for (int e = 0; e < g[x].size(); ++e) {
		int v = g[x][e].first, w = g[x][e].second;
		if (v == fa[x][0]) continue;
		fa[v][0] = x;
		fw[v][0] = w;
		init(v);
	}
}
int verify(int a, int b) {
	assert(find(a) == find(b));
	if (dep[a] < dep[b]) swap(a, b);
	int ans = 0;
	for (int i = maxlogn-1; ~i; --i) {
		if (dep[fa[a][i]] >= dep[b]) {
			ans |= fw[a][i];
			a = fa[a][i];
		}
	}
	if (a == b) return ans;
	for (int i = maxlogn-1; ~i; --i) {
		if (fa[a][i] != fa[b][i]) {
			ans |= fw[a][i] || fw[b][i];
			a = fa[a][i];
			b = fa[b][i];
		}
	}
	return ans || fa[a][0] || fa[a][1];
}

bool solve() {
	scanf("%d%d%d", &n, &m, &q);
	int ans = 0;
	for (int i = 0; i < q; ++i) {
		scanf("%d%d%d", a+i, b+i, c+i);
		a[i]++, b[i]++;
		if (find(a[i]) != find(b[i])) {
			f[find(a[i])] = find(b[i]);
			add(a[i], b[i], c[i]), add(b[i], a[i], c[i]);
			ans += c[i]+1;
		}
	}
	if (ans > m) return false;
	for (int i = 1; i <= n; ++i)
		if (!dep[i]) init(1);
	for (int i = 0; i < q; ++i) {
		if (verify(a[i], b[i]) != c[i])
			return false;
	}
	return true;
}

int main() {
	puts(solve()?"Yes":"No");
}

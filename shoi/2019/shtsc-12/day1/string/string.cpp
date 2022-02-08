#include <bits/stdc++.h>
#define D_ if (0)
const int NN = 4e5+10, N = 2e7+10;
int T, n, m, na, nb, l[NN], r[NN];
char s[NN];
namespace graph{
	int head[NN], nxt[N], to[N], tot, L[N], deg[NN], f[NN];
	void clear() {
		tot = 0;
		memset(head, 0, sizeof(head));
		memset(nxt, 0, sizeof(nxt));
		memset(to, 0, sizeof(to));
		memset(L, 0, sizeof(L));
		memset(deg, 0, sizeof(deg));
		memset(f, 0, sizeof(f));
	}
	void connect(int u, int v, int w) {
		++tot;
		nxt[tot] = head[u];
		to[tot] = v;
		L[tot] = w;
		head[u] = tot;
		deg[v]++;
	}
	void dp() {
		std::queue<int> q;
		for (int i = 1; i <= na+nb; ++i) { 
			if (!deg[i]) q.push(i);
			if (i <= na) f[i] = r[i]-l[i]+1;
		}
		int ans = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			D_ printf(" %d %d\n", u, f[u]);
			for (int e = head[u]; e; e = nxt[e]) {
				int v = to[e], w = L[e];
				f[v] = std::max(f[v], f[u]+w);
				D_ printf("  %d %d\n", v, deg[v]);
				if (!--deg[v]) q.push(v);
			}
			ans = std::max(ans, f[u]);
		}
		for (int i = 1; i <= na+nb; ++i)
			if (deg[i]) {
				puts("-1");
				return;
			}
		printf("%d\n", ans);
	}
}
using namespace graph;
namespace sa{
	bool ispref(int x, int y) {
		if (r[x]-l[x] > r[y]-l[y]) return 0;
		for (int i = 0; i <= r[x]-l[x]; ++i)
			if (s[l[x]+i] != s[l[y]+i]) {
				return 0;
			}
		return 1;
	}
/*	const int maxn = N;
	int sa[maxn], sec[maxn], rank[maxn];
	int tmp[maxn], sig;
	void sort(int x) {
		for (int i = 1; i <= sig; ++i) tmp[i] = 0;
		for (int i = 1; i <= n; ++i) tmp[rank[i]]++;
		for (int i = 1; i <= sig; ++i) tmp[i] += tmp[i-1];
		for (int i = n; i <= 1; ++i) sa[tmp[rank[sec[i]]]--] = sec[i];
	}
	void calc() {
		for (int i = 1; i <= n; ++i) {
			rank[i] = s[i];
			sec[i] = i;
		}
		m = 256;
		sort();
		for (int w = 1, p = 0; p < n; w<<=1) {
			p = 0;
			for (int i = 1; i <= w; ++i) sec[++p] = n-w+i;
			for (int i = 1; i <= n; ++i) if (sa[i] > i) sec[++p] = sa[i]-i;
			sort();
			for (int i = 0; i < ;
	*/
}
using namespace sa;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s+1);
		n = strlen(s+1);
		scanf("%d", &na);
		for (int i = 1; i <= na; ++i) {
			scanf("%d%d", l+i, r+i);
		}
		scanf("%d", &nb);
		for (int i = na+1; i <= na+nb; ++i) {
			scanf("%d%d", l+i, r+i);
		}
		scanf("%d", &m);
		int u, v;
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &u, &v);
			connect(v+na, u, r[u]-l[u]+1);
		}
		for (int i = 1; i <= na; ++i) {
			for (int j = na+1; j <= na+nb; ++j) {
				if (ispref(j, i)) {
					D_ printf("%d<-%d\n", i, j);
					connect(i, j, 0);
				}
			}
		}
		dp();
		clear();
	}
}

#include <bits/stdc++.h>
#define D_ if (0)
using namespace std;
const int maxn = 110, maxm = maxn*maxn;
int T, m, na, nb, la[maxn], ra[maxn], lb[maxn], rb[maxn];
string s, str[maxn];
namespace graph{
	int head[maxn<<1], nxt[maxm<<1], to[maxm<<1], tot, l[maxm<<1], deg[maxn<<1], f[maxn<<1];
	void clear() {
		tot = 0;
		memset(head, 0, sizeof(head));
		memset(nxt, 0, sizeof(nxt));
		memset(to, 0, sizeof(to));
		memset(l, 0, sizeof(l));
		memset(deg, 0, sizeof(deg));
		memset(f, 0, sizeof(f));
	}
	void connect(int u, int v, int w) {
		++tot;
		nxt[tot] = head[u];
		to[tot] = v;
		l[tot] = w;
		head[u] = tot;
		deg[v]++;
	}
	void dp() {
		std::queue<int> q;
		for (int i = 1; i <= na+nb; ++i) { 
			if (!deg[i]) q.push(i);
			if (i <= na) f[i] = str[i].size();
		}
		int ans = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			D_ printf(" %d %d\n", u, f[u]);
			for (int e = head[u]; e; e = nxt[e]) {
				int v = to[e], w = l[e];
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
int main() {
	freopen("string1.in", "r", stdin);
	cin >> T;
	while (T--) {
		cin >> s;
		cin >> na;
		for (int i = 1; i <= na; ++i) {
			cin >> la[i] >> ra[i];
			str[i] = s.substr(la[i]-1, ra[i]-la[i]+1);
			D_ cout << str[i] << endl;
		}
		cin >> nb;
		for (int i = na+1; i <= na+nb; ++i) {
			cin >> lb[i] >> rb[i];
			str[i] = s.substr(lb[i]-1, rb[i]-lb[i]+1);
			D_ cout << str[i] << endl;
		}
		cin >> m;
		int u, v;
		for (int i = 1; i <= m; ++i) {
			cin >> u >> v;
			connect(v+na, u, str[u].size());
			D_ cout << v+na << ' ' << u << endl;
		}
		for (int i = 1; i <= na; ++i) {
			for (int j = na+1; j <= na+nb; ++j) {
				if (str[i].substr(0, str[j].size()) == str[j]) {
					connect(i, j, 0);
					D_ cout << i << ' ' << j << endl;
				}
			}
		}
		dp();
		clear();
	}
}

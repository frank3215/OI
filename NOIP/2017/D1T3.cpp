#include <bits/stdc++.h>
#define debug //fflush(stdout),printf
using namespace std;

const int maxn = 1e5+5, maxm = 2e5+5, maxk = 55;

int t;
int n, m, k, p;
int ans[maxn][maxk];
long long *dis2;

inline int& MOD(int &x) { return x%=p; }

struct graph{
	int head[maxn], nxt[maxm], to[maxm], w[maxm], tot;
	long long dis[maxn];
	vector<int> top;
	void clear() {
		memset(head, 0, sizeof(head));
		tot = 0;
	}
	void add(int a, int b, int c) {
		debug("%d %d %d\n", a, b, c);
		++tot;
		nxt[tot] = head[a];
		to[tot] = b;
		w[tot] = c;
		head[a] = tot;
	}
	void dijk(int s) {
		typedef pair<long long, int> pr;
		memset(dis, 0x3f, sizeof(dis));
		priority_queue<pr, vector<pr>, greater<pr> > q;
		q.push(make_pair(dis[s]=0, s));
		while (!q.empty()) {
			pr p = q.top(); int u = p.second; q.pop();
			if (dis[u] < p.first) continue;
			for (int e = head[u]; e; e = nxt[e]) {
				int v = to[e];
				if (dis[u] + w[e] < dis[v]) {
					q.push(make_pair(dis[v]=dis[u]+w[e], v));
				}
			}
		}
	}
	int dfs(int u, int l) {
		debug(" %d %d %lld %d\n", u, l, dis[u], dis2[u]);
		if (dis[u]+l+dis2[u] > dis[n]+k) return 0;
		if (ans[u][l] == -2) return -1;
		if (~ans[u][l]) return ans[u][l];
		ans[u][l] = -2;
		int res = (u==n);
		for (int e = head[u]; e; e=nxt[e]) {
			int v = to[e], t = dis[u]+l+w[e]-dis[v];
			int tmp = dfs(v, t);
			if (tmp == -1) return -1;
			MOD(res += tmp);
		}
		return ans[u][l]=res;
	}
}g, h;

void solve() {
	scanf("%d%d%d%d", &n, &m, &k, &p);
	g.clear();
	h.clear();
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		g.add(a, b, c);
		h.add(b, a, c);
	}
	g.dijk(1);
	h.dijk(n);
	dis2 = h.dis;
	memset(ans, -1, sizeof(ans));
	printf("%d\n", g.dfs(1, 0));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		debug(" %d\n", t);
		solve();
	}
}

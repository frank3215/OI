#include <bits/stdc++.h>
using namespace std;

const int maxn = 110, maxm = 1010, inf = 1e6;

int n, m;
int x[maxn];
int head[maxn], nxt[maxm<<1], to[maxm<<1], len[maxm<<1], tot;
int dis[maxn], vis[maxn];
set<pair<int,int> > s, t;

void add(int u, int v) {
	++tot;
	nxt[tot] = head[u];
	to[tot] = v;
	len[tot] = -1;
	head[u] = tot;
}
void solve() {
	cin >> n >> m;
	tot = 1;
	memset(head, 0, sizeof(head));
	for (int i = 2; i <= n; ++i) {
		cin >> x[i];
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[1] = 0; vis[1] = 2;
	for (int e = head[1]; e; e = nxt[e]) {
		int v = to[e];
		//printf("(%d)", v);
		if (vis[v]) continue;
		vis[v] = 1;
		if (x[v] > 0) t.insert(make_pair(x[v], v));
		else s.insert(make_pair(-x[v], v));
	}
	int num = 1, curdis = 0, prevnum;
	while ((!t.empty()) || (!s.empty())) {
		prevnum = num;
		//printf("n=%d d=%d\n", num, curdis);
		//if (!s.empty()) printf("s: %d %d\n", s.begin()->first, s.begin()->second);
		if (!s.empty() && s.begin()->first == num) {
			if (s.begin()->first == num) ++curdis;
			int nxtnum = num;
			while (!s.empty() && s.begin()->first == num) {
				++nxtnum;
				int u = s.begin()->second;
				//printf("[%d]", u);
				dis[u] = curdis;
				vis[u] = 2;
				for (int e = head[u]; e; e = nxt[e]) {
					int v = to[e];
					if (vis[v] == 2) {
						if (dis[u] > dis[v])
							len[e] = len[e^1] = dis[u]-dis[v];
						else len[e] = len[e^1] = inf;
					} else if (vis[v] == 0) {
						vis[v] = 1;
						if (x[v] > 0) t.insert(make_pair(x[v], v));
						else s.insert(make_pair(-x[v], v));
					}
				}
				s.erase(s.begin());
			}
			num = nxtnum;
		} else if (!t.empty()) {
			assert(curdis <= t.begin()->first);
			curdis = t.begin()->first;
			while (!t.empty() && t.begin()->first == curdis) {
				++num;
				int u = t.begin()->second;
				dis[u] = curdis;
				vis[u] = 2;
				for (int e = head[u]; e; e = nxt[e]) {
					int v = to[e];
					if (vis[v] == 2) {
						len[e] = len[e^1] = dis[u]-dis[v]?dis[u]-dis[v]:1;
					} else if (vis[v] == 0) {
						vis[v] = 1;
						if (x[v] > 0) t.insert(make_pair(x[v], v));
						else s.insert(make_pair(-x[v], v));
					}
				}
				t.erase(t.begin());
			}
		}
	}
	for (int i = 1; i <= m; ++i) {
		printf("%d%c", len[i<<1], " \n"[i==m]);
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
}

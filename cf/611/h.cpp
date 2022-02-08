#include <bits/stdc++.h>
#define print printf
using namespace std;

const int maxn = 2e5+10, maxm = 8, inf = 1e9;

int n, deg[maxm], cnt[maxm][maxm];
int m, node[maxm];

int vis[maxm];
struct tree{
	vector<int> to[maxm];
	void clear() {
		for (int i = 0; i < maxm; ++i)
			to[i].clear();
	}
	void add(int u, int v) { to[u].push_back(v); }
	void add2(int u, int v) { add(u, v), add(v, u); }
	int dfs(int u) {
		if (vis[u] == 1) return 0;
		int ret = 1;
		vis[u] = 1;
		for (int v: to[u]) ret += dfs(v);
//		printf("%d %d\n", u, ret);
		return ret;
	}
}t;

namespace dinic{
	const int maxn = 100, maxm = 200;
	struct flow{
		int head[maxn], nxt[maxm], to[maxm], f[maxm], tot;
		int cur[maxn], dep[maxn];
		void clear() {
			tot = 1;
			memset(head, 0, sizeof(head));
		}
		void _add(int u, int v, int w) {
			++tot;
			assert(u < maxn && v < maxn && tot < maxm);
			nxt[tot] = head[u];
			to[tot] = v;
			f[tot] = w;
			head[u] = tot;
		}
		int add(int u, int v, int w) {
			assert(w >= 0);
//			print("edge: %d %d %d\n", u, v, w);
			_add(u, v, w), _add(v, u, 0);
			return tot;
		}
		bool bfs(int s, int t) {
			queue<int> q;
			q.push(s);
			memset(dep, -1, sizeof(dep));
			dep[s] = 0;
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (int e = head[u]; e; e = nxt[e]) {
					if (!f[e]) continue;
					int v = to[e];
					if (dep[v] == -1) {
						dep[v] = dep[u]+1;
						q.push(v);
					}
				}
			}
			return dep[t] != -1;
		}
		int dfs(int u, int t, int rest = inf) {
			assert(rest != 0);
			if (u == t) return rest;
			int ret = 0;
			for (int &e = cur[u]; e; e = nxt[e]) {
				if (!f[e]) continue;
				int v = to[e];
				if (dep[v] == dep[u]+1) {
					int tmp = dfs(v, t, min(rest, f[e]));
					rest -= tmp;
					f[e] -= tmp;
					ret += tmp;
					f[e^1] += tmp;
				}
				if (!rest) return ret;
			}
			return ret;
		}
		int dinic(int s, int t) {
			assert(s != t);
			int ans = 0;
			while (bfs(s,t)) {
				memcpy(cur, head, sizeof(cur));
				ans += dfs(s,t);
			}
			return ans;
		}
	}f;
}

vector<pair<int,int> > edges;

using dinic::f;
int tmp[maxm][maxm*maxm];
bool check(int mask) {
//	printf("{%d}\n", mask);
	f.clear();
	int tot = n-m;
	for (int i = 1; i <= m; ++i) {
		int c = deg[i]-1-cnt[i][i];
		tot -= cnt[i][i];
		if (c < 0) return false;
		f.add(1, 2+i, c);
	}
	for (int i = 0; i < (int)edges.size(); ++i) {
		int a = edges[i].first, b = edges[i].second, c = cnt[a][b];
//		printf("%d: %d %d %d\n", i, a, b, c);
		c -= (mask>>i&1);
		if (c < 0) return false;
		tmp[a][i] = f.add(a+2, i+m+3, inf);
		tmp[b][i] = f.add(b+2, i+m+3, inf);
		f.add(i+m+3, 2, c);
	}
	int tmp = f.dinic(1, 2);
//	printf("%d\n", tmp);
	return tmp == tot;
}

int cur[maxm];
void getans(int mask) {
	for (int i = 1, j = 1; j <= m; i *= 10, ++j) {
		node[j] = cur[j] = i;
	}
	node[m+1] = n+1;
	for (int i = 1; i <= m; ++i) {
		for (int k = 1; k <= cnt[i][i]; ++k) {
			++cur[i];
			assert(cur[i] < node[i+1]);
			printf("%d %d\n", node[i], cur[i]);
		}
	}
	for (int i = 0; i < (int)edges.size(); ++i) {
		int a = edges[i].first, b = edges[i].second;
		if (mask>>i&1) {
			printf("%d %d\n", node[a], node[b]);
		}
		for (int j = 1; j <= f.f[tmp[a][i]]; ++j) {
			++cur[a];
			assert(cur[a] < node[a+1]);
			printf("%d %d\n", cur[a], node[b]);
		}
		for (int j = 1; j <= f.f[tmp[b][i]]; ++j) {
			++cur[b];
			assert(cur[b] < node[b+1]);
			printf("%d %d\n", cur[b], node[a]);
		}
	}
}

bool solve() {
	for (int i = 0; i < (1 << (int)edges.size()); ++i) {
		int pop = 0;
		for (int j = 0; j < (int)edges.size(); ++j)
			pop += i>>j&1;
		if (pop != m-1) continue;
		t.clear();
		for (int j = 0; j < (int)edges.size(); ++j)
			if (i>>j&1) {
				t.add2(edges[j].first, edges[j].second);
			}
		memset(vis, 0, sizeof(vis));
		if (t.dfs(1) == m && check(i)) {
			getans(i);
			return true;
		}
	}
	return false;
}


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i*=10) {
		++m;
		deg[m] = min(10*i-1, n)-i+1;
	}
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j < i; ++j)
			edges.push_back(make_pair(j, i));
	char s[maxm], t[maxm];
	for (int i = 0; i < n-1; ++i) {
		scanf("%s%s", s, t);
		int a = strlen(s), b = strlen(t);
		if (a > b) swap(a, b);
		cnt[a][b]++;
	}
	if (!solve()) puts("-1");
}

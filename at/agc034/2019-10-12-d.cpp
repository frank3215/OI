#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 10, maxn = 1e5;

int ans;

namespace MCMF{
	int head[maxn], nxt[maxn], to[maxn], c[maxn], r[maxn], tot = 1;
	void add(int u, int v, int w, int f) {
		++tot;
		nxt[tot] = head[u];
		to[tot] = v;
		c[tot] = w;
		r[tot] = f;
		head[u] = tot;
	}
	void add2(int u, int v, int w, int f) {
		add(u,v,w,f), add(v,u,-w,0);
	}
#define mp make_pair
	typedef pair<long long, int> qnode;
	int dis[maxn], inq[maxn], pre[maxn];
	void spfa(int s) {
		memset(dis, 0x3f, sizeof(dis));
		memset(pre, 0, sizeof(pre));
		queue<int> q;
		dis[s] = 0;
		q.push(s);
		while (!q.empty()) {
			int u = q.front();
			q.pop(); inq[u] = 0;
			for (int e = head[u]; e; e = nxt[e]) {
				if (!r[e]) continue;
				int v = to[e], w = c[e];
				if (dis[u]+w < dis[v]) {
					pre[v] = e;
					dis[v] = dis[u]+w;
					if (!inq[v]) {
						q.push(v);
						inq[v] = 1;
					}
				}
			}
		}
	}
	void augment(int t) {
		int flow = inf;
		for (int e = pre[t]; e; e = pre[to[e^1]]) {
			flow = min(flow, r[e]);
		}
		for (int e = pre[t]; e; e = pre[to[e^1]]) {
			r[e] -= flow;
			r[e^1] += flow;
		}
		ans += flow*dis[t];
	}
}
using namespace MCMF;


int n, rx[maxn], ry[maxn], rc[maxn], bx[maxn], by[maxn], bc[maxn];
signed main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> rx[i] >> ry[i] >> rc[i];
		add2(1, i+10, 0, rc[i]);
		add2(i+10, 3, rx[i]+ry[i], inf);
		add2(i+10, 4, rx[i]-ry[i], inf);
		add2(i+10, 5, -rx[i]+ry[i], inf);
		add2(i+10, 6, -rx[i]-ry[i], inf);
	}
	for (int i = n; i < 2*n; ++i) {
		cin >> bx[i] >> by[i] >> bc[i];
		add2(3, i+10, -bx[i]-by[i], inf);
		add2(4, i+10, -bx[i]+by[i], inf);
		add2(5, i+10, bx[i]-by[i], inf);
		add2(6, i+10, bx[i]+by[i], inf);
		add2(i+10, 2, 0, bc[i]);
	}
	while (spfa(1), pre[2]) augment(2);
	cout << -ans;
}

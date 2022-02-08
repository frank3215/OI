#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;

const int maxn = 40, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, inf = 0x3f3f3f3f;
typedef pair<int, int> pos;
typedef pair<pos, pos> ppp;

int b[maxn][maxn], v[maxn][maxn][maxn][maxn];
int n, m, q;
int ex, ey, sx, sy, tx, ty;

namespace brute{
	int solve() {
		memset(v, -1, sizeof(v));
		queue<ppp> q;
		q.push(mp(mp(sx, sy), mp(ex, ey)));
		v[sx][sy][ex][ey] = 0;
		while (!q.empty()) {
			ppp p = q.front(); q.pop();
			sx=p.fi.fi, sy=p.fi.se, ex=p.se.fi, ey=p.se.se;
			int cur = v[sx][sy][ex][ey];
//			printf("%d %d %d %d: %d\n", sx, sy, ex, ey, cur);
			if (sx == tx && sy == ty) return cur;
			for (int i = 0; i < 4; ++i) {
				int nx = ex+dx[i], ny = ey+dy[i];
				if (nx == sx && ny == sy) {
					if (v[ex][ey][sx][sy] == -1) {
						q.push(mp(mp(ex, ey), mp(sx, sy)));
						v[ex][ey][sx][sy] = cur+1;
					}
				}
				else if (b[nx][ny] && v[sx][sy][nx][ny] == -1) {
					q.push(mp(mp(sx, sy), mp(nx, ny)));
					v[sx][sy][nx][ny] = cur+1;
				}
			}
		}
		return -1;
	}
}

namespace ans{
	const int maxm = maxn*maxn<<4;
	int ch(int x, int y) { return x*maxn+y; }
	int ch(int x, int y, int d) { return d*maxn*maxn+x*maxn+y; }
	struct graph{
		int head[maxm], nxt[maxm], to[maxm], w[maxm], tot;
		int dis[maxm], inq[maxm];
		void clear() {
			memset(head, 0, sizeof(head));
			tot = 0;
		}
		void add(int s, int t, int u=1) {
			++tot;
			nxt[tot] = head[s];
			to[tot] = t;
			w[tot] = u;
			head[s] = tot;
		}
		void spfa(int s) {
			memset(dis, 0x3f, sizeof(dis));
			memset(inq, 0, sizeof(inq));
			queue<int> q;
			q.push(s);
			dis[s] = 0;
			while (!q.empty()) {
				s = q.front(); q.pop();
				inq[s] = 0;
				for (int e = head[s]; e; e = nxt[e]) {
					int t = to[e];
					if (dis[t] > dis[s]+w[e]) {
						dis[t] = dis[s]+w[e];
						if (!inq[t]) {
							q.push(t);
							inq[t] = 1;
						}
					}
				}
			}
		}
	}g, h;
	void init(int nx, int ny) {
		assert(b[nx][ny]);
		g.clear();
		b[nx][ny] = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) if (b[i][j]) {
				for (int k = 0; k < 4; ++k) {
					int x = i+dx[k], y = j+dy[k];
					if (b[x][y]) g.add(ch(i, j), ch(x, y));
				}
			}
		b[nx][ny] = 1;
	}
	void init() {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) if (b[i][j]) {
				init(i, j);
				for (int k = 0; k < 4; ++k) {
					int x = i+dx[k], y = j+dy[k];
					if (!b[x][y]) continue;
					g.spfa(ch(x,y));
					for (int l = 0; l < 4; ++l) {
						if (l != k) {
							int nx = i+dx[l], ny = j+dy[l];
//							printf("%d %d %d->%d: %d\n", i, j, k, l, g.dis[ch(nx,ny)]);
							h.add(ch(i,j,k), ch(i,j,l), g.dis[ch(nx,ny)]);
						}
						else {
//							printf("%d %d %d->%d %d %d: %d\n", i, j, k, x, y, k^1, 1);
							h.add(ch(i,j,k), ch(x,y,k^1), 1);
						}
					}
				}
			}
		}
	}
	int solve() {
		if (sx == tx && sy == ty) return 0;
		init(sx, sy);
		g.spfa(ch(ex,ey));
		int _tot = h.tot;
		for (int i = 0; i < 4; ++i) {
			int x = sx+dx[i], y = sy+dy[i];
			h.add(1, ch(sx,sy,i), g.dis[ch(x,y)]);
//			printf("0 -> %d %d %d: %d\n", sx, sy, i, g.dis[ch(x,y)]);
		}
		h.spfa(1);
		h.head[1] = 0;
		h.tot = _tot;
		int ans = inf;
		for (int i = 0; i < 4; ++i) {
			ans = min(ans, h.dis[ch(tx,ty,i)]);
//			printf("-> %d %d %d: %d\n", tx, ty, i, h.dis[ch(tx,ty,i)]);
		}
		return ans==inf?-1:ans;
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &b[i][j]);
	ans::init();
	while (q--) {
		scanf("%d%d%d%d%d%d", &ex, &ey, &sx, &sy, &tx, &ty);
		printf("%d\n", ans::solve());
	}
}

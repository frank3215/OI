#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10, maxt = maxn<<1;

namespace {
	int n, na, nb;
	int la[maxn], ra[maxn], lb[maxn], rb[maxn];
	char s[maxn];
	int m;

	const int maxN = maxt+maxn<<1, maxM = maxt+maxn+maxm<<1;
	struct graph{
		int head[maxt], nxt[maxt], to[maxt], tot;
		void clear(int n) {
			memset(head, 0, n*sizeof(int));
		}
		void add(int x, int y) { nxt[++tot] = head[x], to[tot] = y, head[x] = tot; }
	}g;

	namespace sam{
		int len[maxn], link[maxn][maxlogn];
		int ch[maxn][26];
		int end[maxn];
		int cnt, last;

		void init() {
			for (int i = 0; i <= cnt; ++i) {
				len[i] = 0, link[i] = -1;
				memset(ch[i], -1, sizeof(ch[i]);
			}
			cnt = last = 0;
			t[0].link = -1;
		}

		void extend(int x) {
			int p, cur = ++cnt; len[cur] = len[last]+1
			end[len[cur]] = cur;
			for (p = last; p != -1 && ch[p][x] == -1; p = link[p][0]) {
				ch[p][x] = cur;
			}
			if (p == -1) {
				link[last][0] = 0;
			} else {
				int q = ch[p][x];
				if (len[q] == len[p]+1) {
					link[cur] = q;
				} else {
					int clone = ++cnt;
					len[clone] = len[p]+1;
					for (int i = p; i != -1 && ch[i][p] == q; i = link[i][0]) {
						ch[i][x] = clone;
					}
					t[q].link = t[cur].link = clone;
				}
			}
			last = cur;
		}
		void dfs(int u = 0) {
			for (int i = 1; i < maxlogn; ++i) {
				link[u][i] = link[u][i-1]==-1?-1:link[link[u][i-1]][i-1];
			}
			for (int i = 0; i < son[u].size(); ++i) {
				dfs(son[u][i]);
			}
		}

		void process() {
			for (int i = 0; i <= cnt; ++i) {
				g.head[i] = -1;
			}
			for (int i = 1; i <= cnt; ++i) {
				g.add(link[i][0], i);
			}
			dfs();
		}

		int find(int r, int len) {
			int ret = end[r];
			while (link[r] != -1 && len[link[r]] >= len) r = link[r];
			return ret;
		}
	}

	void sa_tree() {
		tot = 0;
		for (int i = 0; i <= cnt; ++i) {
			head[i] = -1;
			memset(link[i], -1, sizeof(link[i]));
		}
		g.clear(s.cnt);
		s.init();
		for (int i = n-1; ~i; --i) {
			s.extend(s[i]-'a');
		}
		s.process();
	}
	
	void make_graph() {
	}

	void solve() {
		scanf("%s", s+1);
		n = strlen(s+1);
		sa_tree();
		scanf("%d", &na);
		for (int i = 0; i < na; ++i) {
			scanf("%d%d", la+i, ra+i);
			a[i] = find(ra[i], ra[i]-la[i]+1);
		}
		scanf("%d", &nb);
		for (int i = 0; i < nb; ++i) {
			scanf("%d%d", lb+i, rb+i);
			b[i] = find(rb[i], rb[i]-lb[i]+1);
		}
		make_graph();
		scanf("%d", &m);
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
		}
	}
}

int main() {
	memset(nxt, -1, sizeof(nxt));
	memset(link, -1, sizeof(link));
	int t;
	scanf("%d", &t);
	while (t--) solve();
}


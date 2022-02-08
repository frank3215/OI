#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int maxn = 5e5+10;

int n, m;
vector<pair<int,int> > g[maxn], e;
vector<int> loop[maxn];
int F[maxn], f[maxn];
int mn[maxn], id[maxn], pos[maxn], cnt;
int vis[maxn], st[maxn], top;

void dfs(int u, int f) {
	vis[u] = top;
	for (auto p : g[u]) {
		if (p.fi == f) continue;
		st[top++] = p.se;
		if (vis[p.fi] != -1) {
			++cnt;
			mn[cnt] = m;
			ROF(j,vis[p.fi],top) {
				id[st[j]] = cnt;
				pos[st[j]] = loop[cnt].size();
				mn[cnt] = min(mn[cnt], st[j]);
				loop[cnt].pb(st[j]);
			}
		} else dfs(p.fi, u);
		--top;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int u, v;
	F0R(i,m) {
		scanf("%d%d", &u, &v);
		--u, --v;
		g[u].pb(mp(v,i));
		g[v].pb(mp(u,i));
		e.pb(mp(u,v));
	}
	memset(vis, -1, sizeof(vis));
	memset(mn, 0x3f, sizeof(mn));
	dfs(0, 0);
	F0R(i,n) f[i] = 1;
	R0F(i,m) {
		F[i] = f[e[i].fi]+f[e[i].se];
		if (id[i] && i == mn[id[i]]) {
#define cur loop[id[i]]
			int siz = cur.size();
			int s = pos[i], t = pos[i];
			while (cur[(s+1)%siz] > cur[s]) s = (s+1)%siz;
			while (cur[(t+siz-1)%siz] > cur[t]) t = (t+siz-1)%siz;
			if (s == t) F[i] -= F[cur[s]];
#undef cur
		}
		f[e[i].fi] = f[e[i].se] = F[i];
	}
	F0R(i,n) printf("%d ", f[i]-1); puts("");
}

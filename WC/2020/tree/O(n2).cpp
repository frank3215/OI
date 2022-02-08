#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define mp make_pair
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

const int N = 5e5+10;

int n;
int head[N], nxt[N<<1], to[N<<1], tot;

int cnt, st[N], val[N];

//Sorted List
int l[N], r[N], a[N];
void init() {
	l[0] = 0;
	r[0] = n-1;
	FOR(i,1,n+1) l[i] = 0, r[i] = -1;
}
void add(int x) {
	assert(x < n && l[x] <= r[x]);
	a[l[x]++]++;
	if (l[x+1] <= r[x+1]) {
		r[x+1]++;
	} else {
		l[x+1] = r[x+1] = l[x]-1;
	}
}
void sub(int x) {
	assert(x && l[x] <= r[x]);
	a[r[x]--]--;
	if (l[x-1] <= r[x-1]) {
		l[x-1]--;
	} else {
		l[x-1] = r[x-1] = r[x]+1;
	}
}
void erase(int x) { ROF(i,1,x+1) sub(i); }
void insert(int x) { FOR(i,0,x) add(i); }

void add(int u, int v) { nxt[++tot] = head[u], to[tot] = v, head[u] = tot; }
#define trav(u,e,v) for (int e = head[u], v; e && (v = to[e], 1); e = nxt[e])

int in[N], out[N], tim;

void dfs(int u, int f) {
	in[u] = ++tim;
	val[u] = st[u];
	trav(u,e,v) {
		if (v == f) continue;
		dfs(v,u);
	}
	out[u] = tim;
}

int solve() {
	int ret = n;
//	debug(cnt);
	FOR(i,0,cnt) {
		ret = min(ret, max(i+1, a[i+1]));
	}
	return ret;
}

signed main() {
#ifndef STDIO
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
	scanf("%d", &n);
	FOR(i,0,n-1) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	dfs(1,0);
	int q;
	scanf("%d", &q);
	init();
	while (q--) {
		int t, v;
		scanf("%d%d", &t, &v);
		if (t == 1) {
			cnt++; st[v] = val[v] = 1;
			FOR(i,1,n+1) if (i != v && st[i]) {
				if (in[i] <= in[v] && in[v] <= out[i]) {
					add(val[i]++);
				}
				val[v] += in[v] <= in[i] && in[i] <= out[v];
			}
			insert(val[v]);
		} else {
			cnt--; st[v] = 0;
			erase(val[v]); val[v] = 0;
			FOR(i,1,n+1) if (i != v && st[i]) {
				if (in[i] <= in[v] && in[v] <= out[i]) {
					sub(val[i]--);
				}
			}
		}
		printf("%d\n", solve());
	}
}

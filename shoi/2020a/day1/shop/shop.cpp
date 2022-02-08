#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,b,a) for (int i = (b-1); i >= a; --i)
using namespace std;

const int L = 64, N = 1010, V = 1e6, inf = 1e18;

typedef unsigned int ull;

int n, m;
ull c[N];
int v[N], a[L], b[L];

ull xxj[L];

int q[N], nq[N], ans[N];

const int M = N*128+N;
int head[N], to[M<<1], nxt[M<<1], cap[M<<1], tot;
void _add(int u, int v, int w) {
	nxt[tot] = head[u];
	to[tot] = v;
	cap[tot] = w;
	head[u] = tot;
	++tot;
}
void add(int u, int v, int w) {
	_add(u,v,w);
	_add(v,u,0);
}

#define trav(u,e,v,w) for (int e = head[u], v, w; ~e && (v = to[e], w = cap[e], 1); e = nxt[e])

int s, t;
int d[N], cur[N];
bool bfs(int ql, int qr) {
	FOR(i,ql,qr) { d[q[i]] = -1; cur[q[i]] = head[q[i]]; }
	cur[s] = head[s];
	queue<int> qu;
	qu.push(s); d[s] = 0;
	d[t] = -1;
	while (!qu.empty()) {
		int u = qu.front(); qu.pop();
		trav(u,e,v,w) if (w) {
			if (d[v] == -1) { d[v] = d[u]+1; qu.push(v); }
		}
	}
	return d[t] != -1;
}
#define Trav(u,e,v,w) for (int &e = cur[u], v, w; ~e && (v = to[e], w = cap[e], 1); e = nxt[e])
int dfs(int u, int fl) {
	if (u == t) return fl;
	int ret = 0;
	Trav(u,e,v,w) {
		if (w && d[v] == d[u]+1) {
			int tmp = dfs(v, min(fl, w));
			cap[e] -= tmp;
			fl -= tmp;
			cap[e^1] += tmp;
			ret += tmp;
		}
		if (!fl) break;
	}
	return ret;
}

void flow(int ql, int qr) {
	int ret = 0;
	while (bfs(ql, qr)) {
		ret += dfs(s, inf);
	}
}

int bel[N];
void getcut(int ql, int qr) {
	FOR(i,ql,qr) { d[q[i]] = 0; bel[q[i]] = 1; }
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		trav(u,e,v,w) {
			if (w && !d[v]) { d[v] = 1; bel[v] = 0; q.push(v); }
		}
	}
}

void in(int *a, bool type) {
	FOR(i,0,m) scanf("%lld", a+i), a[i]--;
	FOR(i,0,m) {
		memset(xxj, 0, sizeof(xxj));
		FOR(j,0,m) if (j != i) {
			ull cur = c[a[j]];
			ROF(k,L,0) {
				if ((cur>>k)&1) {
					cur ^= xxj[k];
					if (!xxj[k]) { xxj[k] = cur; break; }
				}
			}
		}
		FOR(j,0,n) if (j != a[i]) {
			ull cur = c[j];
			ROF(k,L,0) {
				if ((cur>>k)&1) cur ^= xxj[k];
			}
			if (cur){
				if (!type) add(a[i], j, inf);
				else add(j, a[i], inf);
			}
		}
	}
}

inline int pf(int x) { return x*x; }

void solve(int l, int r, int ql, int qr) {
	if (ql == qr) return;
	if (r-l == 1) {
		FOR(i,ql,qr) ans[q[i]] = l;
		return;
	}
	int m = (l+r)>>1;
	s = n, t = n+1;
	head[s] = -1;
	head[t] = -1;
	int oldtot = tot;
	FOR(i,ql,qr) {
		int v1 = pf(v[q[i]]-(m-1)), v2 = pf(v[q[i]]-m);
		if (v1 < v2) add(q[i], t, v2-v1);
		else if (v1 > v2) add(s, q[i], v1-v2);
	}
	flow(ql, qr);
	getcut(ql, qr);
	FOR(i,ql,qr) {
		int u = q[i], *pre = &head[u];
		trav(u,e,v,w) {
			if (ans[v] != ans[u] || e >= oldtot) {
				*pre = nxt[e];
			} else {
				cap[e] = e&1?0:inf;
				pre = &nxt[e];
			}
		}
	}
	int pl = ql;
	FOR(i,ql,qr) if (bel[q[i]] == 1) nq[pl++] = q[i];
	int pr = pl;
	FOR(i,ql,qr) if (bel[q[i]] == 0) nq[pr++] = q[i];
	assert(pr == qr);
	tot = oldtot;
	FOR(i,ql,qr) q[i] = nq[i];
	solve(l, m, ql, pl);
	solve(m, r, pl, pr);
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("shop.in", "r", stdin);
	freopen("shop.out", "w", stdout);
#endif
	memset(head, -1, sizeof(head));

	scanf("%lld%lld", &n, &m);
	FOR(i,0,n) scanf("%llu", c+i);
	FOR(i,0,n) scanf("%lld", v+i);
	in(a, 0), in(b, 1);
	FOR(i,0,n) q[i] = i;
	solve(0, V, 0, n);
	int Ans = 0;
	FOR(i,0,n) {
		Ans += pf(v[i]-ans[i]);
	}
	printf("%lld\n", Ans);
}

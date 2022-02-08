#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define mp make_pair
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

const int N = 5e5+10;

int n, q, t[N], v[N];
int head[N], nxt[N<<1], to[N<<1], deg[N], tot;

int cnt, st[N], val[N];

//Sorted List
int l[N], r[N], a[N];
void init() {
	l[0] = 0;
	r[0] = n-1;
	FOR(i,1,n+1) l[i] = 0, r[i] = -1;
}
void add(int x) {
	a[l[x]++]++;
	if (l[x+1] <= r[x+1]) {
		r[x+1]++;
	} else {
		l[x+1] = r[x+1] = l[x]-1;
	}
}
void sub(int x) {
	a[r[x]--]--;
	if (l[x-1] <= r[x-1]) {
		l[x-1]--;
	} else {
		l[x-1] = r[x-1] = r[x]+1;
	}
}
void erase(int x) { ROF(i,1,x+1) sub(i); }
void insert(int x) { FOR(i,0,x) add(i); }

//Chain
int beg, L[N], R[N], ed;

void _add(int u, int v) { deg[u]++, nxt[++tot] = head[u], to[tot] = v, head[u] = tot; }
void add(int u, int v) { _add(u, v), _add(v, u); }
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
	if (!cnt) return 0;
	int ret = n;
	FOR(i,0,cnt) {
		ret = min(ret, max(i+1, a[i+1]));
	}
	return ret;
}

void solve_1_6() {
	dfs(1,0);
	init();
	FOR(i,0,q) {
		int v = ::v[i], t = ::t[i];
		if (t == 1) {
			cnt++; st[v] = val[v] = 1;
			if (!beg) beg = ed = v;
			else R[ed] = v, L[v] = ed, ed = v;
			for (int i = beg; i; i = R[i]) if (i != v) {
				if (in[i] <= in[v] && in[v] <= out[i]) {
					add(val[i]++);
				}
				val[v] += in[v] <= in[i] && in[i] <= out[v];
			}
			insert(val[v]);
		} else {
			cnt--; st[v] = 0;
			erase(val[v]); val[v] = 0;
			if (beg == v) beg = R[v];
			if (ed == v) ed = L[v];
			R[L[v]] = R[v]; L[R[v]] = L[v];
			L[v] = R[v] = 0;
			for (int i = beg; i; i = R[i]) if (i != v) {
				if (in[i] <= in[v] && in[v] <= out[i]) {
					sub(val[i]--);
				}
			}
		}
		printf("%d\n", solve());
	}
}

void solve_7_8() {
	FOR(i,0,q) {
		int t = ::t[i], v = ::v[i];
		if (t == 1) {
			cnt++;
			st[v] = 1;
		} else {
			cnt--;
			st[v] = 0;
		}
		printf("%d\n", (cnt+1)/2);
	}
}

bool check_C(int u, int f) {
	if (f > u) return false;
	trav(u,e,v) {
		if (v == f) continue;
		if (!check_C(v, u)) return false;
	}
	return true;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
	scanf("%d", &n);
	FOR(i,0,n-1) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > y) swap(x, y);
		add(x, y);
	}
	bool B = deg[1] == 1;
	FOR(i,2,n+1) B &= deg[i] <= 2;
	scanf("%d", &q);
	bool C = q == n;
	FOR(i,0,q) {
		scanf("%d%d", t+i, v+i);
		C &= v[i] == i+1;
	}
	if (B) solve_7_8();
	else solve_1_6();
}

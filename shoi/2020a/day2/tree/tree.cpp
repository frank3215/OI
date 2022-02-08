#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int N = 6e5, L = 22, T = (L+1)*N;

int n, v[N], p[N];
int cnt[T], ch[T][2], rt[N], pop[N][L][2], tot = 1;
long long ans;

void insert(int i, int v) {
	if (!rt[i]) rt[i] = ++tot;
	int u = rt[i]; cnt[u]++;
	FOR(j,0,L) {
		int &cur = ch[u][(v>>j)&1];
		pop[i][j][(v>>j)&1]++;
		if (!cur) cur = ++tot;
		u = cur; cnt[u]++;
	}
}

void add(int i) {
	int u = rt[i];
	FOR(j,0,L) {
		swap(ch[u][0], ch[u][1]);
		pop[i][j][0] += cnt[ch[u][1]] - cnt[ch[u][0]];
		pop[i][j][1] += cnt[ch[u][0]] - cnt[ch[u][1]];
		u = ch[u][0];
		if (!u) break;
	}
}

int merge(int u, int v) {
	if (!u || !v) return u+v;
	cnt[u] += cnt[v];
	FOR(i,0,2) ch[u][i] = merge(ch[u][i], ch[v][i]);
	return u;
}

void Merge(int i, int j) {
	FOR(k,0,L) FOR(l,0,2) pop[i][k][l] += pop[j][k][l];
	rt[i] = merge(rt[i], rt[j]);
}
/*
void tdfs(int u, int v, int dep) {
	if (!u) return;
	printf("\t %d(%d:%d,%d)\n", u, cnt[u], ch[u][0], ch[u][1]);
	if (dep == L) printf(" %d\n", v);
	FOR(i,0,2) tdfs(ch[u][i], v<<1|i, dep+1);
}

void print(int i) {
	printf("pop[%d]:\n", i);
	FOR(j,0,L) FOR(k,0,2) printf(" pop[%d][%d][%d] = %d\n", i, j, k, pop[i][j][k]);
	printf("trie[%d]:\n", i);
	tdfs(rt[i],0,0);
}*/

int head[N], nxt[N<<1], to[N<<1], tou;
void add(int u, int v) { nxt[++tou] = head[u]; to[tou] = v; head[u] = tou; }

void dfs(int u) {
	for (int e = head[u]; e; e = nxt[e]) {
		int v = to[e];
		dfs(v);
		add(v);
		//print(v);
		Merge(u, v);
	}
	int cur = 0;
	FOR(i,0,L) cur += (pop[u][i][1]&1)<<i;
	//printf("%d: %d %d\n", u, cur, cnt[rt[u]]);
	ans += cur;
}

signed main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &n);
	FOR(i,1,n+1) {
		scanf("%d", v+i);
		insert(i, v[i]);
	}
	FOR(i,2,n+1) {
		scanf("%d", p+i);
		add(p[i], i);
	}
	dfs(1);
	printf("%lld\n", ans);
}


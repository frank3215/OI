#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+10, maxm = 3e5+10;
typedef long long ll;

int n, m;
vector<int> to[maxn];
int dep[maxm], ch[maxm][2], deep[maxm];
ll tag[maxm], val[maxm];
int depth[maxn], heap[maxn];

void init() {
	dep[0] = -1;
}

void modify(int x, ll k) {
	if (!x) return;
	tag[x] += k;
	val[x] += k;
}
void pushdown(int x) {
	modify(ch[x][0], tag[x]), modify(ch[x][1], tag[x]);
	tag[x] = 0;
}
int merge(int x, int y) {
	if (!x || !y) return x+y;
	if (val[x] > val[y]) swap(x, y);
	pushdown(x);
	ch[x][1] = merge(ch[x][1], y);
	if (dep[ch[x][1]] > dep[ch[x][0]]) swap(ch[x][0], ch[x][1]);
	dep[x] = dep[ch[x][1]]+1;
	return x;
}
int pop(int x) {
	pushdown(x);
	return merge(ch[x][0], ch[x][1]);
}

void dfs1(int x, int f) {
	depth[x] = depth[f]+1;
	for (auto y: to[x]) if (y != f) 
		dfs1(y, x);
}

ll dfs2(int x, int f) {
	ll ret = 0;
	for (auto y: to[x]) if (y != f) {
		if (dfs2(y, x) == -1) return -1;
		while (heap[y] && deep[heap[y]] > depth[x])
			heap[y] = pop(heap[y]);
		if (!heap[y]) return -1;
//		printf("%d: %d %d(%d)\n", x, y, val[heap[y]], deep[heap[y]]);
		ret += val[heap[y]];
	}
	modify(heap[x], ret);
	for (auto y: to[x]) if (y != f) {
		modify(heap[y], ret-val[heap[y]]);
		heap[x] = merge(heap[x], heap[y]);
	}
//	printf("%d %lld\n", x, ret);
	return ret;
}

int main() {
	init();
	scanf("%d%d", &n, &m);
	int u, v, c;
	for (int i = 0; i < n-1; ++i) {
		scanf("%d%d", &u, &v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	dfs1(1, 0);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &u, &v, &c);
		val[i] = c;
		deep[i] = depth[v];
		heap[u] = merge(heap[u], i);
	}
	ll ans = dfs2(1, 0);
	printf("%lld\n", ans);
}

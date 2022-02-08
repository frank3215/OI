#include <bits/stdc++.h>
#define NDEBUG
using namespace std;
 
const int maxn = 2e5+10, maxq = 5e5+10;
int n, q, T[maxn], ans[maxq];
string s[maxn];
 
const int maxx = 1e7;
int cnt[maxx];
void modify(int x, int l, int r, int v, int d) {
	cnt[x] += d;
	if (l == r) return;
	int m = l+(r-l)/2;
	if (m >= v) modify(x<<1, l, m, v, d);
	else modify(x<<1|1, m+1, r, v, d);
}
int query(int x, int l, int r, int L, int R) {
	if (!x) return 0;
	if (L <= l && r <= R) return cnt[x];
	int ret = 0, m = l+(r-l)/2;
	if (L <= m) ret += query(x<<1, l, m, L, R);
	if (R > m) ret += query(x<<1|1, m+1, r, L, R);
//	printf("query: %d %d %d %d %d\n", l, r, L, R, ret);
	return ret;
}
 
const int maxt = maxn<<2;
struct sam{
	int len, link;
	int next[27];
	sam() { memset(next, -1, sizeof(next)); }
}st[maxt];
int last, sz, rt[maxt];
void sam_init() {
	last = 0;
	st[last].len = 0;
	st[last].link = -1;
	sz++;
}
void sam_extend(int c, int no) {
	int cur = sz++, p = last;
	st[cur].len = st[last].len+1;
	while (p != -1 && st[p].next[c] == -1) {
		st[p].next[c] = cur;
		p = st[p].link;
	}
	if (p == -1) {
		st[cur].link = 0;
	} else {
		int q = st[p].next[c];
		if (st[q].len == st[p].len+1) {
			st[cur].link = q;
		} else {
			int nq = sz++;
			st[nq] = st[q];
			st[nq].len = st[p].len+1;
			while (p != -1 && st[p].next[c] == q) {
				st[p].next[c] = nq;
				p = st[p].link;
			}
			st[q].link = st[cur].link = nq;
		}
	}
	last = cur;
}
vector<int> son[maxt];
int dfn[maxt], to[maxt], tim;
void dfs(int x) {
	dfn[x] = ++tim;
	for (auto y: son[x]) {
		dfs(y);
	}
	to[x] = tim;
}
int sam_traverse(string &s, bool add) {
	int cur = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		cur = st[cur].next[s[i]-'a'];
		assert(cur != -1);
		if (add) modify(1, 1, tim, dfn[cur], 1);
	}
	return cur;
}
 
struct qquery{
	int id, x, k, r;
	bool operator <(const qquery& q) {
		return r < q.r;
	}
}Q[maxq<<1];
 
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> q;
	sam_init();
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		for (int j = 0; j < (int)s[i].size(); ++j) {
			sam_extend(s[i][j]-'a', i);
		}
		sam_extend(26, i);
	}
	for (int i = 1; i < sz; ++i) {
		son[st[i].link].push_back(i);
	}
	dfs(0);
	for (int i = 1; i <= n; ++i) {
		T[i] = sam_traverse(s[i],false);
	}
	int l, r, k;
	for (int i = 0; i < q; ++i) {
		cin >> l >> r >> k;
		Q[2*i+1] = (qquery){i,1,T[k],r};
		Q[2*i+2] = (qquery){i,-1,T[k],l-1};
	}
	sort(Q+1, Q+2*q+1);
	for (int i = 1; i <= 2*q; ++i) {
//		printf("{%d,%d,%d,%d}\n", Q[i].id, Q[i].x, Q[i].k, Q[i].r);
		for (int j = Q[i-1].r+1; j <= Q[i].r; ++j) {
			sam_traverse(s[j], true);
		}
		ans[Q[i].id] += Q[i].x*query(1, 1, tim, dfn[Q[i].k], to[Q[i].k]);
//		printf("%d\n", query(1, 1, tim, 1, tim));
	}
//	for (int i = 1; i <= n; ++i) printf(" %d\n", query(1, 1, tim, dfn[T[i]], to[T[i]]));
	for (int i = 0; i < q; ++i) {
		printf("%d\n", ans[i]);
	}
}

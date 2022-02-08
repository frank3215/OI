#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10, maxq = ;
int n, q, T[maxn];
string s[maxn];

const int maxx = 1e7;
struct seg{
	int cnt, ls, rs;
}t[maxx];
int tot;
void pushup(int x) {
	t[x].cnt = t[t[x].ls].cnt+t[t[x].rs].cnt;
}
void ins(int &x, int l, int r, int v) {
	if (!x) {
		x = ++tot;
		assert(tot < maxx);
	}
	t[x].cnt++;
	if (l == r) return;
	int m = l+(r-l)/2;
	if (m >= v) ins(t[x].ls, l, m, v);
	else ins(t[x].rs, m+1, r, v);
}
int merge(int x, int y) {
	if (!x || !y) return x+y;
	int z = x;
	t[z].ls = merge(t[x].ls, t[y].ls);
	t[z].rs = merge(t[x].rs, t[y].rs);
	t[z].cnt = t[x].cnt+t[y].cnt;
	return z;
}
int query(int x, int l, int r, int L, int R) {
	if (!x) return 0;
	if (L <= l && r <= R) return t[x].cnt;
	int ret = 0, m = l+(r-l)/2;
	if (L <= m) ret += query(t[x].ls, l, m, L, R);
	if (R > m) ret += query(t[x].rs, m+1, r, L, R);
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
	assert(sz < maxt);
	st[cur].len = st[last].len+1;
	ins(rt[cur], 1, n, no);
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
			assert(nq < maxt);
			st[nq] = st[q];
			st[nq].len = st[p].len+1;
			while (p != -1 && st[p].next[c] == q) {
				st[p].next[c] = nq;
				p = st[p].link;
			}
			st[q].link = st[cur].link = nq;
		}
	}
//	printf("%d(%d)\n", cur, st[cur].link);
	last = cur;
}
int sam_traverse(string s) {
	int cur = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		cur = st[cur].next[s[i]-'a'];
		assert(cur != -1);
	}
	return cur;
}

int deg[maxt];
struct qquery{
	int id, l, r;
};
vector<qquery> qq[maxt];
queue<int> Q;
int ans[maxq];
void topu() {
	for (int i = 1; i < sz; ++i) {
		deg[st[i].link]++;
	}
	for (int i = 0; i < sz; ++i) {
		if (!deg[i]) Q.push(i);
	}
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		for (int i = 0; i < (int)qq[i].size(); ++i) {
			ans[qq[i].id] = query(rt[x], qq[i].l, qq[i].r);
		}
		if (x) {
			if (!--deg[st[x].link]) Q.push(st[x].link);
			rt[st[x].link] = merge(rt[st[x].link], rt[x]);
		}
	}
}

int main() {
	cin >> n >> q;
	sam_init();
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		for (int j = 0; j < (int)s[i].size(); ++j) {
			sam_extend(s[i][j]-'a', i);
		}
		sam_extend(26, i);
	}
	for (int i = 1; i <= n; ++i) {
		T[i] = sam_traverse(s[i]);
	}
	int l, r, k;
	for (int i = 1; i <= q; ++i) {
		cin >> l >> r >> k;
		qq[T[k]].push_back((query){i,l,r});
	}
	topu();
	for (int i = 1; i <= q; ++i) {
		cout << ans[i];
	}
}

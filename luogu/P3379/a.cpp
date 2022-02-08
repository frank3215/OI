#include <bits/stdc++.h>

#define _(str) cout << str << endl
#define __(var) cout << #var << " = " << var << endl

using namespace std;

const int maxn = 5e5+10, maxlog = 22;

struct ST{
	int len;
	int a[maxn<<1], lg[maxn<<1], pw[maxlog];
	int st[maxlog][maxn<<1];
	inline int cmp(const int &x, const int &y) {
		return a[x] < a[y] ? x : y;
	}
	void init(int l) {
		len = l;
		lg[0] = -1;
		for (int i = 1; i <= len; ++i)
			lg[i] = lg[i/2]+1;
		pw[0] = 1;
		for (int i = 1; i <= lg[len]; ++i)
			pw[i] = pw[i-1]*2;

		for (int i = 0; i < len; ++i) st[0][i] = i;
		for (int j = 1; j <= lg[len]; ++j) 
			for (int i = 0; i <= len-pw[j]; ++i)
				st[j][i] = cmp(st[j-1][i], st[j-1][i+pw[j-1]]);
	}
	int query(int l, int r) {
		int k = lg[r-l+1];
		return cmp(st[k][l], st[k][r-pw[k]+1]);
	}
};

struct lca{
	int head[maxn], nxt[maxn<<1], to[maxn<<1], tot;
	int e[maxn<<1], d[maxn], p[maxn], len;
	ST t;
	void add(int u, int v) {
		++tot;
		nxt[tot] = head[u];
		to[tot] = v;
		head[u] = tot;
	}
	void add2(int u, int v) {
		add(u, v);
		add(v, u);
	}
	void init(int u, int fa = 0) {
		d[u] = d[fa]+1;
		p[u] = len;

		e[len] = u;
		t.a[len] = d[u];
		len++;
		for (int i = head[u]; i != 0; i = nxt[i]) {
			int v = to[i];
			if (v == fa) continue;
			init(v, u);
			e[len] = u;
			t.a[len] = d[u];
			len++;
		}

		if (!fa) t.init(len);
	}
	int query(int u, int v) {
		if (p[u] > p[v]) swap(u, v);
		return e[t.query(p[u], p[v])];
	}
}t;

int main() {
	int n, m, s, u, v;
	scanf("%d%d%d", &n, &m, &s);
	for (int _ = 1; _ < n; ++_) {
		scanf("%d%d", &u, &v);
		t.add2(u, v);
	}
//	_("START INIT");
	t.init(s);
//	_("END INIT");
	while (m--) {
		scanf("%d%d", &u, &v);
//		__(u), __(v);
		printf("%d\n", t.query(u, v));
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+10;
typedef long long ll;

int n, fa[maxn], val[maxn], dfn[maxn], cnt; ll ret[maxn], ans;
char s[maxn], t[maxn]; int dep;
vector<int> v, son[maxn];

int vof(char c) {
	return c==')'?-1:1;
}

void dfs(int u) {
	val[u] = val[fa[u]] + vof(s[u-1]);
	ret[u] = ret[fa[u]];
	t[dep++] = s[u-1];
	printf("%s\n", t);
	for (int i = u; i; i = fa[i]) {
		if (val[fa[i]] == val[u]) ret[u]++;
		if (val[fa[i]] < val[u]) break;
	}
	printf("%d(%d) %lld\n", u, fa[u], ret[u]);
	ans ^= ret[u]*u;
	for (int i = 0; i < son[u].size(); ++i) {
		dfs(son[u][i]);
	}
	t[--dep] = '\0';
}

int main() {
	freopen("brackets2.in", "r", stdin);
	freopen("brackets.ans", "w", stdout);
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", fa+i);
		son[fa[i]].push_back(i);
	}
	fa[0] = -1;
	val[0] = 0;
	dfs(1);
	cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+10;
typedef long long ll;

int n, fa[maxn], brk[maxn], dfn[maxn], cnt; ll ret[maxn], ans;
char s[maxn];
stack<int> st;
vector<int> val[maxn<<1], son[maxn];

int pre[maxn];

int vof(char c) {
	return c==')'?-1:1;
}

int get(int v, int l, int r) {
	return upper_bound(val[v+maxn].begin(), val[v+maxn].end(), r) -
		lower_bound(val[v+maxn].begin(), val[v+maxn].end(), l);
}

void dfs(int u) {
	assert(!st.empty());
	dfn[u] = ++cnt;
	brk[u] = brk[fa[u]] + vof(s[u-1]);
	int top = -1;
	if (brk[u] < brk[st.top()]) {
		top = st.top(); st.pop();
	}
	if (st.empty() || brk[st.top()] < brk[u]) st.push(u);
//	printf("%d:%d\n", st.top(), dfn[st.top()]);
	ret[u] = ret[fa[u]] + get(brk[u], dfn[st.top()], dfn[u]);
//	printf("%d(%d) %lld\n", u, fa[u], ret[u]);
	ans ^= (ll)u*ret[u];
	val[maxn+brk[u]].push_back(dfn[u]);
	for (int i = 0; i < son[u].size(); ++i) {
		int v = son[u][i];
		dfs(v);
	}
	if (st.top() == u) st.pop();
	if (~top) st.push(top);
	val[maxn+brk[u]].pop_back();
}

int main() {
	freopen("brackets2.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", fa+i);
		son[fa[i]].push_back(i);
	}
	val[maxn].push_back(0);
	st.push(0);
	dfs(1);
	cout << ans << endl;
}

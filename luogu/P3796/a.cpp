#include <bits/stdc++.h>
using namespace std;

const int maxm = 155, maxl = 75, maxn = maxm*maxl, maxq = 2e6+10;

int n, tot = 1, ch[maxn][26], fa[maxn], vis[maxn], fail[maxn], a[maxn];
int ans;
char s[maxn][maxl], t[maxq];

void add(int u, char *s, int num) {
	for (int i = 0; s[i]; ++i) {
		int &son = ch[u][s[i]-'a'];
		if (!son) {
			son = ++tot;
			fa[son] = u;
		}
		u = son;
	}
	a[num] = u;
}
void build() {
	queue<int> q;
	for (int i = 0; i < 26; ++i)
		ch[0][i] = 1;
	q.push(1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; ++i)
			if (ch[u][i]) {
				q.push(ch[u][i]);
				fail[ch[u][i]] = ch[fail[u]][i];
			} else ch[u][i] = ch[fail[u]][i];
	}
}
void ac(char *t) {
	int u = 1;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; t[i]; ++i) {
		u = ch[u][t[i]-'a'];
		vis[u]++;
	}
}
void clear() {
	tot = 1;
	memset(ch, 0, sizeof(ch));
	memset(fa, 0, sizeof(fa));
	memset(fail, 0, sizeof(fail));
}
int deg[maxn];
void topu(int u) {
	queue<int> q;
	memset(deg, 0, sizeof(deg));
	for (int i = 1; i <= tot; ++i)
		deg[fail[i]]++;
	for (int i = 1; i <= tot; ++i)
		if (!deg[i])
			q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[fail[u]] += vis[u];
		if (!--deg[fail[u]]) q.push(fail[u]);
	}
}
bool solve() {
	scanf("%d", &n);
	if (!n) return false;
	clear();
	for (int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
		add(1, s[i], i);
	}
	build();
	scanf("%s", t);
	assert(tot < maxn);
	ac(t);
	topu(1);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, vis[a[i]]);
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; ++i) if (vis[a[i]] == ans) {
		printf("%s\n", s[i]);
	}
	return true;
}

int main() {
	while (solve());
}

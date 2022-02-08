#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;

int n, tot = 1, ch[maxn][26], fa[maxn], cnt[maxn], vis[maxn], fail[maxn];
int ans;
char s[maxn], t[maxn];

void add(int u, char *s) {
	for (int i = 0; s[i]; ++i) {
		int &son = ch[u][s[i]-'a'];
		if (!son) {
			son = ++tot;
			fa[son] = u;
		}
		u = son;
	}
	cnt[u]++;
}
void build() {
	queue<int> q;
	for (int i = 0; i < 26; ++i)
		if (ch[1][i]) {
			fail[ch[1][i]] = 1;
			q.push(ch[1][i]);
		}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < 26; ++i)
			if (ch[u][i]) {
				q.push(ch[u][i]);
				int v = fail[u];
				while (v && !ch[v][i]) v = fail[v];
				fail[ch[u][i]] = ch[v][i];
			}
	}
}
void ac(char *t) {
	int u = 1;
	for (int i = 0; t[i]; ++i) {
		while (u && !ch[u][t[i]-'a']) u = fail[u];
		u = ch[u][t[i]-'a'];
		for (int v = u; v && ~cnt[v]; v = fail[v]) ans += cnt[v], cnt[v] = -1;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		add(1, s);
	}
	build();
	scanf("%s", t);
	ac(t);
	cout << ans << endl;
}

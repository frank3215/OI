#include <bits/stdc++.h>
using namespace std;

const int N = 11, maxq = 2e6+10, A = 10;

int n, tot = 1, ch[maxn][A], fa[maxn], vis[maxn], fail[maxn], a[maxn];
int ans;
char s[N];

void add(int u, char *s, int num) {
	for (int i = 0; s[i]; ++i) {
		int &son = ch[u][s[i]-'a'];
		if (!son) {
			son = ++tot;
			fa[son] = u;
		}
		u = son;
	}
	a[num] = u, b[u] = num;
}
void build() {
	queue<int> q;
	for (int i = 0; i < A; ++i)
		ch[0][i] = 1;
	q.push(1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < A; ++i)
			if (ch[u][i]) {
				q.push(ch[u][i]);
				fail[ch[u][i]] = ch[fail[u]][i];
			} else ch[u][i] = ch[fail[u]][i];
	}
}
void ac(char *t) {
	int u = 1;
	for (int i = 0; t[i]; ++i) {
		u = ch[u][t[i]-'a'];
		vis[u]++;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s);
		add(1, s, i);
	}
	build();
	scanf("%s", t);
	assert(tot < maxn);
	ac(t);
	for (int i = 0; i < n; ++i)
		printf("%d\n", vis[a[i]]);
}

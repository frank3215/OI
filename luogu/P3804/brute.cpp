#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10, maxt = maxn<<1;

struct sam{
	int len, link, endpos;
	int next[26];
	sam() { memset(next, -1, sizeof(next)); }
}st[maxt];

int sz, last;
vector<int> son[maxt];

void sam_init() {
	st[0].len = 0;
	st[0].link = -1;
	last = 0;
	sz++;
}

void sam_extend(int c) {
	int cur = sz++;
	st[cur].len = st[last].len+1;
	st[cur].endpos = 1;
	int p = last;
	while (p != -1 && !~st[p].next[c]) {
		st[p].next[c] = cur;
		p = st[p].link;
	}
//	printf("%d\n", p);
	if (p == -1) {
		st[cur].link = 0;
	} else {
		int q = st[p].next[c];
		if (st[q].len == st[p].len+1) {
			st[cur].link = q;
		} else {
			int clone = sz++;
			st[clone].link = st[q].link;
			memcpy(st[clone].next, st[q].next, sizeof(st[clone].next));
			st[clone].len = st[p].len+1;
			while (p != -1 && st[p].next[c] == q) {
				st[p].next[c] = clone;
				p = st[p].link;
			}
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}

char s[maxn];
typedef long long ll;
ll ans;

void dfs(int u) {
	for (auto v: son[u]) {
		dfs(v);
		st[u].endpos += st[v].endpos;
	}
//	printf("%d(%d)\n", u, st[u].endpos);
	if (st[u].endpos >= 2) {
		ans = max(ans, (ll)st[u].len*st[u].endpos);
	}
}

void sam_print() {
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (st[i].next[j] != -1) {
				printf("%d %d %c\n", i, st[i].next[j], j+'a');
			}
		}
	}
	puts("");
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.ans", "w", stdout);
	scanf("%s", s);
	int len = strlen(s);
	sam_init();
	for (int i = 0; i < len; ++i) {
		sam_extend(s[i]-'a');
//		sam_print();
	}
	for (int i = 1; i < sz; ++i) {
		son[st[i].link].push_back(i);
	}
	dfs(0);
	printf("%lld\n", ans);
}

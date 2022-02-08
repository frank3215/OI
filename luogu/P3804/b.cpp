#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;

struct sam_node{
	int len;
	int ch[26];
	int link;
	sam_node() { memset(ch, -1, sizeof(ch)); }
}t[maxn<<1];

int lst, tot, cnt[maxn<<1];

void sam_init() {
	t[0].link = -1;
}

void sam_extend(int x) {
	int p = ++tot;
	t[p].len = t[lst].len+1;
	cnt[p] = 1;
	int q = lst;
	while (q != -1 && t[q].ch[x] == -1) {
		t[q].ch[x] = p;
		q = t[q].link;
	}
	if (q == -1) {
		t[p].link = 0;
	} else {
		int np = t[q].ch[x];
		if (t[np].len == t[q].len+1) {
			t[p].link = np;
		} else {
			int nnp = ++tot;
			t[nnp] = t[np];
			t[nnp].len = t[q].len+1;
			t[nnp].link = t[np].link;
			while (q != -1 && t[q].ch[x] == np) {
				t[q].ch[x] = nnp;
				q = t[q].link;
			}
			t[np].link = nnp;
			t[p].link = nnp;
		}
	}
	lst = p;
}

vector<int> to[maxn<<1];
int n;
char s[maxn];

void dfs(int x) {
	for (auto y: to[x]) {
		dfs(y);
		cnt[x] += cnt[y];
	}
}

long long ans;

int main() {
	scanf("%s", s);
	n = strlen(s);
	sam_init();
	for (int i = 0; i < n; ++i) {
		sam_extend(s[i]-'a');
	}
	for (int i = 1; i <= tot; ++i)
		to[t[i].link].push_back(i);
	dfs(0);
	for (int i = 1; i <= tot; ++i) if (cnt[i] > 1) {
		ans = max(ans, 1ll*t[i].len*cnt[i]);
	}
	printf("%lld\n", ans);
}

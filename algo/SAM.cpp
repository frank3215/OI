#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10, SIGMA = 27;

long long ans;

namespace sam{
	struct node{
		int link, len, cnt, ch[SIGMA];
		vector<int> v;
		inline void add_son(int x, int y) {
			assert(ch[x] == 0 && y);
			ch[x] = y;
		}
		inline void clone_son(const node &n) {
			memcpy(ch, n.ch, sizeof(ch));
		}
		/*
		inline void print() {
			printf(" end:%d link:%d len:%d cnt:%d\n", end, link, len, cnt);
			for (int i = 0; i < 26; ++i) if (ch[i])
				printf(" %c->%d", i+'a', ch[i]);
			printf("\n\n");
		}
		*/
	}t[maxn<<1];
	int tot, last;
	pair<int, int> tmp[maxn<<1]; int z;
	void init() {
		tot = last = 0;
		t[0].link = -1;
	}
	void add(int c) {
		int cur = ++tot, p = last;
//		printf("%d:\n", cur);
		t[cur].cnt = 1;
		t[cur].len = t[last].len+1;
		while (p != -1 && !t[p].ch[c]) {
			 t[p].add_son(c, cur);
			 p = t[p].link;
		}
//		printf("p=%d\n", p);
		if (p == -1) {
			t[cur].link = 0;
		} else {
			int q = t[p].ch[c];
//			printf("q=%d\n", q);
			if (t[q].len == t[p].len+1) {
				t[cur].link = q;
			} else {
				int clone = ++tot;
				t[clone].len = t[p].len+1;
				t[clone].link = t[q].link;
				t[clone].cnt = 0;
				t[q].link = t[cur].link = clone;
				t[clone].clone_son(t[q]);
				while (p != -1 && t[p].ch[c] == q) {
					t[p].ch[c] = clone;
					p = t[p].link;
				}
			}
		}
		last = cur;
//		t[cur].print();
	}
	void solve() {
		for (int i = tot; i; --i) t[t[i].link].v.push_back(i);
		tmp[++z] = make_pair(0, -1);
		while (z) {
			pair<int, int> &cur = tmp[z];
			int &f = cur.first, &s = cur.second;
			if (~s) t[f].cnt += t[t[f].v[s]].cnt;
			if (++s < t[f].v.size()) tmp[++z] = make_pair(t[f].v[s], -1);
			else --z;
		}
		for (int i = 0; i <= tot; ++i) {
//			printf("%d\n", i);
			if (t[i].cnt > 1) ans = max(ans, (long long)t[i].len*t[i].cnt);
//			printf("%d\n", ans);
//			t[i].print();
		}
	}
}

int main() {
	using namespace sam;
	init();
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		add(s[i]-'a');
	}
	solve();
	printf("%lld\n", ans);
//	printf("%d\n", tot);
}

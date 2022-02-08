#include <bits/stdc++.h>
#define fi first
using namespace std;

const int inf = 0x3f3f3f3f, N = 1e5+10;

map<int,int> m;

int n;
int t[N], a[N], b[N], w[N];
int ans = -1, pos = inf;

signed main() {
	scanf("%d", &n);
	m[inf] = m[-inf] = 0;
	m[0];
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", t+i, a+i);
		if (t[i] == 1) scanf("%d", b+i);
		scanf("%d", w+i);
		if (t[i] == 1) {
			m[a[i]-1];
			m[a[i]] ^= w[i];
			m[b[i]];
			m[b[i]+1] ^= w[i];
		} else if (t[i] == 2) {
			m[a[i]-1];
			m[a[i]] ^= w[i];
			m[a[i]+1] ^= w[i];
		} else if (t[i] == 3) {
			m[-inf] ^= w[i];
			m[a[i]-1];
			m[a[i]] ^= w[i];
			m[a[i]+1] ^= w[i];
		}
	}
	int cur = 0;
	for (map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
		cur ^= it->second;
		if (cur > ans || (cur == ans && (abs(pos) > abs(it->fi) || (abs(pos) == abs(it->fi) && pos < it->fi)))) {
			ans = cur, pos = it->fi;
		}
	}
	printf("%d %d\n", ans, pos);
}


#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4+10, S = 27, M = 1e3+10;

int n, bb[N], end[N];

char a[M], b[M];
char s[N][S];

namespace ac{
	int t[N][26], tot, fail[N], rt;
	int val[N];
	void clear() {
		rt = tot = 1;
		memset(t, 0, sizeof(t));
		for (int i = 0; i < 26; ++i) t[0][i] = 1;
		memset(fail, 0, sizeof(fail));
	}
	int insert(char *s) {
		int i = 1;
		for (; *s; ++s) {
			int &cur = t[i][*s-'a'];
			if (!cur) cur = ++tot;
			i = cur;
		}
		return i;
	}
	void build() {
		queue<int> q;
		q.push(rt);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			val[u] += val[fail[u]];
			for (int i = 0; i < 26; ++i) {
				if (t[u][i]) {
					fail[t[u][i]] = t[fail[u]][i];
					q.push(t[u][i]);
				}
				else t[u][i] = t[fail[u]][i];
			}
		}
//		for (int i = 0; i <= tot; ++i) {
//			printf("%d(%d): %d\n", i, val[i], fail[i]);
//			for (int j = 0; j < 26; ++j) if (t[i][j] != 1) {
//				printf(" %c:%d", 'a'+j, t[i][j]);
//			} puts("");
//		}
	}
}
using namespace ac;

int pa[N], sb[N];

void solve() {
	clear();
	cin >> (a+1) >> (b+1);
	int la = strlen(a+1), lb = strlen(b+1);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i] >> bb[i];
		val[insert(s[i])] = bb[i];
	}
	build();
	for (int i = 1, j = 1; i <= la; ++i) {
		j = t[j][a[i]-'a'];
		pa[i] = val[j];
		//printf("%d: %d\n", j, val[j]);
	}
	for (int i = 1; i <= la; ++i) pa[i] += pa[i-1];
	for (int i = 1, j = 1; i <= lb; ++i) {
		j = t[j][b[i]-'a'];
		sb[i] = val[j];
		//printf("%d: %d\n", j, val[j]);
	}
	for (int i = lb; ~i; --i) sb[i] += sb[i+1];
	int ans = 0;
	for (int i = 1; i <= la; ++i) {
		for (int j = 1; j <= lb; ++j) {
			int cur = 0, al = max(1ll, i-26), br = min(lb, j+26);
			int u = 1;
			for (int k = al; k <= i; ++k) {
				u = t[u][a[k]-'a'];
				cur += val[u];
				//printf(" %d %d\n", u, val[u]);
			}
			for (int k = j; k <= br; ++k) {
				u = t[u][b[k]-'a'];
				cur += val[u];
				//printf(" %d %d\n", u, val[u]);
			}
			//printf("%d,%d %d\n", i, j, cur);
			cur -= pa[i]-pa[al-1];
			cur -= sb[j]-sb[br+1];
			cur += pa[i];
			cur += sb[j];
			ans = max(ans, cur);
		}
	}
	cout << ans << endl;
}

signed main() {
	int t;
	cin >> t;
	while (t--) solve();
}

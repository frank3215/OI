#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4+10, S = 28, M = 1e3+10, Len = 26;

int n, bb[N], end[N];

char a[M], b[M];
char s[N][S];

int rt[S];
namespace ac{
	const int N = (::N*S*2);
	int t[N][26], tot, fail[N];
	int val[N];
	void clear() {
		memset(t, 0, (tot+1)*sizeof(t[0]));
		memset(fail, 0, (tot+1)*sizeof(fail[0]));
		memset(val, 0, (tot+1)*sizeof(val[0]));
		tot = Len+1;
	}
	int insert(int &rt, char *s) {
		int i = rt;
		for (; *s; ++s) {
			int &cur = t[i][*s-'a'];
			if (!cur) cur = ++tot;
			i = cur;
		}
		return i;
	}
	void build(int rt) {
		queue<int> q;
		for (int i = 0; i < 26; ++i) t[0][i] = rt;
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
	}
}
using namespace ac;

int pa[S][M], sb[S][M];
int pos[S];
int la, lb;

void solve() {
	clear();
	for (int i = 0; i <= Len; ++i) {
		for (int j = 0; j <= la+2; ++j) pa[i][j] = 0;
		for (int j = 0; j <= lb+2; ++j) sb[i][j] = 0;
	}
	scanf("%s%s", a+1, b+1);
	la = strlen(a+1), lb = strlen(b+1);
	scanf("%lld", &n);
	for (int i = 0; i <= Len; ++i) rt[i] = i+1;
	for (int i = 1; i <= n; ++i) {
		scanf("%s%lld", s[i], &bb[i]);
		val[insert(rt[0], s[i])] += bb[i];
		val[insert(rt[strlen(s[i])], s[i])] += bb[i];
	}
	for (int i = 0; i <= Len; ++i) build(rt[i]);
	for (int i = 1; i <= Len; ++i) pos[i] = rt[i];
	for (int i = 1; i <= la; ++i) {
		for (int j = 1; j <= Len; ++j) {
			pos[j] = t[pos[j]][a[i]-'a'];
			pa[j][i] = val[pos[j]];
		}
	}
	for (int i = 1; i <= la; ++i) 
		for (int j = 1; j <= Len; ++j) 
			pa[j][i] += pa[j][i-1];
	for (int i = 1; i <= Len; ++i) pos[i] = rt[i];
	for (int i = 1; i <= lb; ++i) {
		for (int j = 1; j <= Len; ++j) {
			pos[j] = t[pos[j]][b[i]-'a'];
			sb[j][i] = val[pos[j]];
		}
	}
	for (int i = lb; ~i; --i) 
		for (int j = 0; j <= Len; ++j) 
			sb[j][i] += sb[j][i+1];
	int ans = 0;
	for (int i = 1; i <= la; ++i) {
		for (int j = 1; j <= lb; ++j) {
			int cur = 0, al = max(1ll, i-Len), br = min(lb, j+Len);
			int u = 1;
			for (int k = al; k <= i; ++k) {
				u = t[u][a[k]-'a'];
				cur += val[u];
			}
			for (int k = j; k <= br; ++k) {
				u = t[u][b[k]-'a'];
				cur += val[u];
			}
			for (int k = 1; k <= Len; ++k) {
				cur -= pa[k][i]-pa[k][al+k-2];
				cur -= sb[k][j+k-1]-sb[k][br+1];
				cur += pa[k][i];
				cur += sb[k][j+k-1];
			}
			ans = max(ans, cur);
		}
	}
	printf("%lld\n", ans);
}

signed main() {
	int t;
	scanf("%lld", &t);
	while (t--) solve();
}

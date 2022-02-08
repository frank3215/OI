#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4+10, S = 28, M = 1e3+10;

int n, bb[N];

char a[M], b[M];
char s[N][S];
int nxt[N][S], l[N];

void solve() {
	cin >> (a+1) >> (b+1);
	int la = strlen(a+1), lb = strlen(b+1);
	cin >> n;
	memset(nxt, 0, sizeof(nxt));
	for (int i = 1; i <= n; ++i) {
		cin >> (s[i]+1) >> bb[i];
		l[i] = strlen(s[i]+1);
		nxt[i][0] = -1;
		for (int j = 1, k; j <= l[i]; ++j) {
			for (k = nxt[i][j-1]; k != -1 && s[i][k+1] != s[i][j]; k = nxt[i][k]);
			nxt[i][j] = k+1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= la; ++i) {
		for (int j = 1; j <= lb; ++j) {
			int ret = 0;
			for (int _ = 1; _ <= n; ++_) {
				int cur = 0;
				for (int k = 1; k <= i; ++k) {
					for (; cur != -1 && a[k] != s[_][cur+1]; cur = nxt[_][cur]);
					if (++cur == l[_]) {
						cur = nxt[_][cur];
						ret += bb[_];
					}
				}
				for (int k = j; k <= lb; ++k) {
					for (; cur != -1 && b[k] != s[_][cur+1]; cur = nxt[_][cur]);
					if (++cur == l[_]) {
						cur = nxt[_][cur];
						ret += bb[_];
					}
				}
			}
			ans = max(ans, ret);
		}
	}
	cout << ans << endl;
}

signed main() {
	int t;
	cin >> t;
	while (t--) solve();
}

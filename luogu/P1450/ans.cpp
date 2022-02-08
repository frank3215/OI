#include <bits/stdc++.h>
using namespace std;

const int n = 4, mx = 1e5+10, pm[] = {1,-1};
#define int long long

int c[n], d[n], dp[mx] = {1};

signed main() {
	for (int i = 0; i < 4; ++i) {
		cin >> c[i];
		for (int j = c[i]; j < mx; ++j)
			dp[j] += dp[j-c[i]];
	}
	int tot, s;
	cin >> tot;
	while (tot--) {
		for (int i = 0; i < 4; ++i) cin >> d[i];
		cin >> s;
		int res = 0;
		for (int i = 0; i < 16; ++i) {
			int tmp = s, cnt = 0;
			for (int j = 0; j < 4; ++j) {
				if ((i>>j) & 1) {
					cnt++;
					tmp -= (d[j]+1)*c[j];
				}
			}
//			cout << cnt << ' ' << tmp << endl;
			res += pm[cnt%2]*(tmp>=0?dp[tmp]:0);
		}
		cout << res << endl;
	}
}

#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n, bb[N];
string a, b, s[N];

void solve() {
	cin >> a >> b >> n;
	for (int i = 0; i < n; ++i) cin >> s[i] >> bb[i];
	int ans = 0;
	for (int i = 0; i <= (int)a.size(); ++i) {
		for (int j = 0; j <= (int)b.size(); ++j) {
			string cur = a.substr(0, i)+b.substr(j);
			int ret = 0;
			for (int k = 0; k < n; ++k) {
				for (int l = 0; l < (int)cur.size(); ++l) {
					if (cur.substr(l, s[k].size()) == s[k]) ret += bb[k];
				}
			}
			ans = max(ans, ret);
		}
	}
	cout << ans << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) solve();
}

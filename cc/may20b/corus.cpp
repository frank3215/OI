#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, q;
	string s;
	cin >> n >> q >> s;
	int cnt[26] = {};
	for (int i = 0; i < n; ++i) {
		cnt[s[i]-'a']++;
	}
	for (int i = 0; i < q; ++i) {
		int c;
		scanf("%d", &c);
		int ans = 0;
		for (int i = 0; i < 26; ++i)
			if (cnt[i] > c) ans += cnt[i]-c;
		cout << ans << endl;
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}

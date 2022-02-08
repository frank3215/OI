#include <bits/stdc++.h>
using namespace std;

const int maxn = 51;

int n;
string s[maxn];
string mid[maxn], pref[maxn], suff[maxn];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		int x = s[i].find('*'), y = s[i].rfind('*');
		pref[i] = s[i].substr(0, x);
		suff[i] = s[i].substr(y+1);
		reverse(suff[i].begin(), suff[i].end());
		mid[i] = s[i].substr(x, y-x);
	}
	sort(pref+1, pref+n+1);
	for (int i = 1; i <= n; ++i) {
		cerr << pref[n] << ' ' << pref[i] << endl;
		if (pref[n].substr(0, pref[i].size()) != pref[i]) {
			puts("*");
			return;
		}
	}
	sort(suff+1, suff+n+1);
	for (int i = 1; i <= n; ++i) {
		cerr << suff[n] << ' ' << suff[i] << endl;
		if (suff[n].substr(0, suff[i].size()) != suff[i]) {
			puts("*");
			return;
		}
	}
	cout << pref[n];
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < (int)mid[i].size(); ++j)
			if (mid[i][j] != '*') cout << mid[i][j];
	}
	reverse(suff[n].begin(), suff[n].end());
	cout << suff[n] << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
}

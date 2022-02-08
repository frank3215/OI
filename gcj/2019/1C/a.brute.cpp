#include <bits/stdc++.h>

const int maxn = 260, maxr = 5;

using namespace std;

bool cmp(char a, char b) {
	if (a=='R') return b=='S';
	else if (a=='P') return b=='R';
	else if (a=='S') return b=='P';
}

void solve() {
	int n, tot = 0;
	cin >> n;
	string s[maxn];
	bool out[maxn]={};

	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i <= maxr; ++i) {
		if (i == maxr) {
			for (int j = 0; j <= i*i; j++) {
				for (int k = 1; k <= n; ++k) if (ok{
					if (cmp(
				}
			}
		}

		int cnt[128];
		cnt['R'] = cnt['P'] = cnt['S'] = 0;
		for (int j = 1; j <= n; j++) if (!out[j]) {
			cnt[s[j][i%s[j].size()]]++;
		}
		if (cnt['R'] && cnt['P'] && cnt['S']) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
		else if (cnt['R'] && cnt['P']) s[0] += 'P';
		else if (cnt['R'] && cnt['S']) s[0] += 'R';
		else if (cnt['P'] && cnt['S']) s[0] += 'S';
		else if (cnt['R']) s[0] += 'P';
		else if (cnt['P']) s[0] += 'S';
		else if (cnt['S']) s[0] += 'R';

		for (int j = 1; j <= n; j++)
			if (!out[j] && cmp(s[0][i], s[j][i%s[j].size()])) {
				out[j] = 1;
				++tot;
			}

		if (tot == n) break;
	}
	cout << s[0] << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}

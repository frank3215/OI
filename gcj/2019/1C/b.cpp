#include <bits/stdc++.h>
#define fprintf //

using namespace std;

int t, f;

int factorial(int n) {
	int res = 1;
	for (int i = 2; i <= n; ++i) res *= i;
	return res;
}

bool solve() {
	vector<int> pos;
	string ans;
	char res;

	for (int i = 1; i <= 595; i += 5) {
		pos.push_back(i);
	}

	int vis[5] = {};
	for (int i = 5; i >= 1; --i) {

		vector<int> cnt[5];
		for (int j = 0; j < pos.size(); ++j) {
			cout << pos[j] << endl;
			fprintf(stderr, "%d\n", pos[j]);
			fflush(stderr);
			cin >> res;
			fprintf(stderr, "%c\n", res);
			fflush(stderr);
			cnt[res-'A'].push_back(pos[j]+1);
		}

		int target = factorial(i-1);
		for (int j = 0; j < 5; ++j) {
			if (!vis[j] && cnt[j].size() != target) {
				ans += ('A'+j);
				vis[j] = 1;
				pos = cnt[j];
			}
		}
		fprintf(stderr, "%s(%d)\n", ans.c_str(), pos.size());
	}
	fprintf(stderr, "%s\n", ans.c_str());
	cout << ans << endl;
	cin >> res;
	return res != 'Y';
}

int main() {
	cin >> t >> f;
	while (t--) {
		if (solve()) return 0;
	}
}

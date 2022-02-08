#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, p, k, a;
	cin >> n >> m >> p;
	vector<int> cnt(m+1);
	for (int i = 0; i < n; ++i) {
		cin >> k;
		for (int j = 0; j < k; ++j) {
			cin >> a;
			cnt[a]++;
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (cnt[i] == p) cout << i << ' ';
	}
	cout << endl;
}

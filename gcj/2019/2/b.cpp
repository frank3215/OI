#include <bits/stdc++.h>



void solve() {
	int cur;
	for (int i = 0; i < 99; ++i) {
		cin >> cur;
		if (i/38 < 1) {
			cout << (i/2)%19+1 << 0 << endl;
			cin >> n;
			while (n--) {
				cin >> val;
				v.push_back(val);
			}
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) solve();
}

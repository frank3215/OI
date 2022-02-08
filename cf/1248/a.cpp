#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, p, P[2] = {}, m, q, Q[2] = {};
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> p;
			P[p%2]++;
		}
		cin >> m;
		for (int i = 0; i < m; ++i) {
			cin >> q;
			Q[q%2]++;
		}
		cout << (long long)Q[0]*P[0]+(long long)Q[1]*P[1] << endl;
	}
}

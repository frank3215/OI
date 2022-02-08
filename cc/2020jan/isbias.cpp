#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int l, r;
	while (q--) {
		cin >> l >> r; --l, --r;
		cout << ((a[l] < a[l+1]) == (a[r] < a[r-1])?"YES":"NO") << endl;
	}
}

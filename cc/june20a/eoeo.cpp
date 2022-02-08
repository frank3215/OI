#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int t, ts;
	cin >> t;
	while (t--) {
		cin >> ts;
		int cnt = 1;
		while (ts%(cnt<<1) == 0) cnt <<= 1;
		cout << (ts-1)/(cnt<<1) << endl;
	}
}

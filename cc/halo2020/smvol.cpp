#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << (n==1?1:6*n*n-12*n+8) << endl;
	}
}
	

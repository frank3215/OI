#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)

int main() {
	int n;
	cin >> n;
	int a[n], ans = 1e9;
	F0R(i,n) {
		cin >> a[i];
	}
	F0R(i,1<<10) {
		int mx = 0;
		F0R(j,n) mx = max(mx, a[j]^i);
		ans = min(ans, mx);
	}
	cout << ans << endl;
}

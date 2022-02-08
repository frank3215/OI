#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)

void solve() {
	int s, w[3], ans = 3;
	cin >> s;
	F0R(i,3) cin >> w[i];
	if (s >= w[0] && s >= w[1]+w[2]) ans = 2;
	if (s >= w[2] && s >= w[0]+w[1]) ans = 2;
	if (s >= w[0]+w[1]+w[2]) ans = 1;
	cout << ans << endl;
}


int main() {
	int t;
	cin >> t;
	while (t--) solve();
}

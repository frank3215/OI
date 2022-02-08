#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)

int n;
vector<int> v;

int solve(int l, int r, int k) {
	if (l == r) return 0;
	if (k == -1) return 0;
	int i = l;
	for(; i < r; ++i) {
		if (v[i]&(1<<k)) break;
	}
	if (i == l) return solve(i, r, k-1);
	if (i == r) return solve(l, i, k-1);
	return (1<<k)+min(solve(l, i, k-1), solve(i, r, k-1));
}

int main() {
	cin >> n;
	int a;
	F0R(i,n) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	cout << solve(0, n, 29);
}

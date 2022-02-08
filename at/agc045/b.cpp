#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b-1); i >= a; --i)
#define REP(i,a,b) for (int i = a; i <= b; ++i)
#define PER(i,a,b) for (int i = b; i >= a; --i)
#define F0R(i,b) FOR(i,0,b)
#define R0F(i,b) ROF(i,0,b)
#define R1P(i,b) REP(i,1,b)
#define P1R(i,b) PER(i,1,b)
using namespace std;

signed main() {
	string s;
	cin >> s;
	int n = s.size();
	int l = 1, r = n;
	while (l < r) {
		int m = (l+r+1)>>1;
		if (solve(s, m)) l = m;
		else r = m-1;
	}
}

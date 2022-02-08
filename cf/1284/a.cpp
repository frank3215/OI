#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define MOD(x,m) ((x)%(m)+(m))%(m)

//#define int long long

signed main() {
	int n, m;
	cin >> n >> m;
	string s[n], t[m];
	F0R(i,n) cin >> s[i];
	F0R(i,m) cin >> t[i];
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x; --x;
		cout << s[x%n]+t[x%m] << endl;
	}
}

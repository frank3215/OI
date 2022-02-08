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
#define int long long

signed main() {
	int m, n, v, p, ans = 0;
	cin >> n >> m >> v >> p;
	vector<int> a(n), s(n);
	F0R(i,n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	F0R(i, n) {
		s[i] = (i?s[i-1]:0)+a[i];
	}
	F0R(i,n) {
		int tmp = upper_bound(a.begin(), a.end(), a[i]+m)-a.begin()-1;
		int sum = (tmp-i)*(a[i]+m)-(s[tmp]-s[i]);
		cout << a[i] << ' ' << tmp << ' ' << sum << ' ' << (v-i-1) << endl;
		if (tmp >= n-p && sum >= (v-i-1)*m) ans++;
	}
	cout << ans;
}

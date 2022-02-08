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
	cin >> n; m = n;
	vector<int> v[n], mx, mn;
	bool a[n] = {};
	F0R(i,n) {
		int l, x, y = 1e6;
		cin >> l;
		F0R(j,l) {
			cin >> x;
			v[i].push_back(x);
			if (y < x) a[i] = 1;
			y = x;
		}
		if (a[i]) --m;
		else {
			mx.push_back(*max_element(v[i].begin(), v[i].end()));
			mn.push_back(*min_element(v[i].begin(), v[i].end()));
		}
	}
	sort(mx.begin(), mx.end());
	sort(mn.begin(), mn.end());
	long long ans = 1ll*n*n-1ll*m*m;
	F0R(i,m) {
//		cout << ans << ' ' << mn[i] << endl;
		ans += mx.end()-upper_bound(mx.begin(),mx.end(),mn[i]);
	}
	cout << ans << endl;
}

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

#define int long long

typedef long long ll;

signed main() {
	ll x;
	cin >> x;
	vector<ll> f;
	for (ll i = 2; i*i <= x; ++i) {
		if (x%i == 0) {
			f.push_back(1);
			do {
				f.back() *= i;
				x /= i;
			} while (x%i == 0);
//			cerr << f.back() << endl;
		}
	}
	if (x != 1) f.push_back(x);
	ll ans = 1e18, A, B;
	for (int i = 0; i < (1ll<<((int)f.size())); ++i) {
		ll a = 1, b = 1;
		for (int j = 0; j < (int)f.size(); ++j) {
			if (i&(1<<j)) a *= f[j];
			else b *= f[j];
		}
//		cerr << a << ' ' << b << endl;
		if (max(a, b) < ans) A = a, B = b, ans = max(a, b);
	}
	cout << A << ' ' << B << endl;
}

#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)

#define fi first
#define se second

#define pb push_back
#define mp make_pair

typedef pair<int,int> pii;

const int N = 1e5+10;

int n;
pii a[N], b[N];

bool check(pii* a, pii *b) {
	vector<pii> v;
	F0R(i,n) {
		v.pb(mp(a[i].fi, -1-i));
		v.pb(mp(a[i].se, i));
	}
	sort(v.begin(), v.end());
	multiset<int> L, R;
	for (auto p : v) {
		if (p.se < 0) {
			if ((!L.empty() && !R.empty()) && (*R.begin() < b[-1-p.se].fi || *L.rbegin() > b[-1-p.se].se)) return false;
			L.insert(b[-1-p.se].fi);
			R.insert(b[-1-p.se].se);
		} else {
			L.erase(L.find(b[p.se].fi));
			R.erase(R.find(b[p.se].se));
		}
	}
	return true;
}

int main() {
	cin >> n;
	F0R(i,n) {
		cin >> a[i].fi >> a[i].se >> b[i].fi >> b[i].se;
	}
	bool ans = true;
	ans &= check(a, b);
	ans &= check(b, a);
	cout << (ans?"YES":"NO") << endl;
}

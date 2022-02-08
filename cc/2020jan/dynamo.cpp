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
#define ins insert
#define ITER(i,x) for (auto &i: x)
#define ITE(i,x) for (auto i: x)
#define IT(i,x) for (auto i = x.begin(); i != x.end(); ++i)
#define ALL(x) x.begin(), x.end()

//#define double long double
//#define int long long

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppp;

void solve() {
	int n;
	ll a, t = 1;
	cin >> n >> a;
	F0R(i,n) t *= 10;
	cout << t*2+a << endl;
	F0R(i,2) {
		cin >> a;
		cout << t-a << endl;
	}
	cin >> n;
	if (n == -1) exit(0);
}


signed main() {
	int t;
	cin >> t;
	while (t--) solve();
}

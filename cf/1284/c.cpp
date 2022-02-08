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
	int n, m;
	cin >> n >> m;
	int ans = 0, fact[n+1] = {1};
	FOR(i,1,n+1) fact[i] = fact[i-1]*i%m;
	FOR(i,1,n+1) {
		ans = (ans + fact[i]*fact[n-3]%m*(n-i+1)%m*(n-i+1))%m;
	}
	cout << ans << endl;
}

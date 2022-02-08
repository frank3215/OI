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
	int n, a, b;
	cin >> n >> a >> b;
	if ((b-a)%2 == 0) cout << (b-a)/2;
	else cout << min((n-b)+1+(n-(a+(n-b)+1))/2, (a-1)+1+(b-a-1)/2);
}

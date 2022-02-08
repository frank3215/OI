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

const int maxn = 5010;

int n, m, ans;
int f[maxn], s[maxn];

int main() {
	cin >> n >> m;
	f[0] = 1;
	FOR(i, 1, n+1) {
		FOR(j, i, n+1)
			f[j] += f[j-i];
		FOR(j, 0, n+1)
			s[i][j] = f[j];
	}
	int k = (n-1)/2;
	if (n%2 == 0) {
		for (int x = 1; x <= n; ++x)
			for (int j = 0; j < x; ++j) {
				ans += f[j]*s[x-j-1];
			}
	} else {
		for (int x = 1; x <= n; ++x)
			for (int j = 0; j < x; ++j) {
				ans += s[j]*s[x-j-1];
			}
	}
	cout << ans << endl;
}

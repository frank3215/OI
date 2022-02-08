#include <bits/stdc++.h>
using namespace std;

#define int long long

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

const int maxn = 2e5+10;

long long a[maxn], s[maxn];

signed main() {
	long long m, n, v, p, ans = 0;
	cin >> n >> m >> v >> p;
	F0R(i,n) {
		cin >> a[i];
	}
	sort(a, a+n);
	F0R(i, n) {
		s[i] = (i?s[i-1]:0)+a[i];
	}
	F0R(i,n) {
		long long num = p-1+i;
		if (a[n-p] > a[i]+m) continue;
		if (num >= v-1) {
			if (a[i]+m >= a[n-p]) {
				ans++;
			}
			continue;
		}
		long long tmp = upper_bound(a, a+n, a[i]+m)-a-1;
//		printf("sum = %d*%d-(%d-%d)\n", (min(tmp,n-p)-i), (a[i]+m), s[min(tmp,n-p)], s[i]);
		long long sum = (min(tmp,n-p)-i)*(a[i]+m)-(s[min(tmp,n-p)]-s[i]);
//		printf("%d:%d %d %d\n", i, tmp, sum, m*(v-num-1));
		if (sum >= m*(v-num-1)) ans++;
	}
	cout << ans;
}

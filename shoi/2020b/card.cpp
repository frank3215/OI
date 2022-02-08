#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,b,a) for (int i = (b-1); i >= a; --i)
using namespace std;

const int N = 1e5+10;

int n;
int a[N], s[N], f[N];

signed main() {
	scanf("%lld", &n);
	FOR(i,0,n) {
		scanf("%lld", a+i);
		s[i] = (i?s[i-1]:0)+a[i];
	}
	f[0] = 0;
	int mx = 0;
	FOR(i,1,n) {
		f[i] = s[i]+mx;
		mx = max(mx, f[i]);
	}
	printf("%lld\n", mx);
}


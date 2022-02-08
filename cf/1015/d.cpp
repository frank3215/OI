#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b-1); i >= a; --i)
using namespace std;

int n, k, s;

signed main() {
	scanf("%lld%lld%lld", &n, &k, &s);
	if (s < k || s > (n-1)*k) puts("NO");
	else {
		puts("YES");
		int cur = 1;
		FOR(i,0,k) {
			int step = min(n-1, s-(k-i-1));
			if (i&1) cur -= step;
			else cur += step;
			s -= step;
			printf("%lld ", cur);
		}
	}
}


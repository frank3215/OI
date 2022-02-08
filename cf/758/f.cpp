#include <bits/stdc++.h>
#define int long long
using namespace std;

const double eps = 1e-10;
const int N = 1e7+10;

int n, l, r;
int f[N], s[N];
vector<int> v;

signed main() {
	scanf("%lld%lld%lld", &n, &l, &r);
	if (n == 1) {
		printf("%lld\n", r-l+1);
	} else if (n == 2) {
		printf("%lld\n", 1ll*(r-l+1)*(r-l));
	} else {
		--n;
		int ans = 0;
		for (int i = 1; i <= r; ++i) {
			int ret = 1;
			for (int j = 0; j < n; ++j) {
				if (r/i < ret) { ret = r+1; break; }
				ret *= i;
			}
			if (ret > r) break;
			v.push_back(ret);
			s[ret] = 1;
			//printf("%lld %lld\n", i, ret);
		}
		for (int i = 1; i <= r; ++i) {
			s[i] += s[i-1];
			//printf("s[%lld] = %lld\n", i, s[i]);
		}
		for (int i = r; i >= 1; --i) {
			int L = (l+i-1)/i, R = (r/i);
			int x = s[R]-s[L-1];
			//printf("%lld %lld\n", i, x);
			f[i] = 1ll*x*(x-1);
			for (int j = 1; j < (int)v.size() && i*v[j] <= r; ++j) {
				f[i] -= f[i*v[j]];
			}
			ans += f[i];
		}
		printf("%lld\n", ans);
	}
}

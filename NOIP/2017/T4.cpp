#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1000000001, N = 5e5+10, infn = -1e18;

int n, d, k;
int x[N], s[N], f[N], q[N], fr, ed;

int check(int g) {
	int ret = 0;
	fr = 1, ed = 0;
	for (int i = 1, j = 0; i <= n; ++i) {
//		for (int j = fr; j <= ed; ++j) cout << '[' << q[j] << ']'; cout << endl;
		for (; j < i && x[i]-x[j] >= d-g; ++j) {
			while (fr <= ed && f[q[ed]] <= f[j]) --ed;
			q[++ed] = j;
		}
//		for (int j = fr; j <= ed; ++j) cout << '[' << q[j] << ']'; cout << endl;
		while (fr <= ed && x[i]-x[q[fr]] > d+g) ++fr;
//		for (int j = fr; j <= ed; ++j) cout << '[' << q[j] << ']'; cout << endl;
		if (fr <= ed) f[i] = f[q[fr]]+s[i];
		else f[i] = infn;
		ret = max(ret, f[i]);
//		cout << ' ' << i << ' ' << f[i] << endl;
	}
	return ret;
}

signed main() {
	scanf("%lld%lld%lld", &n, &d, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%lld%lld", x+i, s+i);
	int l = 0, r = inf;
	while (l < r) {
		int m = (l+r)>>1;
//		cout << m << ' ' << check(m) << endl;
		if (check(m) >= k) r = m;
		else l = m+1;
	}
	printf("%d\n", (r==inf)?-1:r);
}

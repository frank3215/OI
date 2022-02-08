#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 4e5+10, MOD = 1e9+7, co[] = {1, -1};
int n, m, l, r;

int fact[maxn], invf[maxn];
int mod(int x) { return (x%MOD+MOD)%MOD; }
int& mo(int &x) { return x = mod(x); }

int pow(int a, int k) {
	return (k?(pow(a*a%MOD, k/2)*(k&1?a:1)):1)%MOD;
}
int c(int n, int k) {
	assert(0 <= k && k <= n && n < maxn);
	return mod(mod(fact[n]*invf[n-k])*invf[k]);
}
int count(int k, int a, int b) {
	if (k-a*m < 0) return 0;
	int res = c(k-a*m+n, n), tmp = 0;
	printf("%lld %lld %lld = %lld\n", k, a, b, res);
	for (int i = 0; i <= n-m && i*(b+1)+m*a <= k; ++i) {
		mo(tmp += mod(co[i%2]*c(n-m, i))*c(k-(i*(b+1)+m*a) + n, n));
		printf("%lld %lld %lld:%lld = %lld\n", k, a, b, i, tmp);
	}
	mo(res -= tmp*c(n, m));
	printf("%lld %lld %lld = %lld\n", k, a, b, res);
	return res;
}
int count(int k) {
	int res = 0;
	for (int i = 1; i <= k; ++i)
		mo(res += count(k, i, i-1)-count(k, i+1, i-1));
	return res;
}

signed main() {
	fact[0] = 1;
	for (int i = 1; i < maxn; ++i)
		fact[i] = mod(fact[i-1]*i);
	invf[maxn-1] = pow(fact[maxn-1], MOD-2);
	for (int i = maxn-2; ~i; --i)
		invf[i] = mod(invf[i+1]*(i+1));
	cin >> n >> m >> l >> r;
	cout << mod(count(r)-count(l-1)) << endl;
}

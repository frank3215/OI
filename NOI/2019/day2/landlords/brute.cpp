#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long MOD = 998244353, maxn = 100;

namespace brute{
	int inv[maxn], invfact[maxn], fact[maxn];
	int n, m, type, a[maxn], cur[maxn], nxt[maxn];
	void init() {
		inv[1] = 1;
		for (int i = 2; i <= n; ++i) inv[i] = (MOD-(MOD/i)*inv[(MOD%i)]%MOD)%MOD;
		fact[0] = invfact[0] = 1;
		for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
		for (int i = 1; i <= n; ++i) invfact[i] = invfact[i-1]*i;
	}
	long long down(int x, int y) {
		assert(x >= y);
		return (ll)fact[x]*invfact[x-y]%MOD;
	}
	long long invdown(int x, int y) {
		assert(x >= y);
		return (ll)invfact[x]*fact[x-y]%MOD;
	}
	int pow(long long a, int x) {
		return (x?(pow(a*a%MOD, x/2)*(x&1?a:1)):1)%MOD;
	}
	void work() {
		for (int i = 1; i <= m; ++i) cur[i] = pow(i, type);
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int k = 1; k <= n; ++k) {
					if (k <= a[i]) {
						if (a[i]-k+1<=n-j+1)
							nxt[j] = (nxt[j] + cur[k]*(down(a[i], a[i]-k+1)*down(n-a[i], n-a[i]+k-j)%MOD*invdown(n, n-j+1)%MOD)%MOD)%MOD;
					}
					else {
						if (n-k+1 <= n-j+1)
							nxt[j] = (nxt[j] + cur[k]*(down(n-a[i], n-k+1)*down(a[i], k-j)%MOD*invdown(n, n-j+1)%MOD)%MOD)%MOD;
					}
				}
			}
			swap(cur, nxt);
		}
	}
	void solve() {
		scanf("%d%d%d", &n, &m, &type);
		for (int i = 1; i <= m; ++i) scanf("%d", a+i);
		work();
		int q, c;
		scanf("%d", &q);
		while (q--) {
			scanf("%d", &c);
			printf("%d\n", cur[c]);
		}
	}
}

int main() {
	freopen("landlords.in", "r", stdin);
	freopen("landlords.out", "w", stdout);
	brute::solve();
}

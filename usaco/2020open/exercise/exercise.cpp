#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
	ull reduce(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
};
FastMod F(2);

const int N = 7500;

int n, M;

int dp[N], g[N], f[N];

int main() {
	scanf("%d%d", &n, &M); F = FastMod(M);
	for (int i = 2; i <= n; ++i) {
		if (!nop[i]) {
			for (int j = 2*i; j <= n; j += i) {
				nop[j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) if (!nop[i]) {
		for (int j = 1; j <= n; j *= i)
			for (int k = j; k <= n; k += j) {
				if ((k/j)%j != 0) {
					memset(ans, 0, sizeof(ans));
					for (int l = 0; l <= n; ++l) {
						for (int m = 1; l - m*k >= 0; --m) {

						}
					}
				}
			}
	}
}

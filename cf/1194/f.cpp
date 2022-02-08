#include <bits/stdc++.h>
/* denote the probability of solving the first k in t minutes as p(k, t) */
/* the kth crossword is solvable if
 * \sum_{i=1}^k t_i <= T
 * the probability is the the sum of:
 * 1. p(k-1, T-k-1)
 * 2. (p(k-1, T-k)-p(k-1, T-k-1))/2
 */

const int M = 1e9+7;

inline int c(int k, int n) {
	assert(0 <= k && k <= n);
	return (long long)fact[n]*invf[k]%M*invf[n-k]%M;
}

int p(int k, int t) {
	t -= sum[k];
	if (t < 0) return 0;
	int res = 0;
	for (int i = 0; i <= min(t, k); ++i)
		res = (res+c(i, k))%M;
	return res;
}

int main() {
}

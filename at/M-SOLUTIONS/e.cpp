#include <bits/stdc++.h>
#define inv(n) qpow(n, M-2)
using namespace std;

const long long M = 1000003;
typedef long long ll;

int fact[M];

int qpow(long long a, int n) {
	return (n?(qpow(a*a%M, n/2)*(n%2?a:1)):1)%M;
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < M; ++i)
		fact[i] = (ll)fact[i-1]*i%M;

	int q, x, d, n;
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d%d", &x, &d, &n);
		if (d == 0) printf("%d\n", qpow(x, n));
		else {
			int l = (ll)x*inv(d)%M, r = l+(n-1);
			if (r >= M) puts("0\n");
			else printf("%lld\n", (ll)fact[r]*inv(fact[l-1])%M*qpow(d, n)%M);
		}
	}
}

#include <bits/stdc++.h>
using namespace std;

const long long P = 998244353, MX = 3000000;
const int f[] = {2, 1};

int N, M;
long long fact[MX+10], invf[MX+10];

inline long long MOD(long long x, long long M=P) { return (x%M+M)%M; }
inline void SUB(long long &x, long long y) { x = MOD(x-y); }

int qpow(long long a, int k) {
//	printf("a=%lld; k=%d\n", a, k);
	return (k?(qpow(a*a%P, k/2)*((k&1)?a:1)):1)%P;
}

void init() {
	fact[0] = 1;
	for (int i = 1; i <= MX; ++i) fact[i] = fact[i-1]*i%P;
	invf[MX] = qpow(fact[MX], P-2);
	assert(invf[MX]*fact[MX]%P == 1);
	for (int i = MX; i; --i) invf[i-1] = invf[i]*i%P;
}

long long C(int k, int n) {
	assert(0 <= k && k <= n);
	return fact[n]*invf[k]%P*invf[n-k]%P;
//	else printf("%dC%d = %lld\n", k, n, fact[n]*invf[k]%P*invf[n-k]%P);
}

int main() {
	init();
	scanf("%d%d", &N, &M);
	long long ans = C(N-1, 3*M + N-1);
//	printf("%lld\n", ans);
	for (int i = 2*M+1; i <= 3*M; ++i) {
		SUB(ans, N*C(N-2, (3*M-i)+(N-2)));
	}
//	printf("%lld\n", ans);
	for (int i = M+2; i <= N && i <= 3*M; i+=2) {
		SUB(ans, C(i, N)*C(N-1, (3*M-i)/2+(N-1)));
	}
	printf("%lld\n", ans);
}

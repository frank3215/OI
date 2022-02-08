#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int P = 1e9+7, N = 1e5+10;

int fact[N] = {1}, invf[N];

int C(int n, int k) { return 1ll*fact[n]*invf[n-k]%P*invf[k]%P; }
int qpow(long long a, int x) { return (x?qpow(a*a%P,x/2)*(x&1?a:1):1)%P; }

int solve() {
	int n;
	scanf("%d", &n);
	int x[2*n];
	long long sum = 0, ans = 1;
	map<int,int> m;
	for (int i = 0; i < 2*n; ++i) {
		scanf("%d", x+i);
		m[x[i]]++;
		sum += x[i];
	}
	if (sum%(n+1) != 0) return 0;
	sum /= n+1;
	if (m[sum] < 2) return 0;
	m[sum] -= 2, n -= 1;
//	cerr << sum << endl;
	for (auto p: m) {
		if (p.fi*2 > sum) break;
		if (p.se != m[sum-p.fi]) return 0;
		if (p.fi*2 == sum) {
			ans = ans*C(n,p.se/2)%P;
			n -= p.se/2;
		}
		else {
			ans = ans*C(n,p.se)%P*qpow(2,p.se)%P;
			n -= p.se;
		}
	}
	return ans;
}

int main() {
	for (int i = 1; i < N; ++i) fact[i] = (1ll*fact[i-1]*i)%P;
	invf[N-1] = qpow(fact[N-1], P-2);
	for (int i = N-1; i; --i) invf[i-1] = (1ll*invf[i]*i)%P;
	int t;
	scanf("%d", &t);
	while (t--) printf("%d\n", solve());
}

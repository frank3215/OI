#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll qpow(ll b, ll p, ll k) {
	return (p?(qpow(b*b%k, p/2, k)*(p&1?b:1)):1)%k;
}
int main() {
	ll b, p, k;
	scanf("%lld%lld%lld", &b, &p, &k);
	printf("%lld^%lld mod %lld=%lld", b, p, k, qpow(b%k, p, k));
}

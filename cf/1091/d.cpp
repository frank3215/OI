#include <iostream>
const int maxn = 1e6 + 10, mod = 998244353;
int n;
long long ans;
long long prod;
int main() {
	std::cin >> n;
	prod = 1;
	ans = n;
	for (int i = 2; i < n; ++i) {
		prod = prod*(n+2-i)%mod;
		ans = (ans + prod*(n-i)%mod*i)%mod;
	}
	std::cout << ans << std::endl;
}

#include <cstdio>
#define int long long
bool isprime(int n) {
	for (int i = 2; i*i<=n; ++i) {
		if (n%i == 0) return 0;
	}
	return 1;
}
void test() {
	for (int i = 2; i < 1000; ++i) {
		if (isprime(i)) {
			printf("%lld\n", i);
		}
	}
}//ok

signed main() {
	while (~scanf("%lld%lld", &l, &u) && l && u) {
		int pre = 0, ans[2][2]={0,inf,0,0};
		for (int i = l; i <= u; ++i) {
			if (isprime(i)) {
				if (pre) {
					if 
				}
				pre = i;
			}
		}
}

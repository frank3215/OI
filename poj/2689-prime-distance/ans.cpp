#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <algorithm>
using std::vector;
vector<int> p;
const int inf = 1e6+10;
bool isp[inf+10];
int pre, num[2];
int ans[2][2];
void init() {
	memset(isp, 1, sizeof(isp));
	for (int i = 2; i < inf; ++i) {
		if (isp[i]) p.push_back(i);
		for (int j = 2; j*i < inf; ++j) {
			isp[j*i] = 0;
		}
	}
}
int main() {
	init();
	long long l, u;
	while (~scanf("%lld%lld", &l, &u)) {
		memset(isp, 1, sizeof(isp));
		for (int i = 0; i < p.size(); ++i) {
			for (int j = (int)std::max(2ll,(l-1ll+p[i])/p[i]); j <= u/p[i]; ++j) {
				isp[j*p[i]-l] = 0;
			}
		}
		pre = 0;
		num[0] = inf;
		num[1] = 0;
		for (long long i = l; i <= u; ++i) if (isp[i-l]) {
			if (pre) {
				if (i-pre < num[0]) {
					num[0] = i-pre;
					ans[0][0] = pre;
					ans[0][1] = i;
				}
				if (i-pre > num[1]) {
					num[1] = i-pre;
					ans[1][0] = pre;
					ans[1][1] = i;
				}
			}
			pre = i;
		}
		if (num[1])
			printf("%d,%d are closest, %d,%d are most distant.\n", ans[0][0], ans[0][1], ans[1][0], ans[1][1]);
		else puts("There are no adjacent primes.");
	}
}

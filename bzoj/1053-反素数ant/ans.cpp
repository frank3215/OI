#include <cstdio>
const long long p[11] = {1,2,3,5,7,11,13,17,19,23,29};
int n, r[11], ans, num;

void dfs(int x, int sum, int prod) {
	if (sum>num || (sum==num && prod<ans)) {
		ans = prod;
		num = sum;
	}
	r[x] = 0;
	while (prod*p[x]<=n && r[x]<r[x-1]) {
		++r[x];
		prod*=p[x];
		dfs(x+1, sum*(r[x]+1), prod);
	}
}
int main() {
	scanf("%d", &n);
	r[0] = 30;
	dfs(1, 1, 1);
	printf("%d", ans);
}

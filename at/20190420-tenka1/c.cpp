#include <cstdio>
#include <algorithm>
const int maxn = 2e5+10;
char s[maxn+10];
int n, ans, p[maxn];
int main() {
	scanf("%d%s", &n, s+1);
	for (int i = 1; i <= n; ++i) {
		p[i] = p[i-1]+(s[i]=='#');
	}
	ans = 1e9;
	//.(i)#(n-i)
	for (int i = 0; i <= n; ++i) {
		ans = std::min(ans, p[i]+(n-i-(p[n]-p[i])));
	}
	printf("%d\n", ans);
}

#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 1e4 + 10;
int n,k;
int dp[maxn],a[maxn];
int main() {
	freopen("teamwork.in","r",stdin);
	freopen("teamwork.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1; i<=n; ++i) {
		scanf("%d",a+i);
		int mx = a[i];
		for (int j=i-1; ~j && (i-j) <= k; --j) {
			if ((i-j)*mx + dp[j] > dp[i]) dp[i] = dp[j] + (i-j) * mx;
			if (a[j] > mx) mx = a[j];
		}
	}
	printf("%d\n",dp[n]);
}


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1e6+10, MOD = 1e9+7;
int n, h, d;
int a[maxn], sum, b[maxn], s[maxn], ans;

int main() {
	scanf("%d%d%d", &n, &h, &d);
	a[0] = 1;
	for (int i = 1; i <= n; ++i) {
		a[i] = (ll)a[i-1]*i%MOD;
		sum = (ll)(sum+a[i])%MOD;
	}
	for (int i = 1; i <= h; ++i) {
		b[i] = ((s[i-1]-((i-d-1<1)?0:s[i-d-1])+MOD)*(ll)sum+(i<=d))%MOD;
		s[i] = (s[i-1]+b[i])%MOD;
	}
	ans = (ll)b[h]*a[n]%MOD;
	printf("%d\n", ans);
}

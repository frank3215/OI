#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 2e5+10, P = 998244353;

int n, k;
int h[maxn], f[maxn];

int qpow(ll a, int x) { return (x?(qpow(a*a%P, x/2)*(x&1?a:1)):1)%P; }
#define inv(x) qpow(x, P-2)
int C(int n, int k) { return 1ll*f[n]*inv(f[k])%P*inv(f[n-k])%P; }

int main() {
	cin >> n >> k;
	f[0] = 1;
	for (int i = 1; i <= n; ++i) f[i] = 1ll*f[i-1]*i%P;
	for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
	int m = n, ans = 0;
	for (int i = 0; i < n; ++i) if (h[i] == h[(i+1)%n]) m--;
	for (int i = 0; i <= m/2; ++i)
		ans = (ans+1ll*C(m,i)*C(m-i,i)%P*qpow(k-2,m-2*i))%P;
	ans = 1ll*inv(2)*(qpow(k,m)+P-ans)%P;
	ans = 1ll*ans*qpow(k, n-m)%P;
	cout << ans << endl;
}

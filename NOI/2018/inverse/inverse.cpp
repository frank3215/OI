#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sd(x) scanf("%d", &x)
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
#define debug(x) cout << #x << " = " << x << endl
#define print(a,n) cout << #a << " = ";_print(a,n);
void _print(int *a, int n) { FOR(i,0,n) printf("%d%c", a[i], " \n"[i==n-1]); }
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

const int N = 2e6, P = 998244353;

int n, q[N], vis[N];
int ans;

int fact[N], invf[N];
int C(int n, int k) {
	if (k < 0) return 0;
	assert(n >= 0);
	if (k > n) return 0;
	return 1ll*fact[n]*invf[k]%P*invf[n-k]%P;
}
int qpow(int a, int x) {
	int ret = 1;
	for (; x; a = 1ll*a*a%P, x >>= 1)
		if (x&1) ret = 1ll*ret*a%P;
	return ret;
}
int f(int i, int j) {
	return (P+C(n-i+j,j)-C(n-i+j,j-1))%P;
}

void solve() {
	scanf("%d", &n);
	FOR(i,1,n+1) sd(q[i]);
	ans = 0;
	int mx = 0, p2 = 0;
	FOR(i,1,n+1) vis[i] = 0;
	FOR(i,1,n+1) {
		vis[q[i]] = 1;
		bool flag = true;
		if (q[i] > mx) {
			mx = q[i];
		} else {
			while (p2 < q[i]) {
				flag &= vis[++p2];
			}
		}
		if (mx < n) ans = (ans+f(i-1, n-mx-1))%P;
		if (!flag) return;
	}
}

signed main() {
	fact[0] = 1;
	FOR(i,1,N) fact[i] = 1ll*fact[i-1]*i%P;
	invf[N-1] = qpow(fact[N-1], P-2);
	ROF(i,1,N) invf[i-1] = 1ll*invf[i]*i%P;
	freopen("inverse.in", "r", stdin);
	freopen("inverse.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
		printf("%d\n", ans);
	}
}

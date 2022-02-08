#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

const int N = 5e6;

typedef vector<int> vi;
typedef pair<int,int> pii;

unordered_map<int,int> sumphi, summu;

int phi[N], mu[N];
int prime[N], v[N], m;

void init() {
	phi[1] = mu[1] = 1;
	FOR(i,2,N) {
		if (!v[i]) {
			v[i] = i;
			prime[m++] = i;
			phi[i] = i-1;
			mu[i] = -1;
		}
		for (int j = 0; j < m && prime[j] <= v[i] && prime[j]*i < N; ++j) {
			v[i*prime[j]] = prime[j];
			phi[i*prime[j]] = i%prime[j]!=0 ? phi[i]*(prime[j]-1) : phi[i]*prime[j];
			mu[i*prime[j]] = i%prime[j]!=0 ? -mu[i] : 0;
		}
	}
	FOR(i,2,N) {
		phi[i] += phi[i-1];
		mu[i] += mu[i-1];
	}
}

int SumMu(int n) {
	if (n < N) return mu[n];
	if (summu.count(n)) return summu[n];
	int ret = 1;
	for (int l = 2, r; l <= n; l = r+1) {
		r = n/(n/l);
		ret -= (r-l+1)*SumMu(n/l);
	}
	return summu[n] = ret;
}

int SumPhi(int n) {
	if (n < N) return phi[n];
	if (sumphi.count(n)) return sumphi[n];
	int ret = n*(n+1)/2;
	for (int l = 2, r; l <= n; l = r+1) {
		r = n/(n/l);
		ret -= (r-l+1)*SumPhi(n/l);
	}
	return sumphi[n] = ret;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif
	init();
	int t;
	scanf("%lld", &t);
	while (t--) {
		int n;
		scanf("%lld", &n);
		printf("%lld %lld\n", SumPhi(n), SumMu(n));
	}
}

#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;

const int maxn = 1e5+10, maxlogn = 20;

typedef long long ll;
typedef multiset<pair<long long, int> > Set;
typedef Set::iterator It;

int n, x0, m, s, x;
long long h[maxn], g[maxn][maxlogn], sa[maxn][maxlogn], sb[maxn][maxlogn];
int near[maxn][2], f[maxn][maxlogn];
Set S;

void go(ll s, ll x, ll &S, ll &SA, ll &SB) {
//	printf(" %lld %lld\n", s, x);
	S = SA = SB = 0;
	for (int k = maxlogn-1; ~k; --k)
		if (S+g[x][k] <= s) {
			S += g[x][k];
			SA += sa[x][k];
			SB += sb[x][k];
			x = f[x][k];
		}
//	printf(" %lld %lld %lld %lld %lld\n", s, x, S, SA, SB);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", h+i+1);
	}
	for (int i = 0; i < 2; ++i) {
		S.insert(mp((ll)1e18, 0));
		S.insert(mp((ll)-1e18, 0));
	}
	h[0] = -1e18;
	for (int i = n; i; --i) {
		It A = S.lower_bound(mp((ll)h[i], 0)), B = --A; ++A;
		for (int j = 0; j < 2; ++j) {
			near[i][j] = (A->fi-h[i] < h[i]-B->fi ? A++ : B--)->se;
		}
		S.insert(mp((ll)h[i], i));
//		printf("%d %d\n", near[i][0], near[i][1]);
		f[i][0] = near[i][1];
		g[i][0] = sa[i][0] = sa[i][1] = abs(h[f[i][0]]-h[i]);
		f[i][1] = near[f[i][0]][0];
		sb[i][1] = abs(h[f[i][1]]-h[f[i][0]]);
		g[i][1] = sb[i][1]+sa[i][1];
		for (int k = 2; k < maxlogn; ++k) {
			int w = f[i][k-1];
			f[i][k] = f[w][k-1];
			g[i][k] = g[i][k-1]+g[w][k-1];
			sa[i][k] = sa[i][k-1]+sa[w][k-1];
			sb[i][k] = sb[i][k-1]+sb[w][k-1];
		}
//		for (int k = 0; k < maxlogn; ++k) printf("%lld %lld: %lld %lld %lld %lld\n", i, k, f[i][k], g[i][k], sa[i][k], sb[i][k]);
	}
	scanf("%d%d", &x0, &m);
	ll S, A, B, ansA = 1, ansB = 0, s0 = 0;
	for (int i = 1; i <= n; ++i) {
		go(x0, i, S, A, B);
		if (!B) A = 1;
		if (A*ansB < ansA*B || (A*ansB == ansA*B && h[i] > h[s0])) {
			ansA = A;
			ansB = B;
			s0 = i;
		}
//		printf("  %lld %lld %lld\n", ansA, ansB, s0);
	}
	printf("%lld\n", s0);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &x, &s);
		go(s, x, S, A, B);
		printf("%lld %lld\n", A, B);
	}
}

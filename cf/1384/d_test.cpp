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
#define FIO(x) \
	freopen(x ".in", "r", stdin); \
	freopen(x ".out", "w", stdout);
#define print(a,n) cout << #a << " = ";_print(a,n);
void _print(int *a, int n) { FOR(i,0,n) printf("%d%c", a[i], " \n"[i==n-1]); }
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

const int N = 10;

bool x1[N][N], x0[N][N], h1[N][N], h0[N][N];

signed main() {
#ifndef ONLINE_JUDGE
	FIO("a");
#endif
	x1[0][0] = h1[0][0] = 0;
	x0[0][0] = h0[0][0] = 1;
	FOR(o,0,N) {
		FOR(z,0,N) if (o+z) {
			x1[o][z] = x0[o][z] = 0;
			h1[o][z] = h0[o][z] = 1;
			if (o) {
				x1[o][z] |= h0[o-1][z];
				x0[o][z] |= h1[o-1][z];
				h1[o][z] &= x1[o-1][z];
				h0[o][z] &= x0[o-1][z];
			}
			if (z) {
				x1[o][z] |= h1[o][z-1];
				x0[o][z] |= h0[o][z-1];
				h1[o][z] &= x1[o][z-1];
				h0[o][z] &= x0[o][z-1];
			}
		}
	}
	puts("win:");
	FOR(o,0,N) {
		FOR(z,0,N) {
			printf(" %d", (o&1)&&x1[o][z]);
		}
		putchar('\n');
	}
}

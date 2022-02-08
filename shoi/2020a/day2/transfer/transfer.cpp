#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int M = 23, M2 = 12, N = 1e5+10;

int n, m, k;
int d[M][M], a[N];
int f[1<<M], cnt[1<<M], g1[M][1<<M2], g2[M][1<<M2];

inline void cmin(int &x, int y) { if (y < x) x = y; }

signed main() {
	freopen("transfer.in", "r", stdin);
	freopen("transfer.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	FOR(i,0,n) scanf("%d", a+i), a[i]--;
	FOR(i,1,n) d[a[i-1]][a[i]]++;
	FOR(i,0,m) {
		FOR(j,0,1<<min(m,M2)) {
			FOR(k,0,min(m,M2)) if (k != i) {
				if ((j>>k)&1) {
					g1[i][j] += d[k][i];
					g1[i][j] += d[i][k]*::k;
				} else {
					g1[i][j] -= d[i][k];
					g1[i][j] += d[k][i]*::k;
				}
			}
		}
		FOR(j,0,1<<max(m-M2,0)) {
			FOR(k,M2,m) if (k != i) {
				if ((j>>(k-M2))&1) {
					g2[i][j] += d[k][i];
					g2[i][j] += d[i][k]*::k;
				} else {
					g2[i][j] -= d[i][k];
					g2[i][j] += d[k][i]*::k;
				}
			}
		}
	}


	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	FOR(i,1,(1<<m)) {
		cnt[i] = cnt[i>>1] + (i&1);
		FOR(j,0,m) if ((i>>j)&1) {
			cmin(f[i], f[i^(1<<j)]+cnt[i]*(g1[j][i&((1<<M2)-1)] + g2[j][i>>M2]));
		}
	}
	printf("%d\n", f[(1<<m)-1]);
}


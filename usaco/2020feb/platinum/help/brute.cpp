#include <bits/stdc++.h>
#define L first
#define R second
using namespace std;

const int N = 1e5+10, K = 11, P = 1e9+7;

int n, k, ans;
int C[K][K], f[N<<1][K];
pair<int,int> p[N];

void init() {
	for (int i = 0; i <= k; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = C[i-1][j-1]+C[i-1][j];
		}
	}
}

int main() {
	freopen("help.in", "r", stdin);
	freopen("help.out", "w", stdout);
	scanf("%d%d", &n, &k);
	init();
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p[i].L, &p[i].R);
	}
	sort(p, p+n);
	f[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < p[i].L; ++j) {
			for (int l = 0; l <= k; ++l) {
				for (int _ = 0; _ <= l; ++_) {
					(f[p[i].R][l] += 1ll*C[l][_]*f[j][_]%P) %= P;
				}
			}
		}
		for (int j = p[i].L+1; j < p[i].R; ++j) {
			for (int l = 0; l <= k; ++l) {
				(f[p[i].R][l] += f[j][l]) %= P;
			}
		}
		for (int j = p[i].R+1; j <= 2*n; ++j) {
			for (int l = 0; l <= k; ++l) {
				(f[j][l] *= 2) %= P;
			}
		}
/*
		for (int j = 0; j <= 2*n; ++j) if (vis[j]) {
			printf("%d: ", j);
			for (int l = 0; l <= k; ++l) printf("%d%c", f[j][l], " \n"[l==k]);
		}
*/
	}
	for (int i = 1; i <= 2*n; ++i) 
		(ans += f[i][k]) %= P;
	printf("%d\n", ans);
}

#include <bits/stdc++.h>
using namespace std;

const int P = 1e9+7, N = 210;

int n;
char s[N];
int f[N][N][N], g[N][N], nxt[N];

int main() {
	scanf("%d", &n);
	scanf("%s", s+1);
	int l = strlen(s+1);
	nxt[0] = -1;
	for (int i = 1, j; i <= l; ++i) {
		for (j = nxt[i-1]; j != -1 && s[j+1] != s[i]; j = nxt[j]);
		nxt[i] = j+1;
	}
	f[0][0][0] = 1;
	for (int i = 0; i < 2*n; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 0; k < l; ++k) {
				//if (f[i][j][k]) printf("f[%d][%d][%d] = %d\n", i, j, k, f[i][j][k]);
				if (s[k+1] == ')') {
					if (j) (f[i+1][j-1][k+1] += f[i][j][k]) %= P;
					int l = k;
					for (; l != -1 && s[l+1] != '('; l = nxt[l]);
					(f[i+1][j+1][l+1] += f[i][j][k]) %= P;
				} else {
					(f[i+1][j+1][k+1] += f[i][j][k]) %= P;
					int l = k;
					for (; l != -1 && s[l+1] != ')'; l = nxt[l]);
					if (j) (f[i+1][j-1][l+1] += f[i][j][k]) %= P;
				}
			}
		}
	}
	g[0][0] = 1;
	for (int i = 0; i < 2*n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (j) (g[i+1][j-1] += g[i][j]) %= P;
			(g[i+1][j+1] += g[i][j]) %= P;
		}
	}
	int ans = g[2*n][0];
	//printf("%d\n", (ans+P)%P);
	for (int i = 0; i < l; ++i)
		(ans -= f[2*n][0][i]) %= P;
	printf("%d\n", (ans+P)%P);
}

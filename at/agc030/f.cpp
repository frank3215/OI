#include <bits/stdc++.h>
using namespace std;

const int maxn = 305, P = 1e9+7;
typedef long long ll;

int n, a[maxn<<1], b[maxn<<1], v[maxn<<1];
int f[maxn<<1][maxn][maxn];

int dp(int i, int j, int k) {
	if (j < 0 || j >= maxn || k < 0 || k >= maxn) return 0;
	if (i > 2*n) return (j == 0 && k == 0);
	if (v[i]) return dp(i+1,j,k);
	if (f[i][j][k] != -1) return f[i][j][k];
	if (b[i]) {
		f[i][j][k] = ((ll)dp(i+1,j,k+1)+dp(i+1,j-1,k))%P;
	} else {
		f[i][j][k] = ((ll)dp(i+1,j,k-1)+(ll)(j+1)*dp(i+1,j+1,k)+dp(i+1,j,k+1))%P;
	}
	return f[i][j][k];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 2*n; ++i) {
		scanf("%d", a+i);
		if (a[i] != -1) b[a[i]] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (a[2*i] != -1 && a[2*i+1] != -1) {
			v[a[2*i]] = v[a[2*i+1]] = 1;
		}
		if (a[2*i] == -1 && a[2*i+1] == -1) cnt++;
	}
	memset(f, -1, sizeof(f));
	int fact = 1;
	for (int i = 1; i <= cnt; ++i) fact = (ll)i*fact%P;
	cout << (ll)dp(1, 0, 0)*fact%P << endl;
}

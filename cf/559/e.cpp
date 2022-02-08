#include <bits/stdc++.h>
using namespace std;

const int maxn = 105, inf = 1e9;

int n, a[maxn], l[maxn], ans;
pair<int,int> p[maxn];
int f[maxn][maxn*2];
int R[maxn*2], m;
int b[maxn], c[maxn];

void cmax(int &x, int y) { x = max(x,y); }

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p+n);
	for (int i = 1; i <= n; ++i) {
		a[i] = p[i-1].first;
		l[i] = p[i-1].second;
		R[2*i-1] = a[i];
		R[2*i] = a[i]+l[i];
	}
	R[0] = -inf;
	sort(R, R+2*n+1);
	m = unique(R, R+2*n+1)-R;
	for (int i = 1; i <= n; ++i) {
		b[i] = lower_bound(R, R+m, a[i])-R;
		c[i] = lower_bound(R, R+m, a[i]+l[i])-R;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int r = max(c[i+1],j);
			cmax(f[i+1][r], f[i][j] + R[r]-R[max(j,b[i+1])]);
			for (int k = i+1, mx = 0; k <= n; ++k) {
				int r = max(mx, max(j, b[k]));
				cmax(f[k][r], f[i][j] + R[r]-max(R[j],a[k]-l[k]));
				mx = max(mx, c[k]);
			}
		}
	}
	for (int i = 1; i <= n+1; ++i)
		for (int j = 0; j < m; ++j) {
//			printf("f[%d][%d] = %d\n", i, R[j], f[i][j]);
			cmax(ans, f[i][j]);
		}
	cout << ans << endl;
}

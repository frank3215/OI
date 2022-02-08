#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
const double eps = 1e-12;

int n;
double a[maxn][maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= n; ++j)
			scanf("%lf", &a[i][j]);
	}
	for (int i = 0; i < n; ++i) {
		int flag = -1;
		for (int j = i; j < n; ++j) {
			if (abs(a[j][i]) > eps) {
				swap(a[j], a[i]);
				flag = 1;
				break;
			}
		}
		if (flag == -1) return puts("No Solution"), 0;
		for (int j = 0; j < n; ++j) if (j != i) {
			double t = a[j][i]/a[i][i];
			for (int k = 0; k <= n; ++k) {
				a[j][k] -= t*a[i][k];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%.2f\n", a[i][n]/a[i][i]);
	}
}

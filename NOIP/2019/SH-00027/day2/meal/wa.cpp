#include <bits/stdc++.h>
using namespace std;

const int maxn = 100+10, maxm = 2000+10, P = 998244353;

int n, m, a[maxn][maxm];

void brute() {
	long long s[3][3]={}, sum=0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i != j) {
				for (int k = 0; k < n; ++k) {
					s[i][j] = (s[i][j]+a[k][i]*a[k][j])%P;
				}
			}
			else {
				for (int k = 0; k < n; ++k) {
					s[i][j] = (s[i][j]+a[k][i])%P;
				}
			}
//			printf("s[%d][%d]=%lld\n", i, j, s[i][j]);
		}
	}
	for (int k = 0; k < n; ++k) {
		sum += 1ll*a[k][0]*a[k][1]%P*a[k][2]%P;
	}
	cout << (((s[0][0]*s[1][1]-s[0][1])%P+(s[1][1]*s[2][2]-s[1][2])%P+(s[0][0]*s[2][2]-s[0][2])%P +
		s[0][0]*s[1][1]%P*s[2][2]%P-s[0][1]*s[2][2]%P-s[1][2]*s[0][0]%P-s[2][0]*s[1][1]%P+2*sum)%P+P)%P << endl;
}

int main() {
//	freopen("meal.in", "r", stdin);
//	freopen("meal.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	brute();
}

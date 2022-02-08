#include <iostream>
#define int long long
using namespace std;

const int maxn = 410, P = 1e9+7;

int mod(int a) { return a%P; }
int& ADD(int &a, int b) { return a = mod(a+b); }
int mul(int a, int b) { return mod(a*b); }

int n, f[maxn][maxn];

signed main() {
	cin >> n;
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n-i+1; ++j) {
			for (int k = 0; k <= j-1; ++k)
				ADD(f[i][j], mul(f[i-1][j-1-k],f[i-1][k]));
			for (int k = 0; k <= j; ++k)
				ADD(f[i][j], mul(2*j+1,mul(f[i-1][j-k],f[i-1][k])));
			for (int k = 0; k <= j+1; ++k)
				ADD(f[i][j], mul(j*(j+1),mul(f[i-1][j+1-k],f[i-1][k])));
//			printf("f[%lld][%lld] = %lld\n", i, j, f[i][j]);
		}
	}
	cout << f[n][1] << endl;
}

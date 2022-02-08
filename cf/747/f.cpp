#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define printf //printf
#define int long long
using namespace std;

const int N = 16;
const char b16[] = "0123456789abcdef";

int C[N+1][N+1], f[N+1][N+1];
int n, a[N+1];

void init() {
	for (int i = 0; i <= N; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			C[i][j] = C[i-1][j]+C[i-1][j-1];
	}
}

inline int c(int n, int k) {
	if (n < 0 || k < 0 || k > n) return 0;
	return C[n][k];
}

void get(int L) {
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for (int i = 1; i <= N; ++i)
		for (int j = 0; j <= L; ++j) {
			for (int k = 0; k <= min(j, a[i==N?0:i]); ++k)
				f[i][j] += c(j-(i==N), k)*f[i-1][j-k];
			printf("f[%d][%d] = %lld\n", i, j, f[i][j]);
		}
	{
		f[0][0] = 0;
		for (int j = 0; j <= L; ++j) {
			for (int k = 0; k <= min(j, a[0]); ++k)
				f[0][j] += c(j, k)*f[N-1][j-k];
			printf("f[0][%d] = %lld\n", j, f[0][j]);
		}
	}

}

string solve(int k, int t) {
	int len=0, sum=0;
	string ans;
	for (int i = 0; i <= N; ++i) a[i] = t;
	get(N);
	for (len=1; (sum+=f[N][len]) < k; ++len);
	sum -= f[N][len];
	printf("sum=%d\n", sum);
	for (int i = len; i; --i) {
		for (int j = (i==len); j < N; ++j) if (a[j?j:N]) {
			a[j]--;
			get(i-1);
			printf("%d:%d %lld\n", j, sum, f[0][i-1]);
			if (sum + f[0][i-1] >= k) {
				ans += b16[j];
				break;
			}
			sum += f[0][i-1];
			a[j]++;
		}
	}
	return ans;
}

int test() {
	for (int i = 1; i <= 105; ++i) {
		cout << i << ':' << solve(i, 1) << endl;
	}
	return 0;
}

signed main() {
	init();
//	return test();
	int k, t;
	cin >> k >> t;
	cout << solve(k, t) << endl;
}

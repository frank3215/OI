#include <bits/stdc++.h>
#define clear(x) memset(x, 0, sizeof(x))
using namespace std;

const int N = 105;

int a[N][N], c[N][N], r[N][N], C[N], R[N];

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		int n;
		cin >> n;
		clear(c), clear(r), clear(R), clear(C);
		int trace = 0, ansC = 0, ansR = 0;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				cin >> a[j][k];
				if (c[k][a[j][k]]++) C[k] = 1;
				if (r[j][a[j][k]]++) R[j] = 1;
				if (j == k) trace += a[j][k];
			}
		}
		for (int j = 0; j < n; ++j) {
			ansC += C[j];
			ansR += R[j];
		}
		cout << trace << ' ' << ansR << ' ' << ansC << endl;
	}
}

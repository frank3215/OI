#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

int solve(int n, int m) {
	int ans = 0;
	for (int i = 0; i < 1<<(n*m); ++i) {
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < m; ++k) {
				int cnt = 0;
				for (int l = 0; l < 4; ++l) {
					int nj = j+dx[l], nk = k+dy[l];
					if (nj < 0 || nj >= n || nk < 0 || nk >= m) continue;
					cnt += ((i>>(j+k*n))&1) == ((i>>(nj+nk*n))&1);
				}
				if (cnt > 1) goto end;
			}
		ans++;
		end:;
	}
	return ans;
}

int main() {
	for (int i = 1; i <= 5; ++i) {
		for (int j = 1; j <= 5; ++j) {
			cout << solve(i, j) << ' ';
		}
		cout << endl;
	}
}

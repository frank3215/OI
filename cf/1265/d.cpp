#include <bits/stdc++.h>
using namespace std;

int f[4][4], a[4], s[4], t[4], n;
int pre = -1;

bool check(int i, int j) {
	if (a[i] == 0) return false;
	if (pre != -1 && abs(pre-i) != 1) return false;
	for (int k = 0; k < 4; ++k) {
		s[k] = a[k]-(j==k);
		t[k] = a[k]-(i==k);
	}
	f[0][1] = s[0];
	f[1][0] = t[0];
	f[3][2] = s[3];
	f[2][3] = t[3];
	f[1][2] = s[1]-f[1][0];
	f[2][1] = s[2]-f[2][3];
	if (f[1][2] != t[2]-f[3][2] || f[1][2] < 0) return false;
	if (f[2][1] != t[1]-f[0][1] || f[2][1] < 0) return false;
	if (f[2][1] == 0 && i >= 2 && j >= 2 && (a[1]+a[0] != 0)) return false;
	if (f[1][2] == 0 && i <= 1 && j <= 1 && (a[2]+a[3] != 0)) return false;
	return true;
}

void solve() {
	n = 0;
	for (int i = 0; i < 4; ++i) {
		cin >> a[i];
		n += a[i];
	}
	int end = -1;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (check(i, j)) {
//				printf("%d %d\n", i, j);
				end = j;
				break;
			}
		}
		if (~end) break;
	}
	if (end == -1) {
		puts("NO");
		return;
	}
	puts("YES");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (check(j, end)) {
				printf("%d ", j);
				a[j]--;
				pre = j;
				break;
			}
		}
	}
}

int main() {
	solve();
}

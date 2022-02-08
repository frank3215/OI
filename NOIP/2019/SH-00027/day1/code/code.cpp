/*
 * ~8:43-8:45
 */
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const ull tmp = -1;
int n; ull k;

void dfs(int n, ull k) {
	if (n == 0) {
		cout << endl;
		return;
	}
	if (k&(1ull<<(n-1))) {
		cout << '1';
		dfs(n-1, tmp^k);
	}
	else {
		cout << '0';
		dfs(n-1, k);
	}
}

void test() {
	for (n = 1; n <= 3; ++n)
		for (k = 0; k < (1<<n); ++k)
			dfs(n, k);
}

signed main() {
//	test();
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);
	cin >> n >> k;
	dfs(n, k);
}

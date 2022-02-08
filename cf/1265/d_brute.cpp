#include <bits/stdc++.h>
using namespace std;

int a[4];

bool solve(int pre) {
	bool all = 1;
	for (int i = 0; i < 4; ++i) {
		if (a[i]) {
			all = false;
			if (pre != -1 && abs(i-pre) != 1) continue;
			a[i]--;
			bool ok = solve(i);
			a[i]++;
			if (ok) {
//				printf("%d ", i+1);
				return true;
			}
		}
	}
	return all;
}

void dfs(int dep) {
	if (dep == 4) {
//		for (int i = 0; i < 4; ++i) printf("%d ", a[i]);
		puts(solve(-1)?"YES":"NO");
	}
	else for (a[dep] = 0; a[dep] <= 4; ++a[dep])
		dfs(dep+1);
}

int main() {
	dfs(0);
	return 0;
	for (int i = 0; i < 4; ++i) cin >> a[i];
	if (!solve(-1)) cout << "NO";
}

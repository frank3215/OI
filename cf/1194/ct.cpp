#include <bits/stdc++.h>
using namespace std;

bool solve(int n, int k) {
	bool ans[101]={0, 1, 1};
	for (int i = 3; i <= n; ++i) {
		ans[i] = !(ans[i-1]&&ans[i-2]&&(i>=k?ans[i-k]:1));
	}
	return ans[n];
}

int main() {
	for (int i = 3; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			printf(solve(j,i)?"#":" ");
		}
		puts("");
	}
}

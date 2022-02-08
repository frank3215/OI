#include <bits/stdc++.h>
using namespace std;

int main() {
	int l, r;
	scanf("%d%d", &l, &r);
	int ans = 2019;
	int start = l%2019, end = start+min(2019*2, r-l+1);
	for (int i = start; i < end; ++i) {
		for (int j = i+1; j < end; ++j) {
			ans = min(i*j%2019, ans);
		}
	}
	printf("%d\n", ans);
}

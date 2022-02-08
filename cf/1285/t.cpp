#include <bits/stdc++.h>
using namespace std;

int factor(int x) {
	int ret = 1;
	for (int i = 2; i*i <= x; ++i) {
		int cnt = 0;
		while (x%i == 0) {
			cnt++;
			x /= i;
		}
		ret *= (cnt+1);
	}
	if (x != 1) ret *= 2;
	return ret;
}

int main() {
	int ans = 0;
	for (int i = 1; i <= 1e5; ++i)
		ans = max(ans, factor(i));
	cout << ans << endl;
}

#include <bits/stdc++.h>

using namespace std;

int tot;

int main() {
	srand(time(NULL));
	for (int i = 0; i < 100000; ++i) {
		int cnt[21] = {}, mn = 100, mx = 0;
		for (int j = 0; j < 100; ++j) {
			cnt[rand()%20]++;
		}
		for (int j = 0; j < 10; ++j) {
			mn = min(mn, cnt[j]);
			mx = max(mx, cnt[j]);
		}
		if (cnt[0] < mn + 5) {
//			printf("%d %d\n", mn, mx);
			++tot;
		}
	}
	printf("%d", tot);
}

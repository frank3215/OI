#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

const int N = 200;
bitset<N> sums;
bitset<N> cur;
bitset<N> res;

void solve(int i, int h) {
	if (i == h) {
		if (cur.count() > res.count()) res = cur;
	} else {
		if (! sums[i]) {
			sums[i] = 1;
			if ((sums & (cur << i)).count() == 0) {
				sums ^= (cur << i);
				cur[i] = 1;
				solve(i+1, h);
				cur[i] = 0;
				sums ^= (cur << i);
			}
			sums[i] = 0;
		}
		solve(i+1, h);
	}
}

int main() {
	int pc = 0;
	for (int h = 1; pc < 9; ++h) {
		solve(1, h);
		if (res.count() > pc) {
			pc = res.count();
			for (int j = 1; j <= h; ++j) {
				if (res[j] == 1) cout << j << ' ';
			}
			cout << '\n';
		}
	}
}

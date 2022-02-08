#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, d, ans = 0;
	cin >> m >> d;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= d; ++j)
			ans += (j/10 >= 2) && (j%10 >= 2) && ((j/10)*(j%10) == i);
	cout << ans;
}

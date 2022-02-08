#include <bits/stdc++.h>
using namespace std;

int n, res;
int h[100010], ans[100010];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> h[i];
	for (int i = n-2; ~i; --i) {
		if (h[i] >= h[i+1])
			res = max(res, ans[i] = ans[i+1]+1);
	}
	cout << res;
}

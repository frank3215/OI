#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, h;
	cin >> h >> n;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
	cout << (sum>=h?"Yes":"No") << endl;
	return 0;
}

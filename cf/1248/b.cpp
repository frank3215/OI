#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	long long ans = 0, sum = 0;
	for (int i = 0; i < (int)a.size()/2; ++i) sum += a[i];
	ans += sum*sum;
	sum = 0;
	for (int i = a.size()/2; i < (int)a.size(); ++i) sum += a[i];
	cout << (ans+=sum*sum) << endl;
}

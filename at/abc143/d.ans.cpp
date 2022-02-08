#include <bits/stdc++.h>
using namespace std;

int n, a[2001], ans;
int b[2001];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[a[i]]++;
	}
	for (int i = 1; i <= 2000; ++i) {
		b[i] += b[i-1];
		for (int j = b[i-1]; j < b[i]; ++j)
			a[j] = i;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			ans += b[a[i]+a[j]-1]-i-1;
	cout << ans;
}

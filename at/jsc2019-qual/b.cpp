#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int a[2010];

int main() {
	int n, k;
	long long ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i] > a[j])
				ans = (ans+((i>j)?((k-1ll)*k/2):((k+1ll)*k/2)))%MOD;
	cout << ans << endl;
}

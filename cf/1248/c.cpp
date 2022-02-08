#include <bits/stdc++.h>
using namespace std;

const int P = 1e9+7;

int dp[100010] = {0, 2, 4}, sum[100010] = {0, 2, 6};

int main() {
	int n, m;
	cin >> n >> m;
	if (n < m) swap(n, m);
	for (int i = 3; i <= n; ++i) {
		dp[i] = (dp[i-1]+dp[i-2])%P;
	}
	cout << ((dp[n]+dp[m]-dp[1])%P+P)%P << endl;
}

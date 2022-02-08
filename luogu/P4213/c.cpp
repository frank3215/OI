#include <bits/stdc++.h>

#define printf //printf
const int sqrtn = 1e5;

long long N, t;

long long f[2][2][sqrtn];
bool vis[2][2][sqrtn];

long long sum_phi(long long n) {
	if (n<sqrtn && vis[0][0][n]) return f[0][0][n];
	else if (n>=sqrtn && vis[0][1][N/n]) return f[0][1][N/n];
	
//	std::cout << n << std::endl;

	long long ans = 0;
	ans += n*(n+1)/2;
	for (int l = 1; l < n; ) {
		++l;
		int d = n/l, r = n/d;
		ans -= (r-l+1ll)*sum_phi(d);
		l = r;
	}

	if (n<sqrtn) vis[0][0][n] = 1, f[0][0][n] = ans;
	else vis[0][1][N/n] = 1, f[0][1][N/n] = ans;
	return ans;
}

long long sum_mu(long long n) {
	if (n<sqrtn && vis[1][0][n]) return f[1][0][n];
	else if (n>=sqrtn && vis[1][1][N/n]) return f[1][1][N/n];

	long long ans = 0;
	ans += 1;
	for (int l = 1; l < n; ) {
		++l;
		int d = n/l, r = n/d;
		ans -= (r-l+1ll)*sum_mu(d);
		l = r;
	}

	if (n<sqrtn) vis[1][0][n] = 1, f[1][0][n] = ans;
	else vis[1][1][N/n] = 1, f[1][1][N/n] = ans;
	return ans;
}

int main() {
	std::cin >> t;
	while (t--) {
		memset(vis, 0, sizeof(vis));

		std::cin >> N;
		long long ans1 = sum_phi(N), ans2 = sum_mu(N);
		std::cout << ans1 << ' ' << ans2 << std::endl;
	}
}

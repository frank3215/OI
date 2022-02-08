#include <bits/stdc++.h>

#define printf //printf
const int MX = 2e7;

long long N, t;

int phi[MX], mu[MX];
long long phi_0[MX], phi_1[INT_MAX/MX];
int mu_0[MX], mu_1[INT_MAX/MX];
bool vis_phi_1[INT_MAX/MX], vis_mu_1[INT_MAX/MX];

bool nop[MX+10];
std::vector<int> p;

void init() {
	int tmp;
	phi[1] = mu[1] = 1;
	for (int i = 2; i <= MX; ++i) {
		if (!nop[i]) {
			p.push_back(i);
			phi[i] = i-1;
			mu[i] = -1;
		}
		for (int j = 0; j < p.size() && i <= MX/p[j]; ++j) {
			nop[tmp=i*p[j]] = 1;
			if (i%p[j]) {
				phi[tmp] = phi[i]*phi[p[j]];
				mu[tmp] = -mu[i];
			}
			else {
				phi[tmp] = phi[i]*p[j];
				mu[tmp] = 0;
				break;
			}
		}
	}
	for (int i = 1; i <= MX; ++i) {
		mu_0[i] = mu_0[i-1] + mu[i];
		phi_0[i] = phi_0[i-1] + phi[i];
	}
}

long long sum_phi(int n) {
	if (n<MX) return phi_0[n];
	else if (n>=MX && vis_phi_1[N/n]) return phi_1[N/n];

	long long ans = 0;
	int d, r;
	ans += n*(n+1ll)/2;
	for (int l = 1; l < n; ) {
		++l;
		d = n/l, r = n/d;
		ans -= (r-l+1ll)*sum_phi(d);
		l = r;
	}

	vis_phi_1[N/n] = 1, phi_1[N/n] = ans;
	return ans;
}

int sum_mu(int n) {
	if (n<MX) return mu_0[n];
	else if (n>=MX && vis_mu_1[N/n]) return mu_1[N/n];

	int ans = 0;
	int d, r;
	ans += 1;
	for (int l = 1; l < n; ) {
		++l;
		d = n/l, r = n/d;
		ans -= (r-l+1ll)*sum_mu(d);
		l = r;
	}

	vis_mu_1[N/n] = 1, mu_1[N/n] = ans;
	return ans;
}

int main() {
	init();
	std::cin >> t;
	while (t--) {
		memset(vis_phi_1, 0, sizeof(vis_phi_1));
		memset(vis_mu_1, 0, sizeof(vis_mu_1));

		std::cin >> N;
		long long ans1 = sum_phi(N), ans2 = sum_mu(N);
		std::cout << ans1 << ' ' << ans2 << std::endl;
	}
}

#include <cstdio>
void euler() {
	memset(isp, 1, sizeof(isp));
	for (int i = 2; i <= n; ++i) {
		if (isp[i]) p.push_back(i);
		for (int j = 0; j < p.size() && p[j]*i <= n; ++j) {
			isp[p[j]*i] = 0;
			if (p[j]%i == 0) break;
		}
	}
}
int main() {
}

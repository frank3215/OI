#include <cstdio>
#include <cstring>
#include <vector>
const int maxn = 1e6+10;
int n;
bool isp[maxn];
std::vector<int> p;
void eratos() {
	memset(isp, 1, sizeof(isp));
	for (int i = 2; i <= n; ++i) {
		if (isp[i]) {
			for (int j = 2; j <= n/i; ++j) isp[i*j] = 0;
			p.push_back(i);
		}
	}
}
int count(int x, int p) {
	int res = 0;
	while (x) res += (x /= p);
	return res;
}
void solve() {
	for (int i = 0; i < p.size(); ++i) {
		printf("%d %d\n", p[i], count(n, p[i]));
	}
}
int main() {
	scanf("%d", &n);
	eratos();
	solve();
}

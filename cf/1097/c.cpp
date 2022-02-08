#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

const int maxn = 1e5 + 10, maxv = 5e5 + 10;
int n, ans;
int cnt[2*maxv];
std::string s;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		std::cin >> s;
		int v = 0, mn = 0;
		for (int j = 0; j < s.size(); ++j) {
			if (s[j] == ')') {
				mn = std::min(mn, --v);
			}
			if (s[j] == '(') {
				++v;
			}
		}
		if ((v < 0 && mn == v) || (v >= 0 && mn == 0))  {
			if (cnt[maxv - v]) {
				++ans;
				--cnt[maxv - v];
			}
			else {
				++cnt[maxv + v];
			}
		}
	}
	printf("%d\n", ans);
}


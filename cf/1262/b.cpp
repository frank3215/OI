#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int maxn = 1e5+10;

int n, p[maxn], a[maxn];
set<int> s;

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
		s.insert(i);
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] != a[i-1]) {
			p[i] = a[i];
			s.erase(a[i]);
		} else {
			if (*s.begin() > a[i]) {
				puts("-1");
				return;
			}
			p[i] = *s.begin();
			s.erase(s.begin());
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", p[i], " \n"[i==n]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}

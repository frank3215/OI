#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxn = 1e4+10, base[2] = {131, 151}, mod[2] = {998244353, 1000000007};

int n, m;
char s[maxn];
vector<int> val[maxn];
int p[maxn];

bool cmp(int i, int j) {
	return val[i] < val[j];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		p[i] = i;
		val[i] = vector<int>(2);
		for (int j = 0; s[j]; ++j) {
			for (int k = 0; k < 2; ++k) {
				val[i][k] = ((ll)val[i][k]*base[k]+s[j])%mod[k];
			}
		}
	}
	sort(p, p+n, cmp);
	int ans = n;
	for (int i = 1; i < n; ++i) {
		if (!cmp(p[i-1], p[i])) ans--;
	}
	printf("%d\n", ans);
}

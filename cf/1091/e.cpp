#include <cstdio>
#include <cstring>
#include <vector>
const int maxn = 5e5 + 10;
int n, tot, ok = 1;
int d[maxn], a[maxn], b[maxn], aa[maxn], p[maxn];
long long pre[maxn], suf[maxn], ge, le;
std::vector<int> v[maxn];
bool cmp(const int &x, const int &y) {
	return a[x] > a[y];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", d + i);
	}
	std::sort(a+1, a+n+1);
	for (int i = 1; i <= n; ++i) {
		a[i] = std::min(d[i], i-1);
		p[a[i]]++;
//		b[i] = i;
		pre[i] = pre[i-1] + d[i];
	}
//	std::sort(b + 1, b + n + 1, cmp);
	tot = v[n].size();
	long long cur = 0;
	ge = pre[n] - n*(n-1);
	le = n;
	for (int k = n-1; k; --k) {
		tot += p[k+1];
		suf[k] = suf[k+1] + a[k+1] - tot;
		cur = pre[k] - k*(k-1) - suf[k];
		if (cur > k) ok = 0;
		if(k) ge = std::max(ge, std::max((long long)d[k], cur));
		le = std::min(le, std::min((long long)d[k], std::min(d[k],k) + d[k] - cur));
		printf("%d:%lld\n",k,suf[k]);
		printf("%lld, %lld\n",ge,le);
	}
}

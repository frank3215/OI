#include <bits/stdc++.h>
const int maxn = 5e5+10;
int n, k, cur[maxn];
long long a[maxn], ans;
namespace trie{
	int ch[maxn<<5][2], t[maxn<<5], tot = 1;
	void add(long long n) {
		for (long long w = 1ll<<31, u = 1; w; w>>=1) {
			bool b = w&n;
			if (!ch[u][b]) ch[u][b] = ++tot;
			++t[u=ch[u][b]];
		}
	}
	long long find(long long n, int rank) {
		long long res = 0;
		for (long long w = 1ll<<31, u = 1; w; w>>=1) {
			bool b = w&n;
			if (t[ch[u][!b]] >= rank) {
				u = ch[u][!b];
				res |= w;
			}
			else {
				rank -= t[ch[u][!b]];
				u = ch[u][b];
			}
		}
		return res;
	}
}
std::priority_queue<std::pair<long long, int> > q;
int main() {
//	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	trie::add(0);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld",&a[i]);
		a[i] = a[i-1]^a[i];
		trie::add(a[i]);
	}
	for (int i = 0; i <= n; ++i) {
		q.push(std::make_pair(trie::find(a[i], cur[i]=1), i));
	}
	for (int i = 0; i < (k<<1); ++i) {
		std::pair<long long, int> p = q.top(); q.pop();
		if (i&1) ans += p.first;
		int j = p.second;
		if (++cur[j] < n) {
			q.push(std::make_pair(trie::find(a[j], cur[j]), p.second));
		}
	}
	printf("%lld\n", ans);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;
typedef long long ll;

int n, m;
int a[maxn], b[maxn], inv[maxn];

struct BIT{
	ll t[maxn];
	void add(int x, int d) {
		assert(x > 0);
		for (; x < maxn; x += x&-x) {
			t[x] += d;
		}
	}
	ll sum(int x) {
		assert(x < maxn);
		ll ret = 0;
		for (; x; x -= x&-x) {
			ret += t[x];
		}
		return ret;
	}
}t1, t2;

int main() {
	freopen("bubble.in", "r", stdin);
	freopen("bubble.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a+i);
		b[i] = inv[a[i]] = (i-1)-t1.sum(a[i]);
		t1.add(a[i], 1);
	}
	sort(b+1, b+n+1);
	for (int i = 1; i <= n; ++i) {
		t2.add(i, b[i]);
	}
	for (int i = 1; i <= m; ++i) {
		int t, c;
		scanf("%d%d", &t, &c);
		if (t == 1) {
			if (a[c] < a[c+1]) {
				int x = upper_bound(b+1, b+n+1, inv[a[c]])-b-1;
				assert(b[x] == inv[a[c]]);
				b[x]++, inv[a[c]]++, t2.add(x, 1);
			} else {
				int x = lower_bound(b+1, b+n+1, inv[a[c+1]])-b;
				assert(b[x] == inv[a[c+1]]);
				b[x]--, inv[a[c+1]]--, t2.add(x, -1);
			}
			swap(a[c], a[c+1]);
		} else {
			int x = upper_bound(b+1, b+n+1, c)-b;
//			printf("%d: ", x);
			printf("%lld\n", (t2.sum(n)-t2.sum(x-1))-1ll*(n+1-x)*c);
		}
	}
}

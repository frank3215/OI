#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int Q = 2e6+10, P = 1<<20;

int q;
int op[Q], t[Q], x[Q], y[Q], k[Q];
int a[Q];

struct BIT{
	int t[Q];
	void add(int x, int d) {
		for (; x < Q; x += x&-x) t[x] += d;
	}
	int sum(int x) {
		int ret = 0;
		for (; x; x -= x&-x) ret += t[x];
		return ret;
	}
	int min_g(int x) {
		int sum = 0, cur = 0;
		for (int k = P; k; k >>= 1) if (cur+k < Q && sum+t[cur+k] <= x) {
			sum += t[cur+=k];
		}
		return cur+1;
	}
	int max_le(int x) {
		return min_g(x)-1;
	}
}A, B, AB;

int sumA, sumB;

#define debug printf

signed main() {
	freopen("icefire.in", "r", stdin);
	freopen("icefire.out", "w", stdout);
	scanf("%lld", &q);
	int m = 0;
	for (int i = 1; i <= q; ++i) {
		scanf("%lld", &op[i]);
		if (op[i] == 1) {
			scanf("%lld%lld%lld", t+i, x+i, y+i);
			a[++m] = x[i];
		} else {
			scanf("%lld", k+i);
		}
	}
	sort(a+1, a+m+1);
	m = unique(a+1, a+m+1)-(a+1);
	B.add(m+2, 1);
	AB.add(m+2, 1);
	for (int i = 1; i <= q; ++i) {
		if (op[i] == 1) {
			x[i] = lower_bound(a+1, a+m+1, x[i])-a;
		}
	}
	//debug("unique: %lld\n", m);
	for (int i = 1; i <= q; ++i) {
		if (op[i] == 1) {
			if (t[i] == 0) A.add(x[i], y[i]), sumA+=y[i];
			if (t[i] == 1) B.add(x[i]+1, y[i]), sumB+=y[i];
			AB.add(x[i]+(t[i]==1), y[i]);
		} else {
			if (t[k[i]] == 0) A.add(x[k[i]], -y[k[i]]), sumA-=y[k[i]];
			if (t[k[i]] == 1) B.add(x[k[i]]+1, -y[k[i]]), sumB-=y[k[i]];
			AB.add(x[k[i]]+(t[k[i]]==1), -y[k[i]]);
		}
		int ans = 0, power = 0;
		int ret1 = AB.min_g(sumB), ret2 = ret1-1; ret1 = B.max_le(B.sum(ret1));
		int ans1 = min(A.sum(ret1), sumB-B.sum(ret1));
		if (ans1 > power || (ans1 == power && ret1 > ans)) power = ans1, ans = ret1;
		int ans2 = min(A.sum(ret2), sumB-B.sum(ret2));
		if (ans2 > power || (ans2 == power && ret2 > ans)) power = ans2, ans = ret2;
		if (!power) puts("Peace");
		else printf("%lld %lld\n", a[ans], power*2);
	}
}

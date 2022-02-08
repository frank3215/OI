#include <bits/stdc++.h>
#define us long long
const int maxn = 5e5+10;
const us inf = (1ll<<32)-1;
int n, k;
us a[maxn], s[maxn];
long long ans;
namespace tr{
	int ch[maxn<<6][2], t[maxn<<6], tot=1, rt[maxn];
	int add(int u, us l, us r, us x) {
		int v = ++tot;
		t[v] = t[u] + 1;
		ch[v][0] = ch[u][0];
		ch[v][1] = ch[u][1];
		if (l == r) return v;
		us m = (l+r)>>1;
		if (x <= m) ch[v][0] = add(ch[u][0], l, m, x);
		else ch[v][1] = add(ch[u][1], m+1, r, x);
		return v;
	}
	us find(int u, us x, int k) {
		us ans = 0;
		for (int i = 31; ~i; --i) {
			bool b = x&(1ll<<i);
			if (t[ch[u][!b]] >= k) {
				u = ch[u][!b];
				ans ^= (1u<<i);
			}
			else {
				k -= t[ch[u][!b]];
				u = ch[u][b];
			}
		}
		return ans;
	}
}
struct node{
	int i, k;
	us v;
	node(int I, int K, us V) {
		i = I, k = K;
		v = V;
	}
	bool operator < (const node &n) const {
		return v < n.v;
	}
};
std::priority_queue<node> q;
void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a+i);
		s[i] = s[i-1]^a[i];
		tr::rt[i] = tr::add(tr::rt[i-1], 0, inf, s[i-1]);
		q.push(node(i, 1, tr::find(tr::rt[i], s[i], 1)));
	}
	while (k--) {
		node u = q.top(); q.pop();
		ans += u.v;
		if (u.i > u.k) {
			q.push(node(u.i, u.k+1, tr::find(tr::rt[u.i], s[u.i], u.k+1)));
		}
	}
	printf("%lld\n", ans);
}
int main() {
	solve();
}

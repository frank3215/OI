#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;

set<int> s;
set<int>::iterator lmid;
long long inv, ans;
int n, a[maxn], pos[maxn];

struct BIT{
	int t[maxn];
	void add(int x, int y=1) {
		for (; x < maxn; x += x&-x) t[x] += y;
	}
	int sum(int x) {
		int ret = 0;
		for (; x; x -= x&-x) ret += t[x];
		return ret;
	}
	int query(int l, int r) {
		return sum(r)-sum(l);
	}
}t;

#define back(s) prev(s.end())

void add(int x) {
	ans -= min(t.sum(x), t.sum(n)-t.sum(x));
	t.add(x);
	s.insert(x);
	if (lmid != s.end()) {
		if (x < *lmid && s.size()%2==0) --lmid;
		if (x > *lmid && s.size()%2==1) lmid++;
	} else lmid = s.begin();
	if (s.size()%2==0) {
		if (x <= *lmid) {
			ans += (*next(lmid)-x)-t.query(x,*next(lmid));
		} else {
			ans += (x-*lmid)-t.query(*lmid,x);
		}
	}
	if (s.size()%2==1) {
//		cout << endl << *lmid << ' ' << x << ' ' << t.query(x,*lmid) << endl;
		if (x <= *lmid) {
			ans += (*lmid-x)-t.query(x,*lmid);
		} else {
			ans += (x-*lmid)-t.query(*lmid,x);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	lmid = s.begin();
	for (int i = 1; i <= n; ++i) {
		inv += t.sum(n)-t.sum(pos[i]);
		add(pos[i]);
//		cout << endl << ans << ' ' << inv << endl;
		cout << ans+inv << ' ';
	}
}

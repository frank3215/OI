#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 2e5+10;
int n, m, a[maxn], t[maxn], ans[maxn];
pair<int, int> p[maxn];
vector<pair<int, int> > q[maxn];

void add(int x, int k=1) {
	for (; x < maxn; x += x&-x)
		t[x] += k;
}
int kth(int k) {
	int sum = 0, i = 0;
	for (int j = 20; ~j; --j) {
		i += 1<<j;
		if (i < maxn && t[i]+sum < k) sum += t[i];
		else i -= 1<<j;
	}
	return i+1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
		p[i] = make_pair(-a[i], i);
	}
	scanf("%d", &m);
	int k, pos;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &k, &pos);
		q[k-1].push_back(make_pair(i, pos));
	}
	sort(p, p+n);
	for (int i = 0; i < n; ++i) {
		add(p[i].second+1);
		for (int j = 0; j < (int)q[i].size(); ++j) {
			ans[q[i][j].first] = kth(q[i][j].second);
		}
	}
	for (int i = 0; i < m; ++i)
		printf("%d\n", a[ans[i]-1]);
}

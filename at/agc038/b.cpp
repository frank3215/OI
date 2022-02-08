#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10, maxlogn = 19;
int n, k;
int p[maxn];

namespace brute{
	vector<int> pp, q;
	set<vector<int> > st;
	int main() {
		st.clear();
		pp = vector<int>(p+1, p+n+1);
		for (int i = 0; i+k<=n; ++i) {
			q = pp;
			sort(q.begin()+i, q.begin()+i+k);
			st.insert(q);
		}
		return st.size();
	}
}

namespace ST{
	int mn[maxn][maxlogn], mx[maxn][maxlogn], lg[maxn];
	void init() {
		lg[0] = -1;
		for (int i = 1; i <= n; ++i) {
			mn[i][0] = mx[i][0] = p[i];
			lg[i] = lg[i/2]+1;
		}
		mn[n+1][0] = -n-1;
		mx[n+1][0] = n+1;
		for (int j = 1; j < maxlogn; ++j)
			for (int i = 1; i+(1<<(j-1)) <= n; ++i) {
				mn[i][j] = min(mn[i][j-1], mn[i + (1<<(j-1))][j-1]);
				mx[i][j] = max(mx[i][j-1], mx[i + (1<<(j-1))][j-1]);
			}
	}
	int min(int l, int r) {
		int t = lg[r-l+1];
		return std::min(mn[l][t], mn[r-(1<<t)+1][t]);
	}
	int max(int l, int r) {
		int t = lg[r-l+1];
		return std::max(mx[l][t], mx[r-(1<<t)+1][t]);
	}
}

int solve() {
	ST::init();
	bool same = 0;
	int ans = 0, streak = 1;
	for (int i = 1; i < k; ++i)
		if (p[i] < p[i+1]) streak++;
		else streak = 1;
	for (int i = k; i <= n; ++i) {
		if (streak >= k) same = 1;
		else if (i > k && p[i-k] < ST::min(i-k+1, i-1) && ST::max(i-k+1, i-1) < p[i]);
		else ans++;
		if (p[i] < p[i+1]) streak++;
		else streak = 1;
	}
//	printf("%d %d %d\n", ans, streak, same);
	return ans+same;
}

bool test() {
	srand(time(NULL));
	n = 1000;
	k = 300;
	for (int i = 1; i <= n; ++i)
		p[i] = i;
	random_shuffle(p+1, p+n+1);
	return solve() == brute::main();
}

int main() {

	while (test());
	for (int i = 1; i <= n; ++i)
		printf("%d%c", p[i], " \n"[i==n]);
	printf("%d %d\n", solve(), brute::main());
	exit(0);

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", p+i);
	printf("%d\n", solve());
}

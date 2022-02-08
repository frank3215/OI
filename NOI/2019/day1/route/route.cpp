#include <bits/stdc++.h>
using namespace std;

#define debug printf
#define S second
#define F first

const long long inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5+10, maxm = 2e5+10;
typedef long long ll;
typedef map<int, long long>::iterator IT;

int n, m, A, B, C;
int f[maxn];
map<int, long long> mp[maxn];

struct edge{
	int x, y, p, q;
	void scan() {
		scanf("%d%d%d%d", &x, &y, &p, &q);
	}
	void print() {
		printf("%d %d %d %d\n", x, y, p, q);
	}
}e[maxm];

template<typename T>
void minn(T &x, T y) { if (y < x) x = y; } 
bool cmp1(edge e1, edge e2) { return e1.p < e2.p; }
//bool cmp2(edge e1, edge e2) { return e1.x < e2.x; }
long long calc(long long x) { return A*x*x + B*x + C; }

// Easy ones
void solvechain() {
	sort(e, e+m, cmp1);
	long long ans = 0;
	int prev = 0;
	for (int i = 0; i < m; ++i) {
		ans += calc(e[i].p-prev);
		prev = e[i].q;
		debug("%lld\n", ans);
	}
	printf("%lld\n", ans+prev);
}
void solveabc() {
	memset(f, 0x3f, sizeof(f));
	f[1] = 0;
	sort(e, e+m, cmp1);
	for (int i = 0; i < m; ++i) {
		if (f[e[i].x] <= e[i].p)
			minn(f[e[i].y], e[i].q);
	}
	printf("%d\n", f[n]);
}

// LEGACY
void printAB(int i) {
	if (mp[i].empty()) return;
	debug("SET %d\n", i);
	for (IT it = mp[i].begin(); it != mp[i].end(); ++it) {
		debug(" %d %lld\n", it->first, it->second);
	}
	debug("END\n");
}
void updateAB(int i, int a, long long b) {
	if (mp[i].empty()) {
		mp[i][a] = b;
		return;
	}
	else {
		IT up = mp[i].upper_bound(a);
		if (up != mp[i].begin() && (--up)->second < b) return;
		mp[i][a] = b;
		while ((up = mp[i].upper_bound(a)) != mp[i].end()) {
			if (up->second > b) mp[i].erase(up);
			else return;
		}
	}
}
void solveab() {
	sort(e, e+m, cmp1);
	mp[1][0] = 0;
	for (int i = 0; i < m; ++i) {
		IT it = mp[e[i].x].upper_bound(e[i].p);
		if (it != mp[e[i].x].begin()) {
//			e[i].print();
//			printAB(e[i].x);
			long long nval = (--it)->second+C;
			updateAB(e[i].y, e[i].q, nval);
		}
	}
	long long ans = inf;
	for (IT it = mp[n].begin(); it != mp[n].end(); ++it) {
		ans = min(ans, it->first + it->second);
	}
	printf("%lld", ans);
}

void solveA() {
	sort(e, e+m, cmp1);
	mp[1][0] = 0;
	for (int i = 0; i < m; ++i) {
		IT it = mp[e[i].x].upper_bound(e[i].p);
		if (it != mp[e[i].x].begin()) {
//			e[i].print();
//			printAB(e[i].x);
			long long nval = (--it)->second + C + e[i].q + B*e[i].p;
			nval -= (B+1)*e[i].q;
			updateAB(e[i].y, e[i].q, nval);
		}
	}
	long long ans = inf;
	assert(!mp[n].empty());
	for (IT it = mp[n].begin(); it != mp[n].end(); ++it) {
		ans = min(ans, (B+1)*it->first + it->second);
	}
	printf("%lld", ans);
}

int main() {
	freopen("route.in", "r", stdin);
	freopen("route.out", "w", stdout);
	scanf("%d%d%d%d%d", &n, &m, &A, &B, &C);
	bool chain = (m == n-1);
	for (int i = 0; i < m; ++i) {
		e[i].scan();
		chain &= (e[i].x+1 == e[i].y);
	}
	if (chain) solvechain();
//	else if (A == 0 && B == 0 && C == 0) solveabc();
//	else if (A == 0 && B == 0) solveab();
	else if (A == 0) solveA();
}

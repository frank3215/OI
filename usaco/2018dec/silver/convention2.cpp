#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
const int maxn = 1e5+10;
int n,ans,cur;
struct cow{
	int a,t,p;
	bool operator <(const cow &c) const {
		return p > c.p;
	}
}c[maxn];
bool cmp_a(const cow &c1, const cow &c2){
	return c1.a < c2.a;
}
int main() {
	std::ifstream fin("convention2.in");
	std::ofstream fout("convention2.out");
	fin >> n;
	for (int i = 0; i < n; ++i) {
		c[i].p = i + 1;
		fin >> c[i].a >> c[i].t;
	}
	std::sort(c, c + n, cmp_a);
	std::priority_queue<cow> q;
	for (int i = 0, j = 0; i < n; ++i) {
		if (q.empty()) {
			cur = c[j].a;
			q.push(c[j++]);
		}
		cow cc = q.top(); q.pop();
		std::cout << cur << ':' << cc.a << ' ' << cc.t << std::endl;
		ans = std::max(cur-cc.a, ans);
		std::cout << ans << std::endl;
		cur += cc.t;
		while (j < n && c[j].a < cur) q.push(c[j++]);
	}
	fout << ans << std::endl;
}

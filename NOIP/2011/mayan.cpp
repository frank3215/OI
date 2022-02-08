#include <bits/stdc++.h>
using namespace std;

int n;
struct op{ int x, y, g; };
vector<op> ans;
static int tmp[5][8], pt;
int tot;

struct state{
	int b[5][8];
	void print() const {
		for (int j = 6; ~j; --j)
			for (int i = 0; i < 5; ++i)
				printf("%d%c", b[i][j], " \n"[i==4]);
		fflush(stdout);
	}
	inline void fall(int x, int y = 0) {
		pt = y;
		for (; y<7; ++y) if (b[x][y]) b[x][pt++] = b[x][y];
		for (; pt<7; ++pt) b[x][pt] = 0;
	}
	inline bool move(const op& o) {
		if ((!b[o.x][o.y]) || o.x+o.g < 0 || o.x+o.g >= 5 || b[o.x][o.y]==b[o.x+o.g][o.y] || (b[o.x+o.g][o.y] && o.g == -1)) return false;
		swap(b[o.x+o.g][o.y], b[o.x][o.y]);
		fall(o.x+o.g);
		if (!b[o.x][o.y]) fall(o.x, o.y);
		return true;
	}
	bool clean() {
		bool res = 0;
//		print();
		for (int i = 0; i < 5; ++i)
			for (int j = 0; b[i][j]; ++j) {
				if (i >= 2 && b[i][j] == b[i-1][j] && b[i][j] == b[i-2][j]) {
					tmp[i][j] = tmp[i-1][j] = tmp[i-2][j] = 1;
					res = 1;
				}
				if (j >= 2 && b[i][j] == b[i][j-1] && b[i][j] == b[i][j-2]) {
					tmp[i][j] = tmp[i][j-1] = tmp[i][j-2] = 1;
					res = 1;
				}
			}
		if (!res) return false;
		for (int i = 0; i < 5; ++i)
			for (int j = 0; b[i][j]; ++j)
				if (tmp[i][j]) {
					b[i][j] = tmp[i][j] = 0;
					tmp[i][7] = 1;
				}
		for (int i = 0; i < 5; ++i) if (tmp[i][7]){
			fall(i);
			tmp[i][7] = 0;
		}
		return true;
	}
}s, t;

bool dfs(int m, const state &x) {
//	printf("%d\n", m);
//	x.print();
//	if ((++tot) > 1e5) return false;
//	printf("%d\n", tot);
	if (m == n) return memcmp(&x, &t, sizeof(state)) == 0;
	state y = x;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; x.b[i][j]; ++j) {
			for (int k = 1; k >= -1; k -= 2) {
				op z = (op){i,j,k};
				if (y.move(z)) {
					while(y.clean());
					if (dfs(m+1, y)) {
						ans.push_back(z);
						return true;
					}
					y = x;
				}
			}
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	int m;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; scanf("%d", &m) && m; ++j)
			s.b[i][j] = m;
	if (dfs(0, s))
		for (int i = (int)ans.size()-1; ~i; --i)
			printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].g);
	else puts("-1");
}

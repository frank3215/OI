#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1}, maxn = 1e6+10;

int n, m;
string s[maxn];
vector<vector<int> > v1;
queue<pair<int,int> > q;

void bfs(queue<pair<int,int> > &q, vector<vector<int> > &v) {
	while (!q.empty()) {
		pair<int,int> p = q.front(); q.pop();
		int x = p.first, y = p.second, cur = (0 <= x && x < n && 0 <= y && y < m?v[x][y]:0);
//		printf("%d %d\n", x, y);
		for (int k = 0; k < 8; ++k) {
			int nx = x+dx[k], ny = y+dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && v[nx][ny] == -1) {
				q.push(make_pair(nx, ny));
				v[nx][ny] = cur+1;
			}
		}
	}
}

bool check(int t, bool out=0) {
	vector<vector<int> >  v2(n+2,vector<int>(m+2,-1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
//			printf("%d %d %c %d\n", i, j, s[i][j], v1[i][j]);
			if (v1[i][j] > t) {
				q.push(make_pair(i,j));
				v2[i][j] = 0;
			}
			if (out) putchar(".X"[v1[i][j]>t]);
		}
		if (out) puts("");
	}
	if (q.empty()) return false;
	bfs(q, v2);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
//			printf("%d %d %c %d\n", i, j, s[i][j], v2[i][j]);
			if ((v2[i][j] <= t && s[i][j] != 'X') || (v2[i][j] > t && s[i][j] != '.')) return false;
		}
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	v1 = vector<vector<int> > (n+2,vector<int>(m+2,-1));
	for (int i = -1; i <= n; ++i) {
		for (int j = -1; j <= m; ++j) {
			if (i == -1 || i == n || j == -1 || j == m) q.push(make_pair(i,j));
			else if (s[i][j] == '.') {
				q.push(make_pair(i,j));
				v1[i][j] = 0;
			}
		}
	}
	bfs(q, v1);
	int l = 0, r = min(n, m);
	while (l < r) {
		int mid = l+r+1>>1;
		if (check(mid)) l = mid;
		else r = mid-1;
	}
	printf("%d\n", l);
	check(l, 1);
}

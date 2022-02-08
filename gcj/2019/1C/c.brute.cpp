#include <bits/stdc++.h>

using namespace std;

const int MX = 7;
const int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};
typedef char state[MX][MX];

int r, c;
state board;
vector<int> f[5][5];

int qpow(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; ++i) res *= x;
	return res;
}

int Hash(const state &s) {
	int res = 0;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			res *= 3;
			if (s[i][j] == '#') res += 1;
			if (s[i][j] == 'B') res += 2;
		}
	}
	return res;
}


void print(char cur[MX][MX]) {
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j)
			printf("%c", cur[i][j]);
		putchar('\n');
	}
	puts("");
}

bool ok(state &newboard, int i, int j, int k) {
//	printf("TEST %d %d %d\n", i, j, k);
//	print(newboard);
	for (int dir = k; dir < 4; dir += 2) {
		int x = i, y = j;
//		printf("START %d\n", dir);
		while (1) {
			x += dx[dir];
			y += dy[dir];
//			printf("AT %d %d\n", x, y);
			if (board[x][y] == '.') newboard[x][y] = 'B';
			else if (board[x][y] == 'B' || board[x][y] == '\0') {
				break;
			}
			else {
				return 0;
			}
//			print(newboard);
		}
	}
	return 1;
}

int dfs(int cur) {
	state newboard;
	int res = 0, hs = Hash(board);
	if (f[r][c][hs] != -1) return f[r][c][hs]; 
//	printf("%d:\n", cur, res);
//	print(board);
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (board[i][j] == '.') {
				for (int k = 0; k < 2; ++k) {
					memcpy(newboard, board, sizeof(board));
					newboard[i][j] = 'B';
//					print(newboard);
					if (ok(newboard, i, j, k)) {
//						printf("ok: %d %d %d\n", i, j, k);
//						print(newboard);
						swap(newboard, board);
						if (!dfs(cur+1)) {
							res++;
						}
						swap(board, newboard);
					}
				}
			}
		}
	}
	f[r][c][hs] = res;
//	printf("%d %d\n", cur, res);
	return res;
}

void solve() {
	cin >> r >> c;
	memset(board, 0, sizeof(board));
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			cin >> board[i][j];
		}
	}
//	print(board);
	int ans = dfs(0);
	cout << ans << endl;
}

int main() {
	for (int i = 1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j) {
			int pw = qpow(3, i*j);
			for (int k = 1; k <= pw; ++k) f[i][j].push_back(-1);
		}

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}

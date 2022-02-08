#include <bits/stdc++.h>
using namespace std;

const int M = 20;

int n, a[10][10], cnt[2][10];

bool dfs(int u, int v) {
	if (u == n && v == n) return true;
	if (u < n && (v == n || rand()%2)) {
		for (int _ = 0; _ < M; ++_) {
			int i = rand()%n, j = rand()%(n-1);
			if (a[i][j] == 0 && a[i][j+1] == 0 && cnt[0][i] < 3 && cnt[1][j] < 3 && cnt[1][j+1] < 3) {
				a[i][j] = a[i][j+1] = u+v+1;
				cnt[0][i]++, cnt[1][j]++, cnt[1][j+1]++;
				if (dfs(u+1, v)) return true;
				a[i][j] = a[i][j+1] = 0;
				cnt[0][i]--, cnt[1][j]--, cnt[1][j+1]--;
			}
		}
	}
	else {
		for (int _ = 0; _ < M; ++_) {
			int j = rand()%n, i = rand()%(n-1);
			if (a[i][j] == 0 && a[i+1][j] == 0 && cnt[0][i] < 3 && cnt[1][j] < 3 && cnt[0][i+1] < 3) {
				a[i][j] = a[i+1][j] = u+v+1;
				cnt[0][i]++, cnt[1][j]++, cnt[0][i+1]++;
				if (dfs(u, v+1)) return true;
				a[i][j] = a[i+1][j] = 0;
				cnt[0][i]--, cnt[1][j]--, cnt[0][i+1]--;
			}
		}
	}
	return false;
}

int main() {
	for (n = 3; n <= 7; ++n) {
		memset(cnt, 0, sizeof(cnt));
		memset(a, 0, sizeof(a));
		dfs(0, 0);
		printf("{\n");
		for (int i = 0; i < n; ++i) {
			printf("\t{\"");
			for (int j = 0; j < n; ++j) {
				printf("%c", a[i][j]?a[i][j]-1+'a':'.');
			}
			printf("\"},\n");
		}
		printf("},\n");
	}
}

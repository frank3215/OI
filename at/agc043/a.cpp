#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int h, w;
int f[N][N][2], a[N][N];
char c[N][N];

int main() {
	cin >> h >> w;
	for (int i = 1; i <= h; ++i)
		for (int j = 1; j <= w; ++j) {
			cin >> c[i][j];
			a[i][j] = c[i][j] == '#';
		}
	memset(f, 0x3f, sizeof(f));
	f[1][0][0] = 0;
	for (int i = 1; i <= h; ++i)
		for (int j = 1; j <= w; ++j) {
			if (a[i][j]) {
				f[i][j][1] = min(min(f[i-1][j][1], f[i][j-1][1]), min(f[i-1][j][0], f[i][j-1][0])+1);
			} else {
				f[i][j][0] = min(min(f[i-1][j][1], f[i][j-1][1]), min(f[i-1][j][0], f[i][j-1][0]));
			}
		}
	cout << min(f[h][w][0], f[h][w][1]+1) << endl;
}	

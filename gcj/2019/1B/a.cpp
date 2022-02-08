#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

const int maxp = 500+10;

int x[maxp], y[maxp];
char d[maxp];
int ax[maxp*3], ay[maxp*3];

std::vector<int> vx, vy;

bool cmp1(int i, int j) {
	return x[i] < x[j];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		vx.clear();
		vy.clear();
		vx.push_back(0);
		vy.push_back(0);
		memset(ax, 0, sizeof(ax));
		memset(ay, 0, sizeof(ay));
		int p, q;
		scanf("%d%d", &p, &q);
		for (int j = 0; j < p; ++j) {
			scanf("%d %d %c", x+j, y+j, d+j);
			for (int delta = -1; delta <= 1; ++delta) {
				if (x[j]+delta >= 0) vx.push_back(x[j]+delta);
				if (y[j]+delta >= 0) vy.push_back(y[j]+delta);
			}
		}
		std::sort(vx.begin(), vx.end());
		vx.erase(std::unique(vx.begin(), vx.end()), vx.end());
		std::sort(vy.begin(), vy.end());
		vy.erase(std::unique(vy.begin(), vy.end()), vy.end());

//		for (int j = 0; j < vx.size(); ++j) printf("%d ", vx[j]); puts("");
//		for (int j = 0; j < vy.size(); ++j) printf("%d ", vy[j]); puts("");

		for (int j = 0; j < p; ++j) {
			int nx = std::lower_bound(vx.begin(), vx.end(), x[j]) - vx.begin(),
				ny = std::lower_bound(vy.begin(), vy.end(), y[j]) - vy.begin();
//			printf(" %d %d %d %c\n", j, nx, ny, d[j]);
			if (d[j] == 'N') ay[ny+1]++, ay[vy.size()]--;
			if (d[j] == 'E') ax[nx+1]++, ax[vx.size()]--;
			if (d[j] == 'W') ax[0]++, ax[nx]--;
			if (d[j] == 'S') ay[0]++, ay[ny]--;
//			for (int k = 0; k <= vx.size(); ++k) printf(" %d", ax[k]); puts("");
//			for (int k = 0; k <= vy.size(); ++k) printf(" %d", ay[k]); puts("");
		}
		int cur = 0, mx = 0, my = 0, ansx = 0, ansy = 0;
		for (int j = 0; j <= vx.size(); ++j) {
			cur += ax[j];
//			printf("x=%d: %d\n", j, cur);
			if (cur > mx) {
				mx = cur;
				ansx = j;
			}
		}
		for (int j = 0; j <= vy.size(); ++j) {
			cur += ay[j];
//			printf("y=%d: %d\n", j, cur);
			if (cur > my) {
				my = cur;
				ansy = j;
			}
		}
//		printf("%d %d\n", ansx, ansy);
		printf("Case %d: %d %d\n", i, vx[ansx], vy[ansy]);
	}
}

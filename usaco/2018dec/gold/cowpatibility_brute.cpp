#include <cstdio>
#include <algorithm>
const int maxn = 50000;
int n, ice[maxn][5], ans;
bool cowpatible(int x,int y) {
	for (int i=0; i<5; ++i) {
		for (int j=0; j<5; ++j) if (ice[x][i] == ice[y][j]) return true;
	}
	return false;
}
int main() {
	freopen("cowpatibility.in","r",stdin);
	freopen("cowpatibility.ans","w",stdout);
	scanf("%d",&n);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<5; ++j) {
			scanf("%d",&ice[i][j]);
		}
		std::sort(ice[i], ice[i]+5);
		for (int k=0; k<i; ++k) {
			if (!cowpatible(i,k)) ++ans;
		}
	}
	printf("%d\n",ans);
}

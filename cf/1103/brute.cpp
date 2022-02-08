#include <cstdio>
#include <algorithm>
using namespace std;

const int p[] = {2, 3, 5, 7, 11, 13, 17, 23, 29, 31, 37, 41, 0};
int cnt[100];

void dfs(int i, long long j) {
	cnt[i]++;
	for (int _ = 1; (j*=p[i]) <= 1e12; ++_) dfs(i+1, j);
}

int main() {
	dfs(0, 1);
	for (int i = 0; p[i]; ++i)
		printf("%d\n", cnt[i]);
}

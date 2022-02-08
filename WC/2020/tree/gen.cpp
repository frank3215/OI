#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define mp make_pair
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

signed main() {
	srand(time(NULL));
	FILE *f = fopen("seed", "r"); int seed; fscanf(f, "%d", &seed); srand(seed); seed += time(NULL)+rand(); fclose(f);
	f = fopen("seed", "w"); fprintf(f, "%d", seed); fflush(f); fclose(f);
#ifndef STDIO
	freopen("tree.inn", "w", stdout);
#endif
	int n = 1000;
	printf("%d\n", n);
	FOR(i,1,n) {
		printf("%d %d\n", i, i+1);
	}
	printf("%d\n", n);
	FOR(i,0,n) {
		printf("1 %d\n", i+1);
	}
}

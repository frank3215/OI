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
	freopen("courses.in", "w", stdout);
#endif
	int m = 3, t = 0;
	int w[3][5], c[3][5], n[3], s[3], tot = 0, ttot = 0;
	FOR(i,0,m) {
		n[i] = 5;
		int sum = 0;
		FOR(j,0,n[i]) {
			w[i][j] = rand()%3+1, c[i][j] = rand()%10+1;
			sum += w[i][j];
		}
		tot += sum;
		s[i] = rand()%(sum+1);
		ttot += s[i];
	}
	t = rand()%(tot-ttot+1)+ttot;
	printf("%d %d\n", m, t);
	FOR(i,0,m) {
		printf("%d %d\n", n[i], s[i]);
		FOR(j,0,n[i]) {
			printf("%d %d\n", w[i][j], c[i][j]);
		}
	}
	puts("0");
}

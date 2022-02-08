#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
using namespace std;

signed main() {
	FILE *f = fopen("seed", "r"); long long seed; fscanf(f, "%lld", &seed); srand(seed+time(NULL)); fclose(f);
	f = fopen("seed", "w"); fprintf(f, "%lld", (long long)rand()*RAND_MAX+rand()); fclose(f);
#ifndef ONLINE_JUDGE
	freopen("b.in", "w", stdout);
#endif
	int t = 1, n = 100, k = rand()%n+1, l = rand()%n+1;
	printf("%d\n%d %d %d\n", t, n, k, l);
	FOR(i,0,n) printf("%d ", rand()%n);
}
